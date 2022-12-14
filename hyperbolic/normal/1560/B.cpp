#include <stdio.h>

long long int abs(long long int k)
{
	return k>0?k:-k;
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		long long int n = abs(a-b);
		if(a<=2*n&&b<=2*n);
		else
		{
			printf("-1\n");
			continue;
		}
		if(c<=n) printf("%lld\n",c+n);
		else if(c<=2*n) printf("%lld\n",c-n);
		else printf("-1\n");
	}
}