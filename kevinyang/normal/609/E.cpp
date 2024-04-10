#include <bits/stdc++.h>
using namespace std;
#define int long long
int mxn = 200005;
vector<vector<pair<int,int>>>adj(mxn);
int ln = 20;
vector<int>lvl(mxn);
vector<vector<int>>dp(mxn,vector<int>(ln));
vector<vector<int>>dp2(mxn,vector<int>(ln));//largest weight in the binary lift 
struct edge{
	int x,y,w;
};
bool comp(edge a, edge b){
	return a.w < b.w;
}
struct DisjointSet{
	vector<int>parent,sz;
	int size;
	void init(int n){
		size = n;
		parent.resize(n+1); sz.resize(n+1);
		for(int i = 1; i<=n; i++){
			parent[i] = i;
			sz[i] = 1;
		}
	}
	int find(int x){
		if(parent[x]==x)return x;
		return find(parent[x]);
	}
	void Union(int x, int y){
		x = find(x); y = find(y);
		if(x==y)return;
		if(sz[x]<sz[y]){
			parent[x] = y;
			sz[y]+=sz[x];
		}
		else{
			parent[y] = x;
			sz[x]+=sz[y];
		}
	}
};
void dfs(int u, int p, int w){
	dp[u][0] = p;
	dp2[u][0] = w;
	lvl[u] = lvl[p]+1;
	for(int i = 1; i<ln; i++){
		dp[u][i] = dp[dp[u][i-1]][i-1];
		dp2[u][i] = max(dp2[u][i-1],dp2[dp[u][i-1]][i-1]);
	}
	for(pair<int,int> nxt: adj[u]){
		if(nxt.second==p)continue;
		dfs(nxt.second,u,nxt.first);
	}
}
int lca(int x, int y){
	if(lvl[x]<lvl[y])swap(x,y);
	int dif = lvl[x]-lvl[y];
	for(int i = 0; i<ln; i++){
		if(dif&(1<<i)){
			x = dp[x][i];
		}
	}
	if(x==y)return x;
	for(int i = ln-1; i>=0; i--){
		if(dp[x][i]!=dp[y][i]){
			x = dp[x][i]; y = dp[y][i];
		}
	}
	return dp[x][0];
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	vector<edge>edges(m);
	vector<edge>old(m);
	for(int i = 0; i<m; i++){
		int x,y,w;
		cin >> x >> y >> w;
		edges[i] = {x,y,w};
		old[i] = edges[i];
	}
	DisjointSet ds;
	ds.init(n);
	int total = 0;
	sort(edges.begin(),edges.end(),comp);
	for(int i = 0; i<m; i++){
		int x = edges[i].x; int y = edges[i].y; int w = edges[i].w;
		if(ds.find(x)==ds.find(y))continue;
		total+=w;
		ds.Union(x,y);
		adj[x].push_back({w,y});
		adj[y].push_back({w,x});
	}
	dfs(1,0,0);
	for(edge nxt: old){
		int x = nxt.x; int y = nxt.y; int w = nxt.w;
		int mx = 0;
		int u = lca(x,y); int dist = lvl[x]-lvl[u];
		for(int j = 0; j<ln; j++){
			if(dist&(1<<j)){
				mx = max(mx,dp2[x][j]);
				x = dp[x][j];
			}
		}
		dist = lvl[y]-lvl[u];
		for(int j = 0; j<ln; j++){
			if(dist&(1<<j)){
				mx = max(mx,dp2[y][j]);
				y = dp[y][j];
			}
		}
		cout << total-mx+w << "\n";
	}
	return 0;
}