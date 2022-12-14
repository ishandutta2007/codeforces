#include <stdio.h>
#define MOD 998244353

long long int power(long long int s, long long int t)
{
	long long int ans = 1;
	long long int k = s;
	while(t)
	{
		if(t%2==1) ans*=k, ans%=MOD;
		k*=k, k%=MOD;
		t/=2;
	}
	return ans;
}
long long int inv(long long int k)
{
	return power(k,MOD-2);
}

long long int fact[200010];
long long int comb(int s, int t)
{
	return (fact[s]*inv(fact[t])%MOD)*inv(fact[s-t])%MOD;
}
long long int check[200010];
long long int func(int s, int t)
{
	if(check[s]!=-1) return check[s];
	
	long long int ans = 0;
	for(int i=0;i<s;i++)
	{
		if(i%2==0)
		{
			ans += (comb(s,i) * power(s-i,t))%MOD, ans%=MOD;
		}
		else
		{
			ans -= (comb(s,i) * power(s-i,t))%MOD, ans+=MOD, ans%=MOD;
		}
	}
	return check[s] = ans;
}
int main()
{
	for(int i=0;i<=200000;i++) check[i] = -1;
	
	fact[0] = 1;
	for(int i=1;i<=200000;i++) fact[i] = fact[i-1]*i, fact[i]%=MOD;
	
	int a;
	long long int b;
	scanf("%d%lld",&a,&b);
	int c = 2*a-b;
	if(a+1 <=c && c<=2*a);
	else
	{
		printf("0");
		return 0;
	}
	long long int ans = 0;
	if(c==2*a) ans = func(a,a);
	else ans = 2*func(c-a,a)*comb(a,2*a-c) %MOD;
	
	printf("%lld",ans);
}