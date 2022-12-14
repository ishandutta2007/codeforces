#include <stdio.h>

int main()
{
	long long int a,b,c,d,e;
	scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e);
	if(b>=a) printf("%lld",a*c);
	else
	{
		long long int S = b*c;
		a-=b;
		if(e+b*c>=d*b)
		{
			S += (a/b)*(d*b);
			a%=b;
		}
		else
		{
			S += (a/b)*(e+b*c);
			a%=b;
		}
		if(e+a*c>a*d) printf("%lld",S+a*d);
		else printf("%lld",S+e+a*c);
	}
}