#include <bits/stdc++.h>
using namespace std;
#define int long long
struct edge{
	int w,x,y;
};
bool cmp(edge a, edge b){
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
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int>>arr(n+1,vector<int>(n+1));
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			cin >> arr[i][j];
		}
	}
	vector<edge>edges;
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			if(i==j)continue;
			edges.push_back({arr[i][j],i,j});
		}
	}
	bool f = true;
	sort(edges.begin(),edges.end(),cmp);
	DisjointSet ds;
	ds.init(n);
	vector<vector<pair<int,int>>>adj(n+1);
	for(edge nxt: edges){
		if(ds.find(nxt.x)==ds.find(nxt.y))continue;
		ds.Union(nxt.x,nxt.y);
		adj[nxt.x].push_back({nxt.w,nxt.y});
		adj[nxt.y].push_back({nxt.w,nxt.x});
		if(nxt.w<=0)f = false;
	}
	vector<vector<int>>dis(n+1,vector<int>(n+1));
	vector<vector<bool>>vis(n+1,vector<bool>(n+1));
	for(int i = 1; i<=n; i++){
		queue<int>q;
		q.push(i);
		vis[i][i] = true;
		while(!q.empty()){
			int cur = q.front(); q.pop();
			for(pair<int,int>nxt: adj[cur]){
				if(!vis[i][nxt.second]){
					vis[i][nxt.second] = true;
					dis[i][nxt.second] = dis[i][cur] + nxt.first;
					q.push(nxt.second);
				}
			}
		}
	}
	
	for(int i = 1; i<=n; i++){
		for(int j = 1; j<=n; j++){
			if(arr[i][j]==dis[i][j])continue;
			f = false;
		}
	}
	if(f)cout << "YES\n";
	else cout << "NO\n";
	return 0;
}