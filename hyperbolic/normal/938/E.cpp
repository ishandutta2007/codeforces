#include <stdio.h>
#include <map>
#define MOD 1000000007
long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans*=k, ans %= MOD;
		b/=2;
		k*=k, k%=MOD;
	}
	return ans;
}

long long int inv(long long int k)
{
	return power(k,MOD-2);
}

std::map<int,int> M;
long long int fact[1000010];
int main()
{
	fact[0] = 1;
	for(int i=1;i<=1000000;i++) fact[i] = (i*fact[i-1])%MOD;
	
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++)
	{
		int b;
		scanf("%d",&b);
		M[b]++;
	}
	
	std::map<int,int> ::iterator it = M.end();
	it--;
	if(it==M.begin())
	{
		printf("0");
		return 0;
	}
	int T = (it->second);
	it--;
	
	long long int ans = 0;
	for(;;it--)
	{
		int s = (it->first);
		int t = (it->second);
		T += t;
		
		long long int S = fact[a];
		S *= inv(T), S %= MOD;
		S *= s, S %= MOD;
		S *= t, S %= MOD;
		ans += S, ans %= MOD;
		
		if(it==M.begin()) break;
	}
	printf("%lld",ans);
}