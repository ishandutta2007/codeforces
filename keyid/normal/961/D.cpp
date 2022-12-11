#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN=100005;

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

	LL operator * (const Point &b) const
	{
		return (LL)x*b.y-(LL)y*b.x;
	}
}p[MAXN],pt[MAXN];

int n;

bool check(int p1,int p2)
{
	int cnt=0;
	Point d=p[p1]-p[p2];
	for (int i=0;i<n;i++)
		if ((p[i]-p[p1])*d!=0)
			pt[cnt++]=p[i];
	if (cnt<3)
		return true;
	d=pt[0]-pt[1];
	for (int i=2;i<cnt;i++)
		if ((pt[i]-pt[0])*d!=0)
			return false;
	return true;
}

int main()
{
	//freopen("read.txt","r",stdin);
	scanf("%d",&n);
	if (n<5)
	{
		printf("YES");
		return 0;
	}
	for (int i=0;i<n;i++)
		p[i].read();
	printf(check(0,1)||check(0,2)||check(1,2)?"YES":"NO");
	return 0;
}