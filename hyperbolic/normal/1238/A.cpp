#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a,b;
		scanf("%lld%lld",&a,&b);
		if(a==b+1) printf("NO\n");
		else printf("YES\n");
	}
}