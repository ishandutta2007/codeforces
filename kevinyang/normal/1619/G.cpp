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
	int t;
	cin >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		vector<pair<int,int>>arr(n+1);
		vector<int>timer(n+1);
		map<pair<int,int>,int>val;
		map<int,set<int>>hmx;
		map<int,set<int>>hmy;
		set<int>sx;
		set<int>sy;
		for(int i = 1; i<=n; i++){
			int x,y,c;
			cin >> x >> y >> c;
			timer[i] = c;
			arr[i] = {x,y};
			val[arr[i]] = i;
			hmx[x].insert(y);
			hmy[y].insert(x);
			sx.insert(x);
			sy.insert(y);
		}
		DisjointSet ds;
			ds.init(n);
			for(int i = 1; i<=n; i++){
				int x = arr[i].first; int y = arr[i].second;
				if(*hmx[x].begin()!=y){
					int v = *--hmx[x].lower_bound(y);
					if(abs(y-v)<=k){
						int j = val[{x,v}];
						ds.Union(i,j);
					}
				}
				if(*--hmx[x].end()!=y){
					int v = *hmx[x].upper_bound(y);
					if(abs(y-v)<=k){
						int j = val[{x,v}];
						ds.Union(i,j);
					}
				}
				if(*hmy[y].begin()!=x){
					int v = *--hmy[y].lower_bound(x);
					if(abs(x-v)<=k){
						int j = val[{v,y}];
						ds.Union(i,j);
					}
				}
				if(*--hmy[y].end()!=x){
					int v = *hmy[y].upper_bound(x);
					if(abs(x-v)<=k){
						int j = val[{v,y}];
						ds.Union(i,j);
					}
				}
			}
		int low = -1; int high = (int)2e9; int mid = (low+high)/2;
		while(low+1<high){
			DisjointSet ds2;
			ds2.init(n);
			for(int i = 1; i<=n; i++){
				ds2.sz[i] = ds.sz[i];
				ds2.parent[i] = ds.parent[i];
			}
			vector<bool>vis(n+1);
			for(int i = 1; i<=n; i++){
				vis[ds.find(i)] = true;
			}
			for(int i = 1; i<=n; i++){
				if(timer[i]<=mid){
					int v = ds.find(i);
					vis[v] = false;
				}
			}
			if(count(vis.begin(),vis.end(),true)<=mid+1){
				high = mid;
			}
			else{
				low = mid;
			}
			mid = (low+high)/2;
		}
		cout << high << "\n";
	}
	return 0;
}