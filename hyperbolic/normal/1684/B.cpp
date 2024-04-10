#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		long long int d = ((c/b)+2);
		printf("%lld %lld %lld\n",d*b+a,b,c);
	}
}