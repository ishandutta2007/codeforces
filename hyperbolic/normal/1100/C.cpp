#include <stdio.h>
#include <math.h>
#define PI 3.1415926535

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	double t = sin(PI/a);
	printf("%.12lf",t*b/(1-t));
}