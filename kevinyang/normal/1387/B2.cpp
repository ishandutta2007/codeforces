#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int>sz(100005);
int cent = 1;
int mxn = 100005;
vector<vector<int>>adj(mxn);
int n;
void dfs(int u, int p){
	sz[u] = 1;
	for(int nxt: adj[u]){
		if(nxt==p)continue;
		dfs(nxt,u);
		sz[u]+=sz[nxt];
	}
	int mx = n-sz[u];
	for(int nxt: adj[u]){
		if(nxt==p)continue;
		mx = max(mx,sz[nxt]);
	}
	if(mx<=n/2){
		cent = u;
	}
}
vector<int>order;
void dfs1(int u, int p){
	order.push_back(u);
	for(int nxt: adj[u]){
		if(nxt==p)continue;
		dfs1(nxt,u);
	}
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n;
	for(int i = 0; i<n-1; i++){
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(1,0);
	dfs1(cent,0);
	queue<int>q;
	vector<int>dis(n+1);
	vector<bool>vis(n+1);
	q.push(cent);
	vis[cent] = true;
	while(q.size()){
		int cur = q.front(); q.pop();
		for(int nxt: adj[cur]){
			if(!vis[nxt]){
				vis[nxt] = true;
				dis[nxt] = dis[cur]+1;
				q.push(nxt);
			}
		}
	}
	int ans = 0;
	for(int i = 1; i<=n; i++){
		ans +=dis[i]*2;
	}
	cout << ans << "\n";
	vector<int>pos(n+1);
	for(int i = 0; i<n; i++){
		int v = order[(i+n/2)%n];
		pos[order[i]] = v;
	}
	for(int i = 1; i<=n; i++){
		cout << pos[i] << " ";
	}
	cout << "\n";
	return 0;
}