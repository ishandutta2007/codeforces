#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	auto __solve_tc = [&](int __tc_num){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> adj(n);
		for(int i = 0; i < m; ++ i){
			int u, v;
			cin >> u >> v, -- u, -- v;
			adj[u].push_back(v), adj[v].push_back(u);
		}
		vector<int> depth(n), vis(n), par(n);
		vector<vector<int>> rd(n);
		function<void(int)> dfs = [&](int u){
			vis[u] = true;
			rd[depth[u]].push_back(u);
			for(auto v: adj[u]){
				if(!vis[v]){
					depth[v] = depth[u] + 1;
					par[v] = u;
					dfs(v);
				}
			}
		};
		dfs(0);
		for(auto r = 0; r < n; ++ r){
			if(depth[r] + 1 >= (n + 1) / 2){
				cout << "PATH\n" << depth[r] + 1 << "\n";
				while(r){
					cout << r + 1 << " ";
					r = par[r];
				}
				cout << r + 1 << "\n";
				return 0;
			}
		}
		vector<array<int, 2>> res;
		for(auto d = 0; d < n; ++ d){
			for(auto i = 0; i + 2 <= int(rd[d].size()); i += 2){
				res.push_back({rd[d][i], rd[d][i + 1]});
			}
		}
		cout << "PAIRING\n" << int(res.size()) << "\n";
		for(auto [u, v]: res){
			cout << u + 1 << " " << v + 1 << "\n";
		}
		return 0;
	};
	int __tc_cnt;
	cin >> __tc_cnt;
	for(auto __tc_num = 0; __tc_num < __tc_cnt; ++ __tc_num){
		__solve_tc(__tc_num);
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