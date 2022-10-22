#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;
const int M=2e5+9;
int n,m;
int a[M],f[M];
ll dp[M],pre[M],suf[M];
vector<int>e[M],d[M];
void dfs(int u,int fa,int deep){
	d[deep].pb(u);f[u]=fa;m=max(m,deep);
	for(auto v:e[u])if(v!=fa)dfs(v,u,deep+1);
}
void work(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)e[i].clear(),d[i].clear(),dp[i]=0;
	for(int i=2;i<=n;++i){
		int x;scanf("%d",&x);
		e[x].pb(i);
		e[i].pb(x);
	}
	for(int i=2;i<=n;++i)scanf("%d",&a[i]);
	dfs(1,0,0);
	for(int i=m;i>=1;--i){
		sort(d[i].begin(),d[i].end(),[&](int l,int r){return a[l]<a[r];});
		for(int j=0,r=d[i].size()-1;j<=r;++j){
			int v=d[i][j];
			pre[j]=dp[v]-a[v];
			if(j!=0)pre[j]=max(pre[j],pre[j-1]);
		}
		for(int j=d[i].size()-1;j>=0;--j){
			int v=d[i][j];
			suf[j]=dp[v]+a[v];
			if(j!=d[i].size()-1)suf[j]=max(suf[j],suf[j+1]);
		}
		for(int j=0,r=d[i].size()-1;j<=r;++j){
			int v=d[i][j],u=f[v];
			dp[u]=max(dp[u],dp[v]+a[v]-a[d[i][0]]);
			dp[u]=max(dp[u],dp[v]-a[v]+a[d[i][r]]);
			if(j!=0)dp[u]=max(dp[u],pre[j-1]+a[v]);
			if(j!=r)dp[u]=max(dp[u],suf[j+1]-a[v]);
		}
	}
	printf("%lld\n",dp[1]);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;
}