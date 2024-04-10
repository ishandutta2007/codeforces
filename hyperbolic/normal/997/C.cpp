#include <stdio.h>
#define MOD 998244353

long long int pow(long long int s, long long int t) // s^t
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

long long int inv(long long int k) // k^-1 = k^MOD-2
{
	return pow(k,MOD-2);
}

long long int comb[1000010];
int main()
{
	long long int a;
	scanf("%lld",&a);
	comb[0] = 1;
	for(int i=0;i<a;i++) comb[i+1] = ((comb[i]*(a-i))%MOD*inv(i+1))%MOD;
	
	long long int ans = 0;
	for(int i=1;i<=a;i++)
	{
		long long int s = ((comb[i]*pow(3,i)%MOD)*pow(3,a*(a-i)))%MOD;
		if(i%2==1) ans += 2*s, ans%=MOD;
		else ans += 2*(MOD-s), ans%=MOD;
	}
	for(int i=1;i<=a;i++)
	{
		long long int s = comb[i]*3;
		s%=MOD;
		s*=(pow(3,a*(a-i))-pow(pow(3,a-i)-1,a)+MOD);
		s%=MOD;
		if(i%2==0) ans+=s,ans%=MOD;
		else ans+=(MOD-s),ans%=MOD;
	}
	printf("%lld",ans);
}