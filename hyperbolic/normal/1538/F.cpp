#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		long long int ans = 0;
		for(int i=1;i<=10;i++)
		{
			ans += (b-a);
			b/=10, a/=10;
		}
		printf("%lld\n",ans);
	}
}