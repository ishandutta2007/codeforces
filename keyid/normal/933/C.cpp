#include <bits/stdc++.h>
using namespace std;

const int MAXN=3;
const double EPS=1e-6;

int dcmp(const double &x)
{
	if (abs(x)<EPS)
		return 0;
	return x<0?-1:1;
}

struct Point
{
	double x,y;

	Point(){}
	Point(double x,double y): x(x),y(y){}

	Point operator - (const Point &b) const
	{
		return Point(x-b.x,y-b.y);
	}

	Point operator + (const Point &b) const
	{
		return Point(x+b.x,y+b.y);
	}

	Point operator * (const double &b) const
	{
		return Point(x*b,y*b);
	}

	Point rot90() const
	{
		return Point(-y,x);
	}

	bool operator < (const Point &b) const
	{
		int d=dcmp(x-b.x);
		if (d!=0)
			return d<0;
		return dcmp(y-b.y)<0;
	}

	bool operator == (const Point &b) const
	{
		return dcmp(x-b.x)==0&&dcmp(y-b.y)==0;
	}

	double lensqr() const
	{
		return x*x+y*y;
	}

	void read()
	{
		scanf("%lf%lf",&x,&y);
	}
}insec[4],insec2[MAXN*MAXN];

struct Round
{
	Point o;
	double r;

	void read()
	{
		o.read();
		scanf("%lf",&r);
	}
}r[MAXN];

bool is_insec[MAXN];
int cnt;

bool getCC(const Point &c1,const double &r1,const Point &c2,const double &r2)
{
	double x=(c1-c2).lensqr();
	if (dcmp(x)==0)
		return false;
	double y=((r1*r1-r2*r2)/x+1)/2;
	double d=r1*r1/x-y*y;
	if (d<-EPS) return false;
	if (d<0) d=0;
	Point q1=c1+(c2-c1)*y,q2=((c2-c1)*sqrt(d)).rot90();
	insec[cnt++]=q1-q2;
	insec[cnt++]=q1+q2;
	return true;
}

int main()
{
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
		r[i].read();
	int v=0,e=0,c=0;
	for (int i=0;i<n;i++)
	{
		cnt=0;
		for (int j=0;j<n;j++)
			if (j!=i)
				if (getCC(r[j].o,r[j].r,r[i].o,r[i].r))
					is_insec[i]=is_insec[j]=true;
		sort(insec,insec+cnt);
		cnt=unique(insec,insec+cnt)-insec;
		e+=cnt;
		for (int j=0;j<cnt;j++)
			insec2[v++]=insec[j];
	}
	sort(insec2,insec2+v);
	v=unique(insec2,insec2+v)-insec2;
	for (int i=0;i<n;i++)
		if (!is_insec[i])
			c++;
	for (int i=0;i<n;i++)
		if (is_insec[i])
		{
			c++;
			break;
		}
	printf("%d",c+1+e-v);
	return 0;
}