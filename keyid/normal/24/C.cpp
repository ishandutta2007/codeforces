#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

const int MAXN=100005;

struct Point
{
	int x,y;

	Point(){}
	Point(int x,int y):x(x),y(y){}

	Point operator * (const int &b) const
	{
		return Point(x*b,y*b);
	}

	Point operator - (const Point &b) const
	{
		return Point(x-b.x,y-b.y);
	}

	void read()
	{
		scanf("%d%d",&x,&y);
	}
}p[MAXN];

int main()
{
	//freopen("read.txt","r",stdin);
	int n;
	LL m;
	scanf("%d%lld",&n,&m);
	m%=2*n;
	Point now;
	now.read();
	for (int i=0;i<n;i++)
		p[i].read();
	for (int i=0;i<m;i++)
		now=p[i%n]*2-now;
	printf("%d %d",now.x,now.y);
	return 0;
}