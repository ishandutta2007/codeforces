#include <stdio.h>
#define MOD 998244353

long long int power(long long int a, long long int b)
{
	long long int ans = 1;
	long long int k = a;
	while(b)
	{
		if(b%2==1) ans *= k, ans %= MOD;
		b/=2;
		k*=k, k%=MOD;
	}
	return ans;
}

long long int inv(long long int k)
{
	return power(k,MOD-2);
}

long long int fact[400010];
long long int comb(int a, int b)
{
	long long int ans = fact[a];
	ans *= inv(fact[b]), ans %= MOD;
	ans *= inv(fact[a-b]), ans %= MOD;
	return ans;
}

int x[200010],y[200010];
int main()
{
	fact[0] = 1;
	for(int i=1;i<=400000;i++) fact[i] = (i*fact[i-1])%MOD;
	
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	for(int i=1;i<=a;i++) y[x[i]] = i;
	
	int count = 0;
	for(int i=1;i<a;i++)
	{
		if(x[i+1]==a-1);
		else if(x[i]==a-1) count++;
		else if(y[x[i]+1]<y[x[i+1]+1]) count++;
	}
	
	count = a - 1 - count;
	
	if(b-count<=0) printf("0");
	else printf("%lld",comb(a+b-count-1,a));
}