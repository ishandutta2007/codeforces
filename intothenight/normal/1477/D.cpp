#include <bits/stdc++.h>
using namespace std;



struct disjoint_set{
	vector<int> p;
	disjoint_set(int n): p(n, -1){ }
	bool share(int a, int b){ return root(a) == root(b); }
	int sz(int u){ return -p[root(u)]; }
	int root(int u){ return p[u] < 0 ? u : p[u] = root(p[u]); } // O(alpha(n))
	bool merge(int u, int v){
		u = root(u), v = root(v);
		if(u == v) return false;
		if(p[u] > p[v]) swap(u, v);
		p[u] += p[v], p[v] = u;
		return true;
	}
	vector<vector<int>> group_up(){
		vector<vector<int>> g((int)p.size());
		for(auto i = 0; i < (int)p.size(); ++ i) g[root(i)].push_back(i);
		g.erase(remove_if(g.begin(), g.end(), [&](auto &s){ return s.empty(); }), g.end());
		return g;
	}
};



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> adj(n);
		for(auto i = 0; i < m; ++ i){
			int u, v;
			cin >> u >> v, -- u, -- v;
			adj[u].push_back(v), adj[v].push_back(u);
		}
		vector<int> resp(n, -1), resq(n, -1), full(n), notfull;
		int mx = n;
		for(auto u = 0; u < n; ++ u){
			if((int)adj[u].size() == n - 1){
				full[u] = true;
				resp[u] = resq[u] = -- mx;
			}
			else{
				notfull.push_back(u);
			}
		}
		vector<vector<int>> forest(n);
		disjoint_set dsu(n);
		for(auto u = 0; u < n; ++ u){
			if(!full[u]){
				adj[u].push_back(u);
				sort(adj[u].begin(), adj[u].end());
				adj[u].erase(remove_if(adj[u].begin(), adj[u].end(), [&](int u){ return full[u]; }), adj[u].end());
				for(auto i = 0; ; ++ i){
					if(i == (int)adj[u].size() || adj[u][i] != notfull[i]){
						if(dsu.merge(u, notfull[i])){
							int v = notfull[i];
							forest[u].push_back(v), forest[v].push_back(u);
						}
						break;
					}
				}
			}
		}
		vector<int> assigned(n), root_or_sz(n, -1);
		for(auto u = 0; u < n; ++ u){
			if(!full[u] && !assigned[u]){
				assigned[u] = true;
				vector<int> unassigned;
				for(auto v: forest[u]){
					if(!assigned[v]){
						unassigned.push_back(v);
					}
				}
				if(unassigned.empty()){
					int v = forest[u][0], r = root_or_sz[v];
					assert(r >= 0 && root_or_sz[r] <= -2);
					if(root_or_sz[r] == -2){
						root_or_sz[r] = v;
						unassigned.push_back(u);
						unassigned.push_back(r);
						for(auto w: forest[v]){
							if(assigned[w]){
								continue;
							}
							unassigned.push_back(w);
						}
						root_or_sz[v] = -((int)unassigned.size() + 1);
						for(auto w: unassigned){
							assigned[w] = true;
							root_or_sz[w] = v;
						}
					}
					else{
						++ root_or_sz[r];
						root_or_sz[v] = u;
						root_or_sz[u] = -2;
					}
				}
				else{
					root_or_sz[u] = -((int)unassigned.size() + 1);
					for(auto v: unassigned){
						assigned[v] = true;
						root_or_sz[v] = u;
					}
				}
			}
		}
		vector<vector<int>> g(n);
		for(auto u = 0; u < n; ++ u){
			if(root_or_sz[u] >= 0){
				g[root_or_sz[u]].push_back(u);
			}
		}
		for(auto u = 0; u < n; ++ u){
			if(g[u].empty()){
				continue;
			}
			int sz = -root_or_sz[u];
			resp[u] = mx - 1;
			resq[u] = mx - sz;
			for(auto i = 0; i < sz - 1; ++ i){
				resp[g[u][i]] = mx - sz + i;
				resq[g[u][i]] = mx - sz + i + 1;
			}
			mx -= sz;
		}
		for(auto x: resp){
			cout << x + 1 << " ";
		}
		cout << "\n";
		for(auto x: resq){
			cout << x + 1 << " ";
		}
		cout << "\n";
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