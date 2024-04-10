#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN=1005,MAXV=1000005;

struct Point
{
	int x,y;

	Point(){}
	Point(int x,int y):x(x),y(y){}

	Point operator - (const Point &b) const
	{
		return Point(x-b.x,y-b.y);
	}

	LL operator * (const Point &b) const
	{
		return (LL)x*b.y-(LL)y*b.x;
	}
};

struct segment
{
	Point a,b;

	void read()
	{
		scanf("%d%d%d%d",&a.x,&a.y,&b.x,&b.y);
	}
}s[MAXN];

int vx[MAXV*2],vy[MAXV*2];

#define vx(i) vx[i+MAXV]
#define vy(i) vy[i+MAXV]

LL dcmp(const LL &x)
{
	if (x==0)
		return 0;
	return x<0?-1:1;
}

LL xmul(const Point &a,const Point &b,const Point &c)
{
	return (b-a)*(c-a);
}

bool is_seg_intersect(const Point &a,const Point &b,const Point &c,const Point &d)
{
	if (max(c.x,d.x)<min(a.x,b.x)||max(c.y,d.y)<min(a.y,b.y))
		return false;
	if (max(a.x,b.x)<min(c.x,d.x)||max(a.y,b.y)<min(c.y,d.y))
		return false;
	if (dcmp((b-a)*(c-a))*dcmp((b-a)*(d-a))>0)
		return false;
	if (dcmp((d-c)*(a-c))*dcmp((d-c)*(b-c))>0)
		return false;
	return true;
}

Point get_intersect(const Point &a,const Point &b,const Point &c,const Point &d)
{
	LL u=xmul(a,b,c),v=xmul(b,a,d);
	if (((LL)c.x*v+(LL)d.x*u)%(u+v)||((LL)c.y*v+(LL)d.y*u)%(u+v))
		return Point(INT_MAX,0);
	return Point(((LL)c.x*v+(LL)d.x*u)/(u+v),((LL)c.y*v+(LL)d.y*u)/(u+v));
}

Point get_ins(const segment &s1,const segment &s2)
{
	if (!is_seg_intersect(s1.a,s1.b,s2.a,s2.b))
		return Point(INT_MAX,0);
	return get_intersect(s1.a,s1.b,s2.a,s2.b);
}

int main()
{
	//freopen("read.txt","r",stdin);
	int n;
	scanf("%d",&n);
	int ans=0;
	for (int i=1;i<=n;i++)
	{
		s[i].read();
		ans+=1+abs(__gcd(s[i].a.x-s[i].b.x,s[i].a.y-s[i].b.y));
		for (int j=1;j<i;j++)
		{
			Point p=get_ins(s[j],s[i]);
			if (p.x!=INT_MAX&&(vx(p.x)!=i||vy(p.y)!=i))
			{
				vx(p.x)=vy(p.y)=i;
				ans--;
			}
		}
	}
	printf("%d",ans);
	return 0;
}