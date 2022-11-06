#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int mxn = 200005;
vector<vector<int>>adj(mxn);
vector<int>dis(mxn);
vector<int>sz(mxn);
vector<int>children(mxn);
vector<int>parent(mxn);
void dfs(int u, int p, int d){
	dis[u] = d;
	sz[u] = 1;
	parent[u] = p;
	for(int nxt: adj[u]){
		if(nxt==p)continue;
		dfs(nxt,u,d+1);
		children[u]++;
		sz[u]+=sz[nxt];
	}
}
set<pair<int,int>>s;
vector<int>val(mxn);

signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> k;
	for(int i = 1; i<n; i++){
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1,0,0);
	for(int i = 1; i<=n; i++){
		val[i] = dis[i];
	}
	for(int i = 1; i<=n; i++){
		if(sz[i]==1){
			s.insert({dis[i],i});
		}
	}
	int ans = 0;
	while(k--){
		pair<int,int>p = *--s.end();
		ans+=p.first;
		s.erase(p);
		int u = p.second;
		int v = parent[p.second];
		val[v]-=sz[u];
		children[v]--;
		if(children[v]==0){
			s.insert({val[v],v});
		}
	}
	cout << ans << "\n";
	return 0;
}