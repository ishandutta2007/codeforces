#include <bits/stdc++.h>
using namespace std;

const int MAXN=4;

struct Point
{
	int x,y;

	Point(){}
	Point(int x,int y):x(x),y(y){}

	void read()
	{
		scanf("%d%d",&x,&y);
	}

	Point operator - (const Point &b) const
	{
		return Point(x-b.x,y-b.y);
	}

	Point operator + (const Point &b) const
	{
		return Point(x+b.x,y+b.y);
	}

	int operator * (const Point &b) const
	{
		return x*b.y-y*b.x;
	}

	int operator % (const Point &b) const
	{
		return x*b.x+y*b.y;
	}

	int len2() const
	{
		return x*x+y*y;
	}

	bool operator < (const Point &b) const
	{
		return x!=b.x?x<b.x:y<b.y;
	}
}p[MAXN][4];

bool check2(Point p1,Point p2,Point p3,Point p4)
{
	if ((p1-p3)*(p2-p4)!=0)
		return false;
	if ((p1-p3).len2()!=(p2-p4).len2())
		return false;
	if ((p1-p2)%(p3-p4)!=0)
		return false;
	return (p1-p2).len2()==(p3-p4).len2();
}

set <Point> ps;

bool check(Point p1,Point p2,Point p3,Point p4)
{
	ps.clear();
	ps.insert(p1);
	ps.insert(p2);
	ps.insert(p3);
	ps.insert(p4);
	if (ps.size()<4)
		return false;
	return check2(p1,p2,p3,p4)||check2(p1,p3,p2,p4)||check2(p1,p4,p2,p3);
}

Point rot(Point a,Point b)
{
	a=a-b;
	swap(a.x,a.y);
	a.x=-a.x;
	a=a+b;
	return a;
}

void solve()
{
	for (int i=0;i<4;i++)
	{
		Point h;
		p[i][0].read();
		h.read();
		for (int j=1;j<4;j++)
			p[i][j]=rot(p[i][j-1],h);
	}
	int ans=INT_MAX;
	for (int i=0;i<4;i++)
		for (int j=0;j<4;j++)
			for (int k=0;k<4;k++)
				for (int l=0;l<4;l++)
					if (check(p[0][i],p[1][j],p[2][k],p[3][l]))
						ans=min(ans,i+j+k+l);
	printf("%d\n",ans==INT_MAX?-1:ans);
}

int main()
{
	//freopen("read.txt","r",stdin);
	int T;
	scanf("%d",&T);
	while (T--) solve();
	return 0;
}