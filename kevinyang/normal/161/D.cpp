#include <bits/stdc++.h>
using namespace std;
int n,k;
int mxn = 200005;
vector<vector<int>>adj(mxn);
vector<bool>vis(mxn);
vector<int>sz(mxn);
vector<int>cntdis(mxn);
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
void dfsreset(int u, int p, int d){
	cntdis[d] = 0;
	for(int nxt: adj[u]){
		if(nxt==p)continue;
		if(vis[nxt])continue;
		dfsreset(nxt,u,d+1);
	}
}
void dfsdis(int u, int p, int d){
	cntdis[d]++;
	for(int nxt: adj[u]){
		if(nxt==p)continue;
		if(vis[nxt])continue;
		dfsdis(nxt,u,d+1);
	}
}
void dfsdis2(int u, int p, int d){
	cntdis[d]--;
	for(int nxt: adj[u]){
		if(nxt==p)continue;
		if(vis[nxt])continue;
		dfsdis2(nxt,u,d+1);
	}
}
int dfsdiscnt(int u, int p, int d){
	int ret = 0;
	if(d<=k)ret+=cntdis[k-d];
	for(int nxt: adj[u]){
		if(nxt==p)continue;
		if(vis[nxt])continue;
		ret+=dfsdiscnt(nxt,u,d+1);
	}
	return ret;
}
long long centroid(int root, int nodes){
	if(nodes==1)return 0;
	dfs(root,root,nodes);
	int temp = cent;
	dfsdis(temp,temp,0);
	long long ans = cntdis[k];
	vis[temp] = true;
	for(int nxt: adj[temp]){
		if(vis[nxt])continue;
		dfsdis2(nxt,temp,1);
		ans+=dfsdiscnt(nxt,temp,1);
		dfsdis(nxt,temp,1);
	}
	dfs(temp,temp,nodes);
	dfsreset(temp,temp,0);
	for(int nxt: adj[temp]){
		if(vis[nxt])continue;
		ans+=centroid(nxt,sz[nxt]);
	}
	//cout << temp << " " << ans << "\n";
	return ans;
}

signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	cin >> n >> k;
	for(int i = 0; i<n-1; i++){
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y); adj[y].push_back(x);
	}
	cout << centroid(1,n)/2 << "\n";
	return 0;
}