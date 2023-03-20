// example code for creating a tag that can use the Hair API

#include "c4d.h"
#include "c4d_symbols.h"
#include "lib_hair.h"
#include "main.h"

#include "povspline.h"

//////////////////////////////////////////////////////////////////////////

class POVSplineTag : public TagData
{
	INSTANCEOF(POVSplineTag, TagData)

public:
	virtual Bool Init(GeListNode* node);
	virtual void Free(GeListNode* node) {};

	static NodeData* Alloc() { return NewObjClear(POVSplineTag); }

	//////////////////////////////////////////////////////////////////////////

	Int32 m_SplineType; // 1:linear_spline | 2:quadratic_spline | 3:cubic_spline |	4:bezier_spline
	Float m_SweepFrom;
	Float m_SweepTo;
};

//////////////////////////////////////////////////////////////////////////

Bool POVSplineTag::Init(GeListNode* node)
{
	BaseContainer* bc = ((BaseList2D*)node)->GetDataInstance();

	bc->SetInt32(POV_SPLINE_SPLINE_TYPE, 1);
	bc->SetInt32(POV_SPLINE_EXPORT_AS, 1);

	return true;
}

//////////////////////////////////////////////////////////////////////////

#define ID_POV_SPLINE 1018985

Bool RegisterPOVSplineTag()
{
	return RegisterTagPlugin(ID_POV_SPLINE, GeLoadString(IDS_POV_SPLINE),
		                       TAG_MULTIPLE | TAG_VISIBLE, POVSplineTag::Alloc,
		                       "POVSpline", AutoBitmap("pvengine-xp.ico"), 0);
}