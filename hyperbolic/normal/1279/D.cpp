#include <stdio.h>
#include <vector>
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

std::vector<int> V[1000010];
int count[1000010];

int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		for(int j=1;j<=b;j++)
		{
			int c;
			scanf("%d",&c);
			V[i].push_back(c);
		}
	}
	
	for(int i=1;i<=a;i++) for(int j=0;j<V[i].size();j++) count[V[i][j]]++;
	
	long long int ans = 0;
	for(int i=1;i<=a;i++)
	{
		long long int A = inv(a);
		long long int B = inv(V[i].size());
		long long int C = (A*B)%MOD;
		for(int j=0;j<V[i].size();j++)
		{
			long long int D = (C*count[V[i][j]])%MOD;
			D *= inv(a), D %= MOD;
			ans += D;
			ans %= MOD;
		}
	}
	printf("%lld",ans);
}