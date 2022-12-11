#include <bits/stdc++.h>
using namespace std;

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

	int len2() const
	{
		return x*x+y*y;
	}

	double len() const
	{
		return sqrt(len2());
	}
};

int main()
{
	//freopen("read.txt","r",stdin);
	Point p[2];
	int r[2];
	for (int i=0;i<2;i++)
	{
		p[i].read();
		scanf("%d",&r[i]);
	}
	if ((p[0]-p[1]).len2()>=(r[0]+r[1])*(r[0]+r[1]))
		printf("%.8f",((p[0]-p[1]).len()-r[0]-r[1])/2);
	else
	{
		if (r[0]>r[1])
		{
			swap(r[0],r[1]);
			swap(p[0],p[1]);
		}
		if ((p[0]-p[1]).len2()>=(r[1]-r[0])*(r[1]-r[0]))
			printf("0");
		else
			printf("%.8f",(r[1]-(p[0]-p[1]).len()-r[0])/2);
	}
	return 0;
}