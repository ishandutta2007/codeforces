#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
const int N=1e5+9,mod=1e9+7;
ll f1[N],dp[N][2],n,x;
vector<int> g[N];
int dfs(int x){
	ll p1=0,a[2],k;
	dp[x][1]=1;
	if(!g[x].size()) return 0;
	f(i,0,g[x].size()){
		dfs(g[x][i]);
		p1=(dp[x][0]*(dp[g[x][i]][0]+1)+dp[x][1]*dp[g[x][i]][1])%mod;
		dp[x][1]=(dp[x][1]*(dp[g[x][i]][0]+1)+dp[x][0]*dp[g[x][i]][1])%mod;
		dp[x][0]=p1%mod;
	}
	dp[x][0]=(dp[x][0]*2)%mod,dp[x][1]=(dp[x][1]*2)%mod;
	p1=1;
	f(i,0,g[x].size())
		p1*=(dp[g[x][i]][0]+1),p1%=mod;
	dp[x][1]=(dp[x][1]+mod-p1)%mod;
	a[0]=1,a[1]=0;
	f(i,0,g[x].size()){
		k=a[0];
		a[0]=(a[0]+a[1]*dp[g[x][i]][1])%mod;
		a[1]=(a[1]+k*dp[g[x][i]][1])%mod;
	}
	dp[x][0]=(dp[x][0]+mod-a[1])%mod;
	return 0;
}
int main(){
	cin>>n;
	f(i,1,n){
		cin>>x;g[x].pb(i+1);}
	dfs(1);
	cout<<(dp[1][0]+dp[1][1])%mod;
}