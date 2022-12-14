#include <stdio.h>
#define MOD 1000000007

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

long long int fact[100010];
long long int comb(int s, int t)
{
	long long int ans = fact[s];
	ans *= inv(fact[t]), ans %= MOD;
	ans *= inv(fact[s-t]), ans %= MOD;
	return ans;
}

int main()
{
	fact[0] = 1;
	for(int i=1;i<=100000;i++) fact[i] = (i*fact[i-1])%MOD;
	
	int a,b,h;
	scanf("%d%d%d",&a,&b,&h);
	if(a==0)
	{
		if(b>=h+1) printf("1");
		else printf("0");
		return 0;
	}
	if(b==0)
	{
		printf("1");
		return 0;
	}
	
	long long int ans = 0, ans2 = 0;
	for(int i=1;i<=100000;i++) // F : i, W = i+1
	{
		int s = a-i;
		int t = b-(i+1)*(h+1);
		if(s<0 || t<0) break;
		// sHi
		long long int val = comb(s+i-1,s) * comb(t+i+1-1,t);
		val %= MOD, ans += val, ans %= MOD;
	}
	
	for(int i=2;i<=100000;i++) // F : i, W = i-1
	{
		int s = a-i;
		int t = b-(i-1)*(h+1);
		if(s<0 || t<0) break;
		// sHi
		long long int val = comb(s+i-1,s) * comb(t+i-1-1,t);
		val %= MOD, ans += val, ans %= MOD;
	}
	
	for(int i=1;i<=100000;i++) // F : i, W = i
	{
		int s = a-i;
		int t = b-(i)*(h+1);
		if(s<0 || t<0) break;
		// sHi
		long long int val = comb(s+i-1,s) * comb(t+i-1,t);
		val %= MOD, val *= 2, val %= MOD, ans += val, ans %= MOD;
	}
	
	for(int i=1;i<=100000;i++) // F : i, W = i+1
	{
		int s = a-i;
		int t = b-(i+1);
		if(s<0 || t<0) break;
		// sHi
		long long int val = comb(s+i-1,s) * comb(t+i+1-1,t);
		val %= MOD, ans2 += val, ans2 %= MOD;
	}
	
	for(int i=2;i<=100000;i++) // F : i, W = i-1
	{
		int s = a-i;
		int t = b-(i-1);
		if(s<0 || t<0) break;
		// sHi
		long long int val = comb(s+i-1,s) * comb(t+i-1-1,t);
		val %= MOD, ans2 += val, ans2 %= MOD;
	}
	
	for(int i=1;i<=100000;i++) // F : i, W = i
	{
		int s = a-i;
		int t = b-(i);
		if(s<0 || t<0) break;
		// sHi
		long long int val = comb(s+i-1,s) * comb(t+i-1,t);
		val %= MOD, val *= 2, val %= MOD, ans2 += val, ans2 %= MOD;
	}
	
	ans *= inv(ans2), ans %= MOD;
	printf("%lld",ans);
}