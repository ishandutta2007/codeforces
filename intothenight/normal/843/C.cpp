#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<vector<int>> adj(n);
	for(auto i = 0; i < n - 1; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	for(auto u = 0; u < n; ++ u){
		sort(adj[u].begin(), adj[u].end());
	}
	vector<int> sz(n, 1);
	function<void(int, int)> dfs = [&](int u, int p){
		for(auto v: adj[u]){
			if(v ^ p){
				dfs(v, u);
				sz[u] += sz[v];
			}
		}
	};
	dfs(0, -1);
	vector<int> cent, is_cent(n);
	{
		int u = 0, p = -1;
		while(true){
			for(auto v: adj[u]){
				if(v ^ p && sz[v] > n / 2){
					p = u, u = v;
					goto NEXT;
				}
			}
			break;
			NEXT:;
		}
		for(auto v: adj[u]){
			if(v ^ p && sz[v] * 2 == n){
				cent = {u, v};
				is_cent[u] = is_cent[v] = true;
				break;
			}
		}
		if(cent.empty()){
			cent = {u};
			is_cent[u] = true;
		}
	}
	vector<array<int, 3>> res;
	auto act = [&](int u, int v, int w){
		if(v == w){
			return;
		}
		res.push_back({u, v, w});
	};
	vector<int> par(n, -1);
	for(auto c: cent){
		for(auto u: adj[c]){
			if(!is_cent[u]){
				vector<int> order;
				function<void(int, int)> dfs = [&](int u, int p){
					par[u] = p;
					for(auto v: adj[u]){
						if(v ^ p){
							dfs(v, u);
						}
					}
					order.push_back(u);
				};
				dfs(u, c);
				act(c, u, order.front());
				for(auto i = 0; i < (int)order.size() - 1; ++ i){
					if(par[order[i]] != order[i + 1]){
						act(order[i], par[order[i]], order[i + 1]);
					}
				}
				if((int)order.size() >= 3){
					for(auto i = (int)order.size() - 3; i >= 0; -- i){
						act(order[i], order[i + 1], order.back());
					}
					act(c, order[0], order.back());
				}
			}
		}
	}
	assert((int)res.size() <= 2 * n);
	cout << (int)res.size() << "\n";
	for(auto [u, v, w]: res){
		cout << u + 1 << " " << v + 1 << " " << w + 1 << "\n";
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