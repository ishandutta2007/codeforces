#include <stdio.h>
#define ERR 0.0000001

double d;
double func(double a, double b, double c, int k)
{
	if(k>20) return 0;
	
	double ans = 1;
	if(a<ERR&&b<ERR);
	else if(a<ERR)
	{
		if(b<=d) ans += b*func(0,0,c+b,k+1);
		else ans += b*func(0,b-d,c+d,k+1);
	}
	else if(b<ERR)
	{
		if(a<=d) ans += a*func(0,0,c+a,k+1);
		else ans += a*func(a-d,0,c+d,k+1);
	}
	else
	{
		if(b<=d) ans += b*func(a+(b/2),0,c+(b/2),k+1);
		else ans += b*func(a+(d/2),b-d,c+(d/2),k+1);
		
		if(a<=d) ans += a*func(0,b+(a/2),c+(a/2),k+1);
		else ans += a*func(a-d,b+(d/2),c+(d/2),k+1);
	}
	
	return ans;
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		double a,b,c;
		scanf("%lf%lf%lf%lf",&a,&b,&c,&d);
		printf("%.12lf\n",func(a,b,c,1));
	}
}