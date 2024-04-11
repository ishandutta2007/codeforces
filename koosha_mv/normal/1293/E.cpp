#include <bits/stdc++.h>
#include <iostream>
using namespace std;
#define print(v,r) f(i,0,r) cout<<v[i]<<" "; cout<<endl;
#define Get(x,y) scanf("%I64d%I64d",&x,&y);
#define f_(i,a,b) for(ll i=a;i>=b;i--)
#define Gett(x,y) scanf("%d%d",&x,&y);
#define f(i,a,b) for(ll i=a;i<b;i++)
#define get(x) scanf("%I64d",&x);
#define gett(x) scanf("%d",&x);																																														
#define ops(x) cout<<x<<" !"<<endl;
#define maxm(a,b) a=max(a,b);
#define minm(a,b) a=min(a,b);
#define mp make_pair
#define ll long long
#define pb push_back
#define S second
#define F first

const int N=3009;

int n,x,y,h[N],par[N],check_par[N][N];
ll ans,dp[N][N],sub[N];
vector<int> g[N];

void dfs2(int x,int rt,int fa){
	check_par[par[rt]][x]=rt;
	f(i,0,g[x].size())
		if(g[x][i]!=fa)
			dfs2(g[x][i],rt,x);
}
void dfs(int x,int dist,int fa){
	h[x]=dist,par[x]=fa,sub[x]=1;
	f(i,0,g[x].size()){
		if(g[x][i]!=fa){
			dfs(g[x][i],dist+1,x);
			dfs2(g[x][i],g[x][i],x);
			sub[x]+=sub[g[x][i]];
		}
	}
}
ll calc(int u,int v){
	int e;
	if(dp[u][v]>0 || u==v) return dp[u][v];
	if(h[u]>h[v]) swap(u,v);
	e=check_par[u][v];
	if(e>0)
		dp[u][v]=max(calc(e,v),calc(u,par[v]))+(1ll*(n-sub[e]))*sub[v];
	else
		dp[u][v]=max(calc(par[u],v),calc(par[v],u))+sub[u]*sub[v];
	dp[v][u]=dp[u][v];
	return dp[u][v];
}
int main(){
	cin>>n;
	f(i,1,n){
		Gett(x,y);
		g[x].pb(y);
		g[y].pb(x);
	}
	dfs(1,0,0);
	f(i,1,n)
		f(j,i+1,n+1)
			maxm(ans,calc(i,j));
	cout<<ans;
}