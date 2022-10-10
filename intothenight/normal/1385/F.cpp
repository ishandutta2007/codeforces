#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	auto __solve_tc = [&](){
		int n, k;
		cin >> n >> k;
		vector<vector<int>> temp(n);
		vector<int> adjleafcnt(n), deg(n);
		for(int i = 1; i < n; ++ i){
			int u, v;
			cin >> u >> v, -- u, -- v;
			temp[u].push_back(v), temp[v].push_back(u);
			++ deg[u], ++ deg[v];
		}
		vector<set<pair<int, int>>> adj(n);
		set<pair<int, int>, greater<>> s;
		for(auto u = 0; u < n; ++ u){
			for(auto v: temp[u]){
				adj[u].insert({deg[v], v});
				if(deg[v] == 1){
					++ adjleafcnt[u];
				}
			}
			s.insert({adjleafcnt[u], u});
		}
		int res = 0;
		while(!s.empty() && s.begin()->first >= k){
			auto [x, u] = *s.begin(); s.erase(s.begin());
			res += x / k, x %= k;
			for(; adjleafcnt[u] > x; -- adjleafcnt[u]){
				int v = adj[u].begin()->second; adj[u].erase(adj[u].begin());
				s.erase({adjleafcnt[v], v});
			}
			for(auto [ignore, v]: adj[u]){
				adj[v].erase({deg[u], u});
				adj[v].insert({int(adj[u].size()), u});
			}
			deg[u] = int(adj[u].size());
			if(!adj[u].empty()){
				if(int(adj[u].size()) == 1){
					int v = adj[u].begin()->second;
					s.erase({adjleafcnt[v], v});
					s.insert({++ adjleafcnt[v], v});
				}
				s.insert({adjleafcnt[u], u});
			}
		}
		cout << res << "\n";
		return 0;
	};
	int __tc_cnt;
	cin >> __tc_cnt;
	for(auto __tc_it = 0; __tc_it < __tc_cnt; ++ __tc_it){
		__solve_tc();
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