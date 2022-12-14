#include <stdio.h>
#include <vector>
#define MOD 998244353

long long int gcd(long long int a, long long int b)
{
	return a?gcd(b%a,a):b;
}

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int s = a;
	long long int t = b;
	while(t)
	{
		if(t%2==1) ans*=s, ans%=MOD;
		s*=s, s%=MOD;
		t/=2;
	}
	return ans;
}
long long int inv(long long int k)
{
	return power(k,MOD-2);
}

long long int fact[110];
long long int invFact[110];
std::vector<long long int> prime;
int check[110];

std::vector<int> V;
long long int func(long long int k)
{
	V.clear();
	for(int i=0;i<prime.size();i++)
	{
		if(k%prime[i]!=0) continue;
		
		int count = 0;
		while(k%prime[i]==0) count++,k/=prime[i];
		V.push_back(count);
	}
	
	int sum = 0;
	for(int i=0;i<V.size();i++) sum+=V[i];
	long long int ans = fact[sum];
	for(int i=0;i<V.size();i++) ans *= invFact[V[i]], ans%=MOD;
	return ans;
}

std::vector<long long int> P;
int main()
{
	fact[0] = 1;
	for(int i=1;i<=100;i++) fact[i] = fact[i-1]*i, fact[i]%=MOD;
	for(int i=0;i<=100;i++) invFact[i] = inv(fact[i]);
	
	long long int a;
	int b;
	scanf("%lld%d",&a,&b);
	
	long long int a2 = a;
	for(long long int i=2;i*i<=a;i++)
	{
		if(a2%i==0)
		{
			prime.push_back(i);
			while(a2%i==0) a2/=i;
		}
	}
	if(a2>1) prime.push_back(a2);
	
	for(int i=1;i<=b;i++)
	{
		long long int c,d;
		scanf("%lld%lld",&c,&d);
		long long int e = gcd(c,d);
		long long int s1 = func(c/e);
		long long int s2 = func(d/e);
		printf("%lld\n",(s1*s2)%MOD);
	}
}