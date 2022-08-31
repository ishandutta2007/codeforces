#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int maxsm = 9e6+100;
const ll mod = 1e9+7;
ll dp[maxsm];
const int maxn = 1e6+5;
ll fact[maxn];
ll powr(ll a, ll b)
{
	ll x = 1%mod;
	a %= mod;
	while(b)
	{
		if(b&1)
			x = (x*a)%mod;
		a = (a*a)%mod;
		b >>= 1;
	}
	return x;
}
ll inv(ll a)
{
	return powr(a,mod-2);
}

void pre()
{
	fact[0] =1;
	for(int i = 1;i<maxn;i++)
	{
		fact[i] = (fact[i-1]*i)%mod;
	}
}
void dfsans(int a, int b, int curr, int len,int n, ll& ans)
{
	if(curr > max(a,b)*n)
		return;
	if(len >= 1)
		ans  = (ans+dp[curr])%mod;
	dfsans(a,b,curr*10+a,len+1,n,ans);
	dfsans(a,b,curr*10+b,len+1,n,ans);
}
int main()
{
	pre();
	int a,b,n;
	cin>>a>>b>>n;
	ll fct = fact[n];
	for(int i = 0;i<=n;i++)
	{
		dp[a*i+b*(n-i)] =(dp[a*i+b*(n-i)] + fct*inv((fact[i]*fact[n-i])%mod))%mod;
	}
	ll ans = 0;
	dfsans(a,b,0,0,n,ans);
	cout<<ans;
}