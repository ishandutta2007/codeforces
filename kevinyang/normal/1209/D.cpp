#include <bits/stdc++.h>
using namespace std;
#define int long long
struct DisjointSet{
	vector<int>parent,sz,edges;
	int size;
	void init(int n){
		size = n;
		parent.resize(n+1); edges.resize(n+1); sz.resize(n+1);
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
			edges[y]+=edges[x]; edges[y]++;
		}
		else{
			parent[y] = x;
			sz[x]+=sz[y];
			edges[x]+=edges[y]; edges[x]++;
		}
	}
};
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int n,k;
	cin >> n >> k;
	DisjointSet ds;
	ds.init(n);
	for(int i = 0; i<k; i++){
		int x,y;
		cin >> x >> y;
		if(ds.find(x)==ds.find(y)){
			ds.edges[ds.find(x)]++;
		}
		else{
			ds.Union(x,y);
		}
	}
	set<int>s;
	int ans = 0;
	for(int i = 1; i<=n; i++){
		if(s.find(ds.find(i))!=s.end())continue;
		s.insert(ds.find(i));
		int e = ds.edges[ds.find(i)];
		int nod = ds.sz[ds.find(i)];
		if(e>=nod)ans+=e-nod+1;
	}
	cout << ans << "\n";
	return 0;
}