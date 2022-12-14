#include <stdio.h>
#define MOD 998244353

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans*=k, ans%=MOD;
		k*=k, k%=MOD;
		b/=2;
	}
	return ans;
}

long long int sum[500010],sum2[500010],ans[500010];
int count[500010];
int x[500010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=0;i<=a+2;i++) ans[i] = sum2[i] = sum[i] = count[i] = 0;
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		
		for(int i=a;i>=1;i--)
		{
			ans[i] = sum[x[i]] + sum[x[i]+1];
			ans[i] %= MOD;
			ans[i] += (sum2[x[i]+2]+1), ans[i] %= MOD;
			if(x[i]>=2) sum2[x[i]] += power(2,count[x[i]]+count[x[i]-2]);
			else sum2[x[i]] += power(2,count[x[i]]);
			sum2[x[i]] %= MOD;
			sum[x[i]] += ans[i], sum[x[i]] %= MOD;
			count[x[i]]++;
		}
		
		long long int S = 0;
		for(int i=1;i<=a;i++) if(x[i]==0) S += ans[i], S %= MOD;
		S += (power(2,count[1])-1), S %= MOD;
		printf("%lld\n",S);
	}
}