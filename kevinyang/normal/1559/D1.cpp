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
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	DisjointSet ds;
	DisjointSet ds2;
	int n,m1,m2;
	cin >> n >> m1 >> m2;
	ds.init(n);
	ds2.init(n);
	for(int i = 0; i<m1; i++){
		int x,y;
		cin >> x >> y;
		ds.Union(x,y);
	}
	for(int i = 0; i<m2; i++){
		int x,y;
		cin >> x >> y;
		ds2.Union(x,y);
	}
	vector<pair<int,int>>ans;
	for(int i = 1; i<=n; i++){
		for(int j = i+1; j<=n; j++){
			if(ds.find(i)!=ds.find(j)&&ds2.find(i)!=ds2.find(j)){
				ds.Union(i,j);
				ds2.Union(i,j);
				ans.push_back({i,j});
			}
		}
	}
	cout << ans.size() << "\n";
	for(pair<int,int>nxt: ans){
		cout << nxt.first << " " << nxt.second << "\n";
	}
	return 0;
}