#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxn = 200005;
vector<vector<int>>adj(mxn);
vector<int>dp(mxn);
vector<bool>vis(mxn);
vector<int>dis(mxn);
set<int>s;
void dfs(int u, int p, int d){
	dis[u] = d;
	for(int nxt: adj[u]){
		if(nxt==p)continue;
		dfs(nxt,u,d+1);
		if(vis[nxt])vis[u] = true;
	}
}
void reset(int n){
	for(int i = 1; i<=n; i++){
		vis[i] = false; dp[i] = 0; dis[i] = 0; adj[i].clear();
	}
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		int x,y;
		cin >> x >> y;
		vis[x] = true;
		vis[y] = true;
		s.insert(x);
		s.insert(y);
		for(int i = 0; i<k; i++){
			int v;
			cin >> v;
			s.insert(v);
			vis[v] = true;
		}
		for(int i = 0; i<n-1; i++){
			int a,b;
			cin >> a >> b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		dfs(x,0,0);
		int nodes = 0;
		for(int i = 1; i<=n; i++){
			if(vis[i])nodes++;
		}
		int len = 2*(nodes-1)-dis[y];
		cout << len << "\n";
		reset(n);
	}
	return 0;
}