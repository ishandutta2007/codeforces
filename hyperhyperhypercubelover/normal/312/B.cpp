#include<cstdio>

int main()
{
	double win=0;
	double prob=1;
	double a,b,c,d;
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	a/=b;c/=d;
	while(prob>0.000000001)
	{
		win+=prob*a;
		prob*=1-a;
		prob*=1-c;
	}
	printf("%.10lf",win);
}