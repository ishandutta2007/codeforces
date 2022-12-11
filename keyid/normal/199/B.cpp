#include <bits/stdc++.h>
using namespace std;

struct Point
{
	int x,y;

	Point(){}
	Point(int x,int y):x(x),y(y){}

	Point operator - (const Point &b) const
	{
		return Point(x-b.x,y-b.y);
	}

	int len2() const
	{
		return x*x+y*y;
	}
};

struct Ring
{
	Point o;
	int r,R;

	void read()
	{
		scanf("%d%d%d%d",&o.x,&o.y,&r,&R);
	}
}a[2];

int sqr(int x)
{
	return x*x;
}

bool is_intersect(const Point &o1,int r1,const Point &o2,int r2)
{
	if (sqr(r1-r2)>=(o1-o2).len2())
		return false;
	return sqr(r1+r2)>(o1-o2).len2();
}

bool check(const Point &o,int r,const Ring &b)
{
	if (is_intersect(o,r,b.o,b.r)||is_intersect(o,r,b.o,b.R))
		return false;
	if ((r>=b.r||(o-b.o).len2()>sqr(r-b.r))&&b.R>=r&&(o-b.o).len2()<=sqr(b.R-r))
		return false;
	return true;
}

int main()
{
	//freopen("read.txt","r",stdin);
	for (int i=0;i<2;i++)
		a[i].read();
	int ans=0;
	for (int i=0;i<2;i++)
	{
		if (check(a[i].o,a[i].r,a[i^1]))
			ans++;
		if (check(a[i].o,a[i].R,a[i^1]))
			ans++;
	}
	printf("%d",ans);
	return 0;
}