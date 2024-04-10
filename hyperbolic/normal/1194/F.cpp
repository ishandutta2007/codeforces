#include <stdio.h>
#define MOD 1000000007

long long int pow(long long int s, long long int t)
{
	long long int ans = 1;
	long long int k = s;
	while(t)
	{
		if(t%2==1) ans*=k,ans%=MOD;
		k*=k,k%=MOD;
		t/=2;
	}
	return ans;
}
long long int inv(long long int k)
{
	return pow(k,MOD-2);
}
long long int fact[200010];
long long int comb(int a, int b)
{
	if(a<b) return 0;
	long long int ans = fact[a];
	ans *= inv(fact[b]), ans%=MOD;
	ans *= inv(fact[a-b]), ans %=MOD;
	return ans;
}

long long int x[200010];
int main()
{
	fact[0] = 1;
	for(int i=1;i<=200000;i++)
	{
		fact[i] = fact[i-1] * i;
		fact[i]%=MOD;
	}
	
	int a;
	long long int b;
	scanf("%d%lld",&a,&b);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	
	long long int ans = 0;
	long long int t = 1;
	long long int p = 0;
	for(int i=1;i<=a;i++)
	{
		b -= x[i];
		if(b<0) break;
		long long int m = b<i?b:i;
		t *=2, t%=MOD;
		t += comb(i-1,p+1), t%=MOD;
		p++;
		for(int j=m+1;j<=p;j++) t += (MOD-comb(i,j)), t%=MOD;
		ans += (t*pow(2,a-i))%MOD, ans%=MOD;
		p = m;
	}
	ans *= inv(pow(2,a)), ans%=MOD;
	printf("%lld",ans);
}