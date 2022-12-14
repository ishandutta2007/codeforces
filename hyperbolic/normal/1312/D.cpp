#include <stdio.h>
#define MOD 998244353
int a;
long long int power(int s, int t)
{
	long long int ans = 1;
	long long int k = s;
	while(t)
	{
		if(t%2==1) ans *=k, ans%=MOD;
		k*=k, k%=MOD, t/=2;
	}
	return ans;
}
long long int inv(int k)
{
	return power(k,MOD-2);
}

long long int check[200010];
long long int comb(int k)
{
	if(k==a-3) return 1;
	if(check[k]) return check[k];
	long long int s = comb(k-1); // k-1Ca-3 = (k-1)! / (k-a+2)! (a-3)!
	// want : k! / (k-a+3)! (a-3)!
	s *= k, s%= MOD;
	s *= inv(k-a+3), s%=MOD;
	return check[k] = s;
}

int main()
{
	int b;
	scanf("%d%d",&a,&b);
	if(a==2)
	{
		printf("0");
		return 0;
	}
	long long int ans = 0;
	for(int i=a-1;i<=b;i++)
	{
		long long int s = (i-1)*comb(i-2);
		s%=MOD, s*=power(2,a-3), s%=MOD;
		ans += s, ans%=MOD;
	}
	printf("%lld",ans);
}