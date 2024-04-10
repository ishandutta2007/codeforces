#include <stdio.h>
#include <math.h>
#define PI 3.14159265358979
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		printf("%.12lf\n",1/tan(PI/(2*a)));
	}
}