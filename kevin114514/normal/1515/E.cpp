#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
void die(string S){puts(S.c_str());exit(0);}
ll mod;
ll fact[440];
ll PW(ll x,ll y)
{
	if(!y)
		return 1ll;
	ll ret=1;
	if(y%2)
		ret=x;
	ret=ret*PW(x*x%mod,y/2)%mod;
	return ret;
}
ll REV(ll x)
{
	return PW(x,mod-2);
}
ll CC(ll n,ll k)
{
	return fact[n]*REV(fact[k])%mod*REV(fact[n-k])%mod;
}
ll C[440][440];
ll dp[440][440];
ll f[440];
int main()
{
	ll N;
	cin>>N>>mod;
	fact[0]=1;
	for(int i=1;i<=400;i++)
		fact[i]=fact[i-1]*i%mod;
	for(int i=0;i<=400;i++)
		for(int j=0;j<=i;j++)
			C[i][j]=CC(i,j);
	for(int i=1;i<=N;i++)
		f[i]=PW(2,i-1);
	for(int i=2;i<N;i++)
		dp[i][1]=PW(2,i-2);
	for(int i=1;i<N;i++)
		for(int j=2;j<=i-1;j++)
			for(int k=1;k<i-1;k++)
				dp[i][j]=(dp[i][j]+dp[k][j-1]*f[i-k-1]%mod*C[i-j][k-j+1]%mod)%mod;
	ll ans=f[N];
//	cout<<ans<<endl;
//	for(int i=0;i<=N;i++)
//	{
//		for(int j=0;j<=N;j++)
//			cout<<dp[i][j]<<" ";
//		puts("");
//	}
//	puts("----------");
	for(int i=1;i<N;i++)
		for(int j=0;j<=i-1;j++)
			ans=(ans+dp[i][j]*f[N-i]%mod*C[N-j][i-j]%mod)%mod;
	cout<<ans<<endl;
	return 0;
}