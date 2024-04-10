#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		int t = 0;
		long long int ans = 0;
		for(int i=1;i<=a;i++)
		{
			if(t+c<=b) t+=c;
			else t-=d;
			ans += t;
		}
		printf("%lld\n",ans);
	}
}