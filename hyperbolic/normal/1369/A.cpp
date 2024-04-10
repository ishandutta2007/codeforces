#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a;
		scanf("%lld",&a);
		if((90*a)%(360)==0) printf("YES\n");
		else printf("NO\n");
	}
}