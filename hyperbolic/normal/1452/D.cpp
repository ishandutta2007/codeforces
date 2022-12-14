#include <stdio.h>
#define MOD 998244353
long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans*=k, ans%=MOD;
		b/=2;
		k*=k, k%=MOD;
	}
	return ans;
}
long long int inv(long long int k)
{
	return power(k,MOD-2);
}

int main()
{
	int a;
	scanf("%d",&a);
	long long int s1 = 1;
	long long int s2 = 0;
	for(int i=2;i<=a;i++)
	{
		long long int temp = s1;
		s1 += s2;
		s1 %= MOD;
		s2 = temp;
	}
	long long int d = inv(2);
	for(int i=1;i<=a;i++) s1*=d, s1%=MOD;
	printf("%lld",s1);
}