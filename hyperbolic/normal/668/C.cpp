#include <stdio.h>
#include <math.h>
//min + max = p+q
double max[100010],min[100010];
double p[100010];
double func(double a, double b, double c)
{
	if(b*b-4*a*c<=0) return (-b)/(2*a);
	return (-b+sqrt(b*b-4*a*c))/(2*a);
}
int main()
{
	int a;
	double M=0,sum=0;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%lf",&max[i]);
	for(int i=1;i<=a;i++) scanf("%lf",&min[i]);
	for(int i=a;i>=1;i--)
	{
		// min[i] = (M+max[i]+min[i]) * p[i] - p[i]^2 - 2p[i] * sum
		// p[i]^2 + (2*sum-M-max[i]-min[i]) * p[i] + min[i] = 0
		p[i] = func(1,2*sum-M-max[i]-min[i],min[i]-(min[i]+max[i])*sum);
		M+=(max[i]+min[i]);
		sum+=p[i];
	}
	for(int i=1;i<=a;i++) printf("%.12lf ",p[i]);
	printf("\n");
	for(int i=1;i<=a;i++) printf("%.12lf ",max[i]+min[i]-p[i]);
}