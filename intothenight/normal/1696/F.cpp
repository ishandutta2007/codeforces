#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

template<bool Enable_small_to_large = true>
struct disjoint_set{
	int n, _classes;
	vector<int> p;
	disjoint_set(int n): n(n), _classes(n), p(n, -1){ }
	int make_set(){
		p.push_back(-1);
		++ _classes;
		return n ++;
	}
	int classes() const{
		return _classes;
	}
	int root(int u){
		return p[u] < 0 ? u : p[u] = root(p[u]);
	}
	bool share(int a, int b){
		return root(a) == root(b);
	}
	int size(int u){
		return -p[root(u)];
	}
	bool merge(int u, int v){
		u = root(u), v = root(v);
		if(u == v) return false;
		-- _classes;
		if constexpr(Enable_small_to_large) if(p[u] > p[v]) swap(u, v);
		p[u] += p[v], p[v] = u;
		return true;
	}
	bool merge(int u, int v, auto act){
		u = root(u), v = root(v);
		if(u == v) return false;
		-- _classes;
		bool swapped = false;
		if constexpr(Enable_small_to_large) if(p[u] > p[v]) swap(u, v), swapped = true;
		p[u] += p[v], p[v] = u;
		act(u, v, swapped);
		return true;
	}
	void clear(){
		_classes = n;
		fill(p.begin(), p.end(), -1);
	}
	vector<vector<int>> group_up(){
		vector<vector<int>> g(n);
		for(auto i = 0; i < n; ++ i) g[root(i)].push_back(i);
		g.erase(remove_if(g.begin(), g.end(), [&](auto &s){ return s.empty(); }), g.end());
		return g;
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n;
		cin >> n;
		vector a(n, vector(n, vector<int>(n)));
		for(auto u = 0; u < n; ++ u){
			for(auto t = 1; t < n - u; ++ t){
				int v = u + t;
				string s;
				cin >> s;
				for(auto w = 0; w < n; ++ w){
					if(s[w] == '1'){
						a[u][v][w] = true;
						a[v][u][w] = true;
					}
				}
			}
		}
		for(auto u = 0; u < n; ++ u){
			for(auto v = 0; v < n; ++ v){
				a[u][u][v] = true;
			}
		}
		vector<vector<vector<int>>> c(n);
		for(auto r = 0; r < n; ++ r){
			disjoint_set dsu(n);
			for(auto u = 0; u < n; ++ u){
				for(auto v = u + 1; v < n; ++ v){
					if(a[u][v][r]){
						dsu.merge(u, v);
					}
				}
			}
			c[r] = dsu.group_up();
			erase(c[r], vector<int>{r});
		}
		for(auto i = 0; i < (int)c[0].size(); ++ i){
			vector<int> vis(n), pv(n, -1), q = c[0][i];
			vis[0] = true;
			for(auto u: c[0][i]){
				vis[u] = true;
				pv[u] = 0;
			}
			for(auto t = 0; t < (int)q.size(); ++ t){
				int u = q[t];
				for(auto i = 0; i < (int)c[u].size(); ++ i){
					if(ranges::find(c[u][i], pv[u]) != c[u][i].end()){
						for(auto v: c[u][i]){
							if(!vis[v]){
								vis[v] = true;
								pv[v] = u;
								q.push_back(v);
							}
						}
						break;
					}
				}
			}
			if(ranges::min(vis)){
				vector<vector<int>> adj(n);
				for(auto u = 1; u < n; ++ u){
					adj[pv[u]].push_back(u);
					adj[u].push_back(pv[u]);
				}
				vector<vector<int>> dist(n, vector<int>(n, -1));
				for(auto s = 0; s < n; ++ s){
					dist[s][s] = 0;
					vector<int> q{s};
					for(auto t = 0; t < (int)q.size(); ++ t){
						int u = q[t];
						for(auto v: adj[u]){
							if(!~dist[s][v]){
								dist[s][v] = dist[s][u] + 1;
								q.push_back(v);
							}
						}
					}
				}
				for(auto u = 0; u < n; ++ u){
					for(auto v = u + 1; v < n; ++ v){
						for(auto w = 0; w < n; ++ w){
							if((dist[u][w] == dist[v][w]) != a[u][v][w]){
								goto FAIL;
							}
						}
					}
				}
				cout << "Yes\n";
				for(auto u = 1; u < n; ++ u){
					cout << pv[u] + 1 << " " << u + 1 << "\n";
				}
				return 0;
				FAIL:;
			}
		}
		cout << "No\n";
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