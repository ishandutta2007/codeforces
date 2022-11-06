
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
		return parent[x] = find(parent[x]);
	}
	void Union(int x, int y){
		x = find(x); y = find(y);
		if(x==y)return;
		parent[x] = y;
		sz[y]+=sz[x];
	}
};
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		int n,m;
		cin >> n >> m;
		vector<int>val(n+1);
		for(int i = 1; i<=n; i++){
			cin >> val[i];
		}
		for(int i = 1; i<=n; i++){
			int x;
			cin >> x;
			val[i]-=x;
		}
		DisjointSet ds;
		ds.init(n);
		vector<vector<int>>nodes(n+1);
		for(int i = 1; i<=n; i++){
			nodes[i].push_back(i);
		}
		vector<int>group(n+1);
		bool bp = true;
		for(int i = 0; i<m; i++){
			int x,y;
			cin >> x >> y;
			int x1 = ds.find(x); int y1 = ds.find(y);
			if(ds.find(x)==ds.find(y)){
				if(group[x]==group[y]){
					bp = false;
				}
			}
			else{
				if(ds.sz[x1]<ds.sz[y1]){
					if(group[x]==group[y]){
						for(int nxt: nodes[x1]){
							group[nxt]^=1;
						}
					}
					for(int nxt: nodes[x1]){
						nodes[y1].push_back(nxt);
					}
					nodes[x1].clear();
					ds.Union(x,y);
				}
				else{
					if(group[y]==group[x]){
						for(int nxt: nodes[y1]){
							group[nxt]^=1;
						}
					}
					for(int nxt: nodes[y1]){
						nodes[x1].push_back(nxt);
					}
					nodes[y1].clear();
					ds.Union(y,x);
				}
			}
		}
		if(bp){
			int v1 = 0; int v0 = 0;
			for(int i = 1; i<=n; i++){
				if(group[i]==0){
					v0+=val[i];
				}
				else{
					v1+=val[i];
				}
			}
			if(v1==v0){
				cout << "YES\n";
			}
			else{
				cout << "NO\n";
			}
		}
		else{
			int v = 0;
			for(int i = 1; i<=n; i++){
				v+=val[i];
			}
			if(v%2==0){
				cout << "YES\n";
			}
			else{
				cout << "NO\n";
			}
		}
	}
	return 0;
}