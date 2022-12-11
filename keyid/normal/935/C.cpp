#include <bits/stdc++.h>
using namespace std;

struct Point
{
	double x,y;

	Point(){}
	Point(double x,double y):x(x),y(y){}

	void read()
	{
		scanf("%lf%lf",&x,&y);
	}

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

	double len() const
	{
		return sqrt(x*x+y*y);
	}
};

int main()
{
	//freopen("read.txt","r",stdin);
	double r;
	Point c,p;
	scanf("%lf",&r);
	c.read();
	p.read();
	if ((c-p).len()==0)
		printf("%.8f %.8f %.8f",c.x+r/2,c.y,r/2);
	else if ((c-p).len()<=r)
	{
		Point p2=c+(c-p)*(r/(c-p).len());
		p2=(p+p2)*0.5;
		printf("%.8f %.8f %.8f",p2.x,p2.y,(p2-p).len());
	}
	else
		printf("%f %f %f",c.x,c.y,r);
	return 0;
}