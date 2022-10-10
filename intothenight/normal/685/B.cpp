#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, qn;
	cin >> n >> qn;
	vector<vector<int>> adj(n);
	vector<int> par(n, -1);
	for(auto u = 1; u < n; ++ u){
		int p;
		cin >> p, -- p;
		adj[p].push_back(u);
		par[u] = p;
	}
	vector<int> sz(n, 1);
	function<void(int)> dfs = [&](int u){
		for(auto v: adj[u]){
			dfs(v);
			sz[u] += sz[v];
		}
	};
	dfs(0);
	vector<int> mxc(n, -1);
	for(auto u = 0; u < n; ++ u){
		if(!adj[u].empty()){
			mxc[u] = *max_element(adj[u].begin(), adj[u].end(), [&](int u, int v){ return sz[u] < sz[v]; });
		}
	}
	vector<int> c(n), flag(n);
	function<void(int)> solve = [&](int u){
		int v = flag[u] ? c[par[u]] : u;
		while(true){
			flag[v] = true;
			if(~mxc[v] && sz[mxc[v]] > sz[u] >> 1){
				v = mxc[v];
				goto NEXT;
			}
			break;
			NEXT:;
		}
		c[u] = v;
		for(auto v: adj[u]){
			solve(v);
		}
	};
	solve(0);
	for(auto qi = 0; qi < qn; ++ qi){
		int u;
		cin >> u, -- u;
		cout << c[u] + 1 << "\n";
	}
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////