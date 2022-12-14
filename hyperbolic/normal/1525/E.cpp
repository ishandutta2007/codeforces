#include <stdio.h>
#include <vector>
#include <algorithm>
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

long long int inv(long long int k)
{
	return power(k,MOD-2);
}

std::vector<int> V[50010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=b;j++)
		{
			int c;
			scanf("%d",&c);
			V[j].push_back(c);
		}
	}
	
	for(int j=1;j<=b;j++) std::sort(V[j].begin(),V[j].end());
	
	long long int S = 1;
	for(int i=1;i<=a;i++) S*=i, S%=MOD;
	
	long long int ans = 0;
	for(int j=1;j<=b;j++)
	{
		long long int s = 1;
		for(int i=1;i<=a;i++) s *= (V[j][i-1]-i), s %= MOD;
		ans += (S-s+MOD), ans %= MOD;
	}
	ans *= inv(S), ans %= MOD;
	
	printf("%lld",ans);
}