#include <stdio.h>
#define MOD 998244353

int a,b;
long long int fact[500010];

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans*=k,ans%=MOD;
		k*=k ,k%=MOD;
		b/=2;
	}
	return ans;
}
long long int inv(long long int k)
{
	return power(k,MOD-2);
}

long long int comb(int s, int t)
{
	if(s<t) return 0;
	if(s<0) return 0;
	
	return (((fact[s]*inv(fact[s-t]))%MOD)*inv(fact[t]))%MOD;
}

int main()
{
	fact[0] = 1;
	for(int i=1;i<=500000;i++) fact[i] = fact[i-1]*i, fact[i]%=MOD;
	
	scanf("%d%d",&a,&b);
	long long int sum = 0;
	for(int i=1;i<=a;i++) sum += comb(a/i -1 , b -1), sum%=MOD;
	printf("%lld",sum);
}