#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair <double,int> pli;

#define mp make_pair
#define fi first
#define sc second

const int MAXN=100005;

struct Point
{
	int x,y;
}p[MAXN];

double d[MAXN];

inline LL sqr(int x)
{
	return (LL)x*x;
}

inline double dis(const Point &a,const Point &b)
{
	return sqrt(sqr(a.x-b.x)+sqr(a.y-b.y));
}

int main()
{
	double ans=0;
	Point a,b,t;
	scanf("%d%d%d%d%d%d",&a.x,&a.y,&b.x,&b.y,&t.x,&t.y);
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d%d",&p[i].x,&p[i].y);
		d[i]=dis(p[i],t);
		ans+=d[i];
	}
	ans*=2;
	pli ma1(DBL_MAX,0),ma2(DBL_MAX,0),mb1(DBL_MAX,0),mb2(DBL_MAX,0);
	for (int i=0;i<n;i++)
	{
		if (ma1>=mp(dis(a,p[i])-d[i],i))
		{
			ma2=ma1;
			ma1=mp(dis(a,p[i])-d[i],i);
		}
		else ma2=min(ma2,mp(dis(a,p[i])-d[i],i));
		if (mb1>=mp(dis(b,p[i])-d[i],i))
		{
			mb2=mb1;
			mb1=mp(dis(b,p[i])-d[i],i);
		}
		else mb2=min(mb2,mp(dis(b,p[i])-d[i],i));
	}
	double mint=DBL_MAX;
	if (ma1.sc!=mb1.sc)
	{
		mint=min(mint,ma1.fi+min(0.0,mb1.fi));
		mint=min(mint,mb1.fi+min(0.0,ma1.fi));
	}
	else
	{
		mint=min(mint,min(0.0,ma1.fi)+mb2.fi);
		mint=min(mint,min(0.0,mb1.fi)+ma2.fi);
		mint=min(mint,min(0.0,ma2.fi)+mb1.fi);
		mint=min(mint,min(0.0,mb2.fi)+ma1.fi);
	}
	printf("%.12f",ans+mint);
	return 0;
}