#include <stdio.h>
#include <math.h>

int main()
{
	int a,b,c,d,e,f;
	double ans = 12345678;
	scanf("%d%d",&a,&b);
	scanf("%d",&c);
	for(int i=1;i<=c;i++)
	{
		scanf("%d%d%d",&d,&e,&f);
		ans = ans<sqrt((d-a)*(d-a)+(e-b)*(e-b))/f?ans:sqrt((d-a)*(d-a)+(e-b)*(e-b))/f;
	}
	printf("%lf",ans);
}