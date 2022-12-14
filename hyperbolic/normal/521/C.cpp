#include <stdio.h>
#define MOD 1000000007
int a,b;
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

long long int fact[100010];
long long int comb(int a, int b)
{
	if(a<b) return 0;
	if(b<0) return 0;
	
	long long int s1 = fact[a];
	long long int s2 = (fact[b]*fact[a-b])%MOD;
	return (s1*inv(s2))%MOD;
}

char x[100010];
int y[100010];
int main()
{
	fact[0] = 1;
	for(int i=1;i<=100000;i++) fact[i] = fact[i-1]*i, fact[i]%=MOD;
	
	scanf("%d%d",&a,&b);
	scanf("%s",x+1);
	for(int i=1;i<=a;i++) y[a-i+1] = x[i]-'0';
	
	long long int S = 0;
	long long int ans = 0;
	for(int i=1;i<=a;i++)
	{
		long long int temp = ( S + (comb(a-i,b)*power(10,i-1))%MOD ) %MOD;
		ans += y[i] * temp, ans%=MOD;
		S += comb(a-(i+1),b-1)*power(10,i-1);
		S%=MOD;
		//printf("%d %lld!!\n",i,ans);
	}
	printf("%lld",ans);
}