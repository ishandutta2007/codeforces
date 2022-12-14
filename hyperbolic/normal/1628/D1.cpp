#include <stdio.h>
#define MOD 1000000007

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

int a,b;
long long int c;
long long int check[2010][2010];
long long int func(int s, int t)
{
	if(t==0) return 0;
	if(t==s) return (c*s)%MOD;
	if(check[s][t]!=-1) return check[s][t];
	
	long long int val = inv(2);
	val *= (func(s-1,t-1)+func(s-1,t));
	return check[s][t] = (val%MOD);
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%lld",&a,&b,&c);
		for(int i=0;i<=a;i++) for(int j=0;j<=b;j++) check[i][j] = -1;
		printf("%lld\n",func(a,b));
	}
}