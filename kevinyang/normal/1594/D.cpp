#include <bits/stdc++.h>
using namespace std;
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
		DisjointSet ds;
		ds.init(n);
		vector<int>group(n+1);
		vector<vector<int>>ind(n+1);
		for(int i = 1; i<=n; i++){
			ind[i].push_back(i);
		}
		vector<vector<int>>adj(n+1);
		bool f = true;
		for(int i = 0; i<m; i++){
			int x,y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
			string s;
			cin >> s;
			if(s=="crewmate"){
				if(ds.find(x)==ds.find(y)){
					if(group[x]!=group[y])f = false;

				}
				else{
					if(ds.sz[ds.find(x)]<ds.sz[ds.find(y)]){
						int val = 0;
						if(group[x]!=group[y])val = 1;
						for(int nxt: ind[ds.find(x)]){
							ind[ds.find(y)].push_back(nxt);
							group[nxt]^=val;
						}
						ind[ds.find(x)].clear();
						ds.Union(x,y);
					}
					else{
						int val = 0;
						if(group[x]!=group[y])val = 1;
						for(int nxt: ind[ds.find(y)]){
							ind[ds.find(x)].push_back(nxt);
							group[nxt]^=val;
						}
						ind[ds.find(y)].clear();
						ds.Union(y,x);
					}
				}
			}
			else{
				if(ds.find(x)==ds.find(y)){
					if(group[x]==group[y])f = false;
				}
				else{
					if(ds.sz[ds.find(x)]<ds.sz[ds.find(y)]){
						int val = 0;
						if(group[x]==group[y])val = 1;
						for(int nxt: ind[ds.find(x)]){
							ind[ds.find(y)].push_back(nxt);
							group[nxt]^=val;
						}
						ind[ds.find(x)].clear();
						ds.Union(x,y);
					}
					else{
						int val = 0;
						if(group[x]==group[y])val = 1;
						for(int nxt: ind[ds.find(y)]){
							ind[ds.find(x)].push_back(nxt);
							group[nxt]^=val;
						}
						ind[ds.find(y)].clear();
						ds.Union(y,x);
					}
				}
			}
		}
		if(!f){
			cout << "-1\n";
			continue;
		}
		int ans = 0;
		vector<bool>vis(n+1);
		for(int i = 1; i<=n; i++){
			if(vis[i])continue;
			queue<int>q;
			q.push(i);
			vis[i] = true;
			int cnt0 = 0; int cnt1 = 0;
			if(group[i]==0)cnt0++;
			else cnt1++;
			while(q.size()){
				int cur = q.front(); q.pop();
				for(int nxt: adj[cur]){
					if(vis[nxt])continue;
					vis[nxt] = true;
					q.push(nxt);
					if(group[nxt]==0)cnt0++;
					else cnt1++;
				}
			}
			ans+=max(cnt0,cnt1);
		}
		cout << ans << "\n";
	}
	return 0;
}