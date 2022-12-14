#include <stdio.h>
#define MOD 998244353

int inv[1000010],x[1000010],check[1000010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int ans = 1;
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=a;i++) inv[i] = -1;
		
		for(int i=a-b+1;i<=a;i++)
		{
			if(x[i]>0)
			{
				printf("0\n");
				goto u;
			}
		}
		for(int i=a-b;i>=2;i--)
		{
			if(x[i]>=0) inv[i+b] = x[i]+b;
		}
		
		for(int i=a;i>=1;i--)
		{
			if(inv[i]==-1) ans*=i, ans %= MOD;
			if(inv[i]==b) ans*=(b+1), ans%=MOD;
		}
		printf("%lld\n",ans);
		u:;
	}
}