#include <stdio.h>
#define MOD 998244353

long long int check[200010];
int main()
{
	int a;
	scanf("%d",&a);
	
	long long int s = 10;
	long long int sum1 = 0;
	long long int sum2 = 0;
	for(int i=1;i<=a;i++)
	{
		long long int t = s*i;
		check[i] = (t-sum1-sum2+2*MOD)%MOD;
		sum1 += check[i], sum1 %= MOD;
		sum2 += sum1, sum2%=MOD;
		s*=10, s%=MOD;
	}
	for(int i=a;i>=1;i--) printf("%lld ",check[i]);
}