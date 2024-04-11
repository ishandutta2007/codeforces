#include <bits/stdc++.h>
#include<algorithm>
using namespace std;
#define f(i,a,b) for(ll i=a;i<b;i++)
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define ll long long
#define pb push_back
const int N=3e5+99;
ll x,y,mx=-(1e18),ans,dp[N],mark[N],n,w[N];
vector<ll> g[N];
void dfs(ll x,ll par){
	f(i,0,g[x].size()){
		if(g[x][i]!=par){
			dfs(g[x][i],x);
			dp[x]+=max(dp[g[x][i]],(ll)0);
		}
	}
	mx=max(mx,dp[x]);
}
ll dfs2(ll x,ll par){
	ll s=w[x],k;
	f(i,0,g[x].size()){
		if(g[x][i]!=par){
			k=dfs2(g[x][i],x);
			if(k>0)
				s+=k;
		}
	}
	if(s==mx){
		ans++;
		return 0;
	}
	return s;
}
int main(){
	scanf("%I64d",&n);
	f(i,1,n+1){scanf("%I64d",&dp[i]);w[i]=dp[i];}
	f(i,1,n){
		scanf("%I64d%I64d",&x,&y);
		g[x].pb(y),g[y].pb(x);
	}
	dfs(1,0);
	dfs2(1,0);
	cout<<ans*mx<<" "<<ans;
}