#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
const int mxn = 100005;
vector<int>adj[mxn];
vector<int>adj2[mxn];
int psa[mxn], parent[mxn], lvl[mxn];
bool vis[mxn];
void dfs(int u, int p){
	vis[u] = true;
	parent[u] = p; lvl[u] = lvl[p]+1; 
	for(int nxt: adj[u]){
		if(nxt==p)continue;
		if(vis[nxt]){
			if(lvl[u]>lvl[nxt]){
				psa[u]++; psa[nxt]--;
			}
			continue;
		}
		adj2[u].push_back(nxt);
		adj2[nxt].push_back(u);
		dfs(nxt,u);
	}
}
bool f = false;
void dfs1(int u, int p){
	for(int nxt: adj2[u]){
		if(nxt==p)continue;
		dfs1(nxt,u);
		psa[u]+=psa[nxt];
	}
	if(psa[u]==0&&u!=1){
		f = true;
	}
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
	cin >> n >> m;
	DisjointSet ds;
	ds.init(n);
	vector<pair<int,int>>edges(m);
	for(int i = 0; i<m; i++){
		int x,y;
		cin >> x >> y;
		ds.Union(x,y);
		adj[x].push_back(y);
		adj[y].push_back(x);
		edges[i] = {x,y};
	}
	if(ds.sz[ds.find(1)]!=n){
		cout << "0\n";
		return 0;
	}
	dfs(1,0);
	dfs1(1,0);
	if(f){
		cout << "0\n";
		return 0;
	}
	for(pair<int,int>nxt: edges){
		int x = nxt.first; int y = nxt.second;
		if(parent[x]==y){
			cout << x << " " << y << "\n";
		}
		else if(parent[y]==x){
			cout << y << " " << x << "\n";
		}
		else if(lvl[x]<lvl[y]){
			cout << x << " " << y << "\n";
		}
		else{
			cout << y << " " << x << "\n";
		}
	}
	return 0;
}