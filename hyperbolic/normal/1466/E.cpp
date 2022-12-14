#include <stdio.h>
#define MOD 1000000007
long long int sum[500010],sum2[500010];
long long int x[500010];
int count[110];
long long int power[110];
int main()
{
	power[0] = 1;
	for(int i=1;i<=60;i++) power[i] = (2*power[i-1])%MOD;
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) sum[i] = sum2[i] = 0;
		for(int i=0;i<=60;i++) count[i] = 0;
		
		
		for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
		long long int S = 0;
		for(int i=1;i<=a;i++) S += x[i], S%= MOD;
		 
		for(int i=1;i<=a;i++)
		{
			long long int k = x[i];
			for(int j=0;j<=60;j++)
			{
				if(k%2==1) count[j]++;
				k/=2;
			}
		}
		
		for(int i=1;i<=a;i++)
		{
			long long int k = x[i];
			for(int j=0;j<=60;j++)
			{
				if(k%2==1)
				{
					sum[i] += (power[j]*count[j])%MOD;
					sum[i] %= MOD;
				}
				k/=2;
			}
		}
		
		for(int i=1;i<=a;i++)
		{
			sum2[i] = S + (x[i]%MOD)*a + (MOD-sum[i]);
			sum2[i] %= MOD;
		}
		
		long long int ans = 0;
		for(int i=1;i<=a;i++)
		{
			ans += (sum[i]*sum2[i])%MOD;
			ans %= MOD;
		}
		printf("%lld\n",ans);
	}
}