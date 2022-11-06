#include <bits/stdc++.h>
using namespace std;
#define int long long
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
struct edge{
	int w,x,y;
};
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	vector<vector<pair<int,int>>>adj(n+1);
	vector<DisjointSet>ds(30);
	vector<edge>edges(m);
	vector<vector<int>>val(30,vector<int>(n+5));
	vector<vector<bool>>good(30,vector<bool>(n+5));
	for(int i = 0; i<m; i++){
		int x,y,w;
		cin >> x >> y >> w;
		adj[x].push_back({w,y});
		adj[y].push_back({w,x});
		edges[i] = {w,x,y};
	}
	for(int i = 0; i<30; i++){
		ds[i].init(n+5);
	}
	for(int i = 0; i<30; i++){
		for(int j = 0; j<m; j++){
			if(edges[j].w&(1<<i)){
				int x = edges[j].x; int y = edges[j].y;
				ds[i].Union(x,y);
			}
		}
	}
	for(int i = 0; i<30; i++){
		for(int j = 1; j<=n; j++){
			val[i][j] = (1<<30)-1;
		}
		for(int j = 0; j<m; j++){
			if(edges[j].w&(1<<i)){
				int x = ds[i].find(edges[j].x);
				val[i][x]&=edges[j].w;
			}
		}
	}
	for(int i = 0; i<30; i++){
		for(int j = 1; j<=n; j++){
			int x = ds[i].find(j);
			if(val[i][x]!=1){
				for(pair<int,int>nxt: adj[j]){
					if((nxt.first&val[i][x])==0){
						good[i][x] = true;
					}
				}
			}
		}
	}
	int q;
	cin >> q;
	while(q--){
		int u,v;
		cin >> u >> v;
		if(true){
			bool f = false;
			for(int i = 0; i<30; i++){
				if(ds[i].find(u)==ds[i].find(v)){
					f = true;
				}
			}
			if(f){
				cout << "0\n";
				continue;
			}
		}
		if(true){
			bool f = false;
			for(int i = 1; i<30; i++){
				int x = ds[i].find(u);
				if(val[i][x]%2==0||good[i][x]){
					f = true;
				}
			}
			for(pair<int,int> nxt: adj[u]){
				if(nxt.first==0){
					f = true;
				}
			}
			if(f){
				cout << "1\n";
				continue;
			}
		}
		cout << "2\n";
	}
	return 0;
}