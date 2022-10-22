#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
using namespace std;
const int M=200009;
int n;
int t[M],h[M];
vector<int>g[M];
ll ans=1ll<<50;
ll dp[M][2];
vector<int>w[M];
void dfs(int u,int fa){
	int l=0,r=0;
	ll sum=1ll*t[u]*g[u].size();
	for(auto v:g[u]){
		if(v!=fa){
			dfs(v,u);
			if(h[v]>h[u])r++,sum+=dp[v][1];
			if(h[v]<h[u])l++,sum+=dp[v][0];
			if(h[v]==h[u]){
				r++,sum+=dp[v][1];
				w[u].eb(dp[v][0]-dp[v][1]);
			}
		}
	}
	sort(w[u].begin(),w[u].end());
	if(u==1){
		ans=min(ans,sum-1ll*min(l,r)*t[u]);
	}
	else{
		if(h[fa]>h[u])dp[u][0]=min(dp[u][0],sum-1ll*min(l,r+1)*t[u]);
		if(h[fa]<h[u])dp[u][1]=min(dp[u][1],sum-1ll*min(l+1,r)*t[u]);
		if(h[fa]==h[u]){
			dp[u][0]=min(dp[u][0],sum-1ll*min(l,r+1)*t[u]);
			dp[u][1]=min(dp[u][1],sum-1ll*min(l+1,r)*t[u]);
		}
	}
	for(auto o:w[u]){
		l++;
		r--;
		sum+=o;
		if(u==1){
			ans=min(ans,sum-1ll*min(l,r)*t[u]);
		}
		else{
			if(h[fa]>h[u])dp[u][0]=min(dp[u][0],sum-1ll*min(l,r+1)*t[u]);
			if(h[fa]<h[u])dp[u][1]=min(dp[u][1],sum-1ll*min(l+1,r)*t[u]);
			if(h[fa]==h[u]){
				dp[u][0]=min(dp[u][0],sum-1ll*min(l,r+1)*t[u]);
				dp[u][1]=min(dp[u][1],sum-1ll*min(l+1,r)*t[u]);
			}
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&t[i]);
	for(int i=1;i<=n;++i)scanf("%d",&h[i]),dp[i][0]=dp[i][1]=1ll<<50;
	for(int i=1;i<n;++i){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].eb(v);
		g[v].eb(u);
	}
	dfs(1,0);
	printf("%lld\n",ans);
	return 0;
}
/*
1
2
ab
ba
*/