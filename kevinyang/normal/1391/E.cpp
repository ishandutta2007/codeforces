#include <bits/stdc++.h>
using namespace std;
int n,m;
int mxn = 500005;
vector<vector<int>>adj(mxn);
vector<int>lvl(mxn);
vector<int>parent(mxn);
vector<bool>vis(mxn);
void dfs(int u, int p){
	vis[u] = true;
	lvl[u] = lvl[p]+1;
	parent[u] = p;
	for(int nxt: adj[u]){
		if(nxt==p)continue;
		if(vis[nxt])continue;
		dfs(nxt,u);
	}
}
signed main(){
	cin.tie(nullptr)->sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--){
		cin >> n >> m;
		for(int i = 0; i<m; i++){
			int x,y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		dfs(1,0);
		int mx = 0; int node = 1;
		vector<int>q(n+1);
		for(int i = 1; i<=n; i++){
			if(lvl[i]>mx){
				mx = lvl[i];
				node = i;
			}
		}
		if(mx>=(n+1)/2){
			vector<int>ans;
			while(node!=1){
				ans.push_back(node);
				node = parent[node];
			}
			ans.push_back(1);
			cout << "PATH\n";
			cout << ans.size() << "\n";
			for(int nxt: ans){
				cout << nxt << " ";
			}
			cout << "\n";
		}
		else{
			vector<pair<int,int>>ans;
			for(int i = 1; i<=n; i++){
				if(q[lvl[i]]!=0){
					ans.push_back({q[lvl[i]],i});
					q[lvl[i]] = 0;
				}
				else{
					q[lvl[i]] = i;
				}
			}
			cout << "PAIRING\n";
			cout << ans.size() << "\n";
			for(pair<int,int>nxt: ans){
				cout << nxt.first << " " << nxt.second << "\n";
			}
		}
		for(int i = 1; i<=n; i++){
			adj[i].clear();
			parent[i] = lvl[i] = vis[i] = 0;
		}
	}
	return 0;
}