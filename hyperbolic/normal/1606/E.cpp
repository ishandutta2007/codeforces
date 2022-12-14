#include <stdio.h>
#define MOD 998244353

long long int check2[510][510];
long long int comb(int s, int t)
{
	if(t==0) return 1;
	if(s==t) return 1;
	if(check2[s][t]) return check2[s][t];
	return check2[s][t] = (comb(s-1,t-1)+comb(s-1,t))%MOD;
}

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

long long int check[510][510];
long long int func(int s, int t)
{
	if(s==1) return 0;
	if(s==0) return 1;
	if(t<=(s-1)) return power(t,s);
	if(check[s][t]!=-1) return check[s][t];
	
	long long int s2 = 0;
	for(int i=0;i<=s;i++)
	{
		//printf("%d??\n",i);
		long long int k = comb(s,i);
		k *= power(s-1,i), k %= MOD;
		k *= func(s-i,t-(s-1)), k %= MOD;
		s2 += k, s2 %= MOD;
	}
	
	return check[s][t] = s2;
}

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	
	for(int i=0;i<=a;i++) for(int j=0;j<=b;j++) check[i][j] = -1;
	printf("%lld",func(a,b));
}