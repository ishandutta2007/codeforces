#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n);
	vector<int> isloop(n);
	int loop = 0;
	for(auto i = 0; i < m; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		if(u == v){
			++ loop;
			isloop[u] = true;
		}
		adj[u].push_back(v), adj[v].push_back(u);
	}
	vector<int> vis(n);
	int cnt = 0;
	function<void(int)> dfs = [&](int u){
		vis[u] = true;
		cnt += (int)adj[u].size();
		for(auto v: adj[u]){
			if(!vis[v]){
				dfs(v);
			}
		}
	};
	int u = 0;
	while(adj[u].empty()){
		++ u;
	}
	dfs(u);
	if(cnt != 2 * m){
		cout << "0\n";
		return 0;
	}
	long long res = 1LL * loop * (loop - 1) / 2 + 1LL * loop * (m - loop);
	for(auto u = 0; u < n; ++ u){
		int deg = (int)adj[u].size() - isloop[u] * 2;
		res += 1LL * deg * (deg - 1) / 2;
	}
	cout << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////