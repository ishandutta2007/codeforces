#include<cstdio>
#include<cmath>

int main()
{
	double x;
	double w,h,a;
	scanf("%lf%lf%lf",&w,&h,&a);
	if(a<0.5||a>179.5)printf("%.8lf",w*h);
	else
	{
		a*=acos(-1)/180;
		if(h>w)
		{
			x=h;
			h=w;
			w=x;
		}
        if(sin(a)>sin(atan(h/w)*2))printf("%.8lf",h*h/sin(a));
        else
		{
			if(a>acos(-1)/2)a=acos(-1)-a;
			printf("%.8lf",w*h-(h/2-w/2*tan(a/2))*(h/2-w/2*tan(a/2))*tan(a)-(w/2-h/2*tan(a/2))*(w/2-h/2*tan(a/2))*tan(a));
		}
	}
}