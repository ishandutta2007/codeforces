#include <stdio.h>
#define MOD 998244353

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int s = a;
	while(b)
	{
		if(b%2==1) ans*=s, ans%=MOD;
		s*=s, s%=MOD;
		b/=2;
	}
	return ans;
}
long long int inv(long long int k)
{
	return power(k,MOD-2);
}

int main()
{
	long long int a,b,c,d;
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	long long int ans = power(d-c+1,a*b);
	ans %= MOD;
	if((a*b)%2==1)
	{
		printf("%lld",ans);
		return 0;
	}
	
	long long int odd = (d-c+1)/2,even = (d-c+1)/2;
	if(c%2==0 && d%2==0) even++;
	else if(c%2==1 && d%2==1) odd++;
	
	long long int s1 = power(odd+even,a*b);
	long long int s2 = power(odd-even+MOD,a*b);
	long long int s3 = (s1-s2)*inv(2)%MOD;
	printf("%lld",(ans-s3+MOD)%MOD);
}