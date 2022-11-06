#include <bits/stdc++.h>
using namespace std;
#define int long long
int mxn = 200005;
vector<vector<int>>adj(mxn);
int ln = 20;
int ans = 0;
int n;
vector<vector<int>>dp(mxn,vector<int>(ln));
vector<int>sz(mxn);
vector<int>psa(mxn);
vector<int>lvl(mxn);
void dfs(int u, int p){
	dp[u][0] = p; lvl[u] = lvl[p]+1;
	sz[u] = 1;
	for(int i = 1; i<ln; i++){
		dp[u][i] = dp[dp[u][i-1]][i-1];
	}
	for(int nxt: adj[u]){
		if(nxt==p)continue;
		dfs(nxt,u);
		sz[u]+=sz[nxt];
	}
}
int lca(int x, int y){
	if(lvl[x]<lvl[y]){
		swap(x,y);
	}
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
struct DisjointSet{
	vector<int> parent,sz;
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
void reset(int n){
	ans = 0;
	for(int i = 1; i<=n; i++){
		adj[i].clear();
		lvl[i] = 0;
		for(int j = 0; j<ln; j++){
			dp[i][j] = 0;
		}
		sz[i] = 0;
		psa[i] = 0;
	}
}
void dfs1(int u, int p){
	for(int nxt: adj[u]){
		if(nxt==p)continue;
		dfs1(nxt,u);
		psa[u]+=psa[nxt];
	}
	if(psa[u]==1){
		//cout << u << "\n";
		int bad = sz[u];
		for(int nxt: adj[u]){
			if(nxt==p)continue;
			if(psa[nxt]==1)bad-=sz[nxt];
		}
		ans-=bad*(bad-1)/2;
	}
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		cin >> n;
		pair<int,int>p;
		DisjointSet ds;
		ds.init(n);
		for(int i = 1; i<=n; i++){
			int x,y;
			cin >> x >> y;
			if(ds.find(x)!=ds.find(y)){
				ds.Union(x,y);
				adj[x].push_back(y);
				adj[y].push_back(x);
			}
			else{
				p = {x,y};
			}
		}
		dfs(p.first,0);
		ans = n*(n-1);
		//cout << ans << " ";
		psa[p.second]++;
		
		dfs1(p.first,0);
		cout << ans << "\n";
		reset(n);
	}
	return 0;
}