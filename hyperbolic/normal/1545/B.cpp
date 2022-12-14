#include <stdio.h>
#include <vector>
#define MOD 998244353

long long int fact[200010];
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

long long int comb(int a, int b)
{
	long long int ans = fact[a];
	ans *= inv(fact[b]), ans %= MOD;
	ans *= inv(fact[a-b]), ans %= MOD;
	return ans;
}

char x[100010];
std::vector<int> V;
int main()
{
	fact[0] = 1;
	for(int i=1;i<=200000;i++) fact[i] = (i*fact[i-1])%MOD;
	int T;
	scanf("%d",&T);
	while(T--)
	{
		V.clear();
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		
		int limit = 0;
		int count = 0;
		for(int i=1;i<=a;i++)
		{
			if(x[i]=='0')
			{
				if((i-limit)%2==1) limit++;
				else limit+=2;
				count++;
			}
		}
		int t = a-limit;
		
		printf("%lld\n",comb(count+t/2,count));
	}
}