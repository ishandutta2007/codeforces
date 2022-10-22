#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define eb emplace_back
using namespace std;
const int M=3e5+9;
int n,m;
bool flag=0;
int f[M],siz[M];	
vector<pii>g[M];
bool vis[M];
ll len[M];
ll ans,ma;
void dfs(int u,int fa){
	f[u]=fa;
	siz[u]=1;
	for(auto o:g[u]){
		int v=o.fi;
		if(v!=fa){
			len[v]=len[u]+o.se;
			dfs(v,u);
			siz[u]+=siz[v];
		}
	}
}
void solve(int u,int fa){
	if(!vis[u]){
		ans=max(ans,ma-len[f[u]]+len[u]-len[f[u]]);
		if(f[f[u]]){
			ans=max(ans,len[u]-len[f[u]]-(len[f[u]]-len[f[f[u]]]));
		}
		ma=max(ma,len[u]);
	}
	else{
		ll w1=0,w2=0;
		for(auto o:g[u]){
			int v=o.fi,w=o.se;
			if(v!=fa){
				if(vis[v])w1=w;
				else w2=w;
			}
		}
		if(w1&&w2)ans=max(ans,w2-w1);
		if(f[f[u]])ans=max(ans,len[f[f[u]]]-len[u]);
	}
	for(auto o:g[u]){
		int v=o.fi;
		if(v!=fa&&!vis[v]){
			solve(v,u);
		}
	}
	for(auto o:g[u]){
		int v=o.fi;
		if(v!=fa&&vis[v]){
			solve(v,u);
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<n;++i){
		int u,v,w;
		cin>>u>>v>>w;
		g[u].eb(v,w);
		g[v].eb(u,w);
	}
	dfs(1,0);
	for(int u=n,la=0;u;u=f[u]){
		if(siz[u]-1-siz[la]>1)flag=1;
		la=u;
		vis[u]=1;
	}
	ans=-(1ll<<60),ma=-(1ll<<60);
	if(f[n]==1&&n==2)ans=0;
	solve(1,0);
	for(int i=1;i<=m;++i){
		int x;
		cin>>x;
		cout<<min(len[n],len[n]+ans+x)<<"\n";
	}
	return 0;
}