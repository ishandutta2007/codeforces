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
		k*=k,k%=MOD;
	}
	return ans;
}

long long int check2[510][510];
long long int comb(int a, int b)
{
	if(b==0) return 1;
	if(a==b) return 1;
	if(check2[a][b]) return check2[a][b];
	return check2[a][b] = (comb(a-1,b-1)+comb(a-1,b))%MOD;
}

int a,b;
long long int check[510][510];
long long int func(int s, int t)
{
	if(s==0) return 1;
	if(t>b) return 0;
	if(check[s][t]!=-1) return check[s][t];
	
	long long int ans = 0;
	for(int i=0;i<=s;i++)
	{
		long long int val = func(s-i,t+1);
		val *= comb(s,i), val %= MOD;
		val *= power(b-t+1,(a-s)*i+i*(i-1)/2), val %= MOD;
		ans += val, ans %= MOD;
	}
	return check[s][t] = ans;
}

int main()
{
	scanf("%d%d",&a,&b);
	for(int i=0;i<=a;i++) for(int j=0;j<=b;j++) check[i][j] = -1;
	a--;
	printf("%lld",func(a,1));
}