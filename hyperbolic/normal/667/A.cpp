#include <stdio.h>
#include <math.h>
#define PI 3.141592
int main()
{
	double a,b,c,d;
	scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
	
	double e = a*a*PI/4;
	double f = c/e - d;
	if(f<=0)
	{
		printf("NO");
		return 0;
	}
	else
	{
		printf("YES\n%lf",b/f);
	}
}