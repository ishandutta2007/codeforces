#include <bits/stdc++.h>
using namespace std;
#define int long long
struct edge{
	int w,x,y;
};
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
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		vector<edge>edges;
		for(int i = 0; i<m; i++){
			int x,y,w;
			cin >> x >> y >> w;
			edges.push_back({w,x,y});
		}
		int ans = 0;
		for(int i = 30; i>=0; i--){
			vector<edge>arr;
			DisjointSet ds;
			ds.init(n);
			for(edge nxt: edges){
				if(nxt.w&(1<<i)){
					continue;
				}
				arr.push_back(nxt);
				ds.Union(nxt.x, nxt.y);
			}
			if(ds.sz[ds.find(1)]==n){
				edges.clear();
				for(edge nxt: arr){
					edges.push_back(nxt);
				}
			}
			else{
				ans^=(1<<i);
			}
		}
		cout << ans << "\n";
	}
	return 0;
}