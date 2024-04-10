#include <bits/stdc++.h>
using namespace std;

typedef long double ld;

const ld PI=acos(-1),EPS=1e-6;

struct Point
{
	ld x,y;

	void read()
	{
		scanf("%Lf%Lf",&x,&y);
	}
};

ld sqr(const ld &x)
{
	return x*x;
}

int sgn(const ld &x)
{
	if (abs(x)<EPS)
		return 0;
	return x<0?-1:1;
}

int main()
{
	//freopen("read.txt","r",stdin);
	Point c1,c2;
	ld r1,r2;
	c1.read();
	scanf("%Lf",&r1);
	c2.read();
	scanf("%Lf",&r2);
	ld d=sqrt(sqr(c1.x-c2.x)+sqr(c1.y-c2.y));
	if (sgn(r1+r2-d)<=0)
		printf("0");
	else
		if (sgn(d-abs(r1-r2))<=0)
		{
			ld r=min(r1,r2);
			printf("%.9Lf",r*r*PI);
		}
		else
		{
			ld ret=0;
			for (int t=0;t<2;t++)
			{
				ld p=(r1*r1+d*d-r2*r2)/(2*r1*d);
				ld da=acos(p)*2;
				ret+=r1*r1*(da-sin(da))/2;
				swap(r1,r2);
			}
			printf("%.9Lf",ret);
		}
	return 0;
}