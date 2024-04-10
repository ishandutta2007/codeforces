#include <stdio.h>
#include <map>
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

std::map<int, long long int> M[210];
long long int comb(int s, int t)
{
	if(t==0) return 1;
	if(M[t].find(s)!=M[t].end()) return M[t][s];
	
	long long int ans = comb(s-1,t-1);
	ans *= s, ans %= MOD;
	ans *= inv(t), ans %= MOD;
	return M[t][s] = ans;
}

int a,b;
long long int fact[310];
long long int check[210][210][410];
long long int func(int s, int t, int c)
{
	if(t==0)
	{
		if(s>0) return 0;
		else return 1;
	}
	if(check[s][t][c]!=-1) return check[s][t][c];
	
	long long int sum = 0;
	sum += func(s,t-1,c);
	
	long long int S = 1;
	for(int i=1;t*i<=s&&(t+1)*i<=(a-c);i++)
	{
		S *= comb((a-c)-(i-1)*(t+1),t+1), S%= MOD;
		S *= fact[t], S %= MOD;
		long long int T = inv(fact[i]);
		T *= S, T %= MOD;
		sum += T*func(s-i*t,t-1,c+(t+1)*i);
		sum %= MOD;
	}
	
	return check[s][t][c] = sum;
}

long long int ans[210];
int main()
{
	fact[0] = 1;
	for(int i=1;i<=300;i++) fact[i] = (i*fact[i-1])%MOD;
	scanf("%d%d",&a,&b);
	
	for(int i=0;i<=b;i++) for(int j=0;j<=b;j++) for(int k=0;k<=2*b;k++) check[i][j][k] = -1;
	
	for(int i=1;i<=b;i++) ans[i] = func(i,i,0);
	ans[0] = 1;
	for(int i=2;i<=b;i++) ans[i] += ans[i-2], ans[i] %= MOD;
	for(int i=1;i<=b;i++) printf("%lld ",ans[i]);
}