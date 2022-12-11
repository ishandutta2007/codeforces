#include <bits/stdc++.h>
using namespace std;

const int MAXN=1005;

struct Point
{
	int x,y;

	Point operator - (const Point &b)
	{
		return (Point){x-b.x,y-b.y};
	}
}a[MAXN];

int n;

inline int getdir(const Point &p1,const Point &p2)
{
	if (p1.x==p2.x) return p1.y<p2.y?-1:1;
	return p1.x<p2.x?-2:2;
}

inline int cross(const Point &a,const Point &b)
{
	return a.x*b.y-a.y*b.x;
}

inline bool check(Point p)
{
	int wn=0;
	for (int i=1;i<n;i++)
	{
		int k=cross(a[i]-a[i-1],p-a[i]),d1=a[i].y-p.y,d2=a[i-1].y-p.y;
		if (k<0&&d1>=0&&d2<0) wn++;
		if (k>0&&d2>=0&&d1<0) wn--;
	}
	return wn!=0;
}

int main()
{
	scanf("%d",&n);
	for (int i=0;i<n;i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].x*=2;
		a[i].y*=2;
	}
	Point p;
	int ans=0;
	for (int i=1;i<n;i++)
	{
		int d=getdir(a[i-1],a[i]);
		p=a[i];
		if (d==-1) p.y++;
		else if (d==1) p.y--;
		else if (d==-2) p.x++;
		else p.x--;
		if (check(p)) ans++;
	}
	printf("%d",ans);
	return 0;
}