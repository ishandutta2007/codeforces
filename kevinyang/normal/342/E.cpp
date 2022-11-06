#include <bits/stdc++.h>
using namespace std;
#define int long long
int mxn = 100005;
vector<vector<int>>adj(mxn);
int ln = 20;
int n,m;
vector<vector<int>>dp(mxn,vector<int>(ln));
vector<int>lvl(mxn);
vector<int>dis(mxn,(int)1e9);
vector<bool>vis(mxn);
void dfs(int u, int p){
	dp[u][0] = p;
	lvl[u] = lvl[p]+1;
	for(int i = 1; i<ln; i++){
		dp[u][i] = dp[dp[u][i-1]][i-1];
	}
	for(int nxt: adj[u]){
		if(nxt==p)continue;
		dfs(nxt,u);
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
int dist(int x, int y){
	int u = lca(x,y);
	return lvl[x]+lvl[y]-2*lvl[u];
}
int sq = 350;
vector<int>all;
vector<int>nodes;
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 0; i<n-1; i++){
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1,0);
	nodes.push_back(1);
	while(m--){
		int cm;
		cin >> cm;
		if(cm==1){
			int x;
			cin >> x;
			nodes.push_back(x);
			if(nodes.size()==sq){
				for(int nxt: nodes){
					all.push_back(nxt);
				}
				nodes.clear();
				for(int i = 1; i<=n; i++){
					dis[i] = 0; vis[i] = false;
				}
				queue<int>q;
				for(int nxt: all){
					vis[nxt] = true;
					q.push(nxt);
				}
				while(q.size()){
					int cur = q.front(); q.pop();
					for(int nxt: adj[cur]){
						if(vis[nxt])continue;
						dis[nxt] = dis[cur]+1;
						vis[nxt] = true;
						q.push(nxt);
					}
				}
			}
		}
		else{
			int x;
			cin >> x;
			int v = dis[x];
			for(int nxt: nodes){
				v = min(v,dist(nxt,x));
			}
			cout << v << "\n";
		}
	}
	return 0;
}