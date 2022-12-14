#include <stdio.h>
#include <algorithm>
#define MOD 998244353

int x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		std::sort(x+1,x+a+1);
		if(x[a-1]+2<=x[a])
		{
			printf("0\n");
		}
		else if(x[a-1]==x[a])
		{
			long long int ans = 1;
			for(int i=1;i<=a;i++) ans*=i, ans %= MOD;
			printf("%lld\n",ans);
		}
		else
		{
			long long int ans = 1;
			int count = 0;
			for(int i=1;i<=a;i++) if(x[i]==x[a-1]) count++;
			
			for(int i=1;i<=count;i++) ans*=i, ans %= MOD;
			ans *= count, ans %= MOD;
			for(int i=count+2;i<=a;i++) ans*=i, ans %=MOD;
			printf("%lld\n",ans);
		}
		
	}
}