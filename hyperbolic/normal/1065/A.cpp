#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a,b,c,d;
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		long long int e = a/d;
		long long int f = (e/b)*c;
		printf("%lld\n",e+f);
	}
}