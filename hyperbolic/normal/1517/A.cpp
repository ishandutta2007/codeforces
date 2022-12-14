#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a;
		scanf("%lld",&a);
		if(a%2050!=0)
		{
			printf("-1\n");
			continue;
		}
		a/=2050;
		
		int ans = 0;
		while(a)
		{
			ans += a%10;
			a/=10;
		}
		printf("%d\n",ans);
	}
}