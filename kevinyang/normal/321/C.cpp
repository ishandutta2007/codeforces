#include <bits/stdc++.h>
using namespace std;
#define int long long
int mxn = 100005;
vector<vector<int>>adj(mxn);
vector<bool>vis(mxn);
vector<int>sz(mxn);
vector<int>ans(mxn);
int cent = 0;
void dfs(int u, int p, int nodes){
	sz[u] = 1;
	bool f = true;
	for(int nxt: adj[u]){
		if(nxt==p)continue;
		if(vis[nxt])continue;
		dfs(nxt,u,nodes);
		sz[u]+=sz[nxt];
		if(sz[nxt]>nodes/2)f = false;
	}
	if(nodes-sz[u]>nodes/2)f = false;
	if(f)cent = u;
}
void dfs1(int u, int p){
	sz[u] = 0;
	for(int nxt: adj[u]){
		if(nxt==p)continue;
		if(vis[nxt])continue;
		dfs1(nxt,u);
	}
}
void dfs2(int u, int p){
	sz[u] = 1;
	for(int nxt: adj[u]){
		if(nxt==p)continue;
		if(vis[nxt])continue;
		dfs2(nxt,u);
		sz[u]+=sz[nxt];
	}
}
void centroid(int root, int depth, int nodes){
	if(nodes==1){
		vis[root] = true;
		ans[root] = depth;
		return;
	}
	dfs1(root,root);
	dfs(root,root,nodes);
	ans[cent] = depth;
	vis[cent] = true;
	dfs1(root,root);
	dfs2(cent,cent);
	for(int nxt: adj[cent]){
		if(vis[nxt])continue;
		centroid(nxt,depth+1,sz[nxt]);
	}
}

signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i<n-1; i++){
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	centroid(1,0,n);
	for(int i = 1; i<=n; i++){
		cout << (char)(ans[i]+'A') << " ";
	}
	cout << "\n";
	return 0;
}