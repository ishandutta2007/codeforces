#include <bits/stdc++.h>
using namespace std;

struct disjoint_set{
	vector<int> p;
	disjoint_set(int n): p(n, -1){ }
	bool share(int a, int b){ return root(a) == root(b); }
	int size(int u){ return -p[root(u)]; }
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
		vector<string> a(n);
		for(auto &s: a){
			cin >> s;
		}
		for(auto i = 0; i < n; ++ i){
			for(auto j = 0; j < m; ++ j){
				if(i % 3 == 0){
					a[i][j] = 'X';
				}
			}
		}
		disjoint_set dsu(n * m);
		auto ind = [&](int i, int j){
			return i * m + j;
		};
		static const vector<pair<int, int>> dr{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
		auto merge = [&](int i, int j){
			assert(a[i][j] == 'X');
			for(auto [di, dj]: dr){
				int ni = i + di, nj = j + dj;
				if(0 <= ni && ni < n && 0 <= nj && nj < m && a[ni][nj] == 'X'){
					dsu.merge(ind(i, j), ind(ni, nj));
				}
			}
		};
		for(auto i = 0; i < n; ++ i){
			for(auto j = 0; j < m; ++ j){
				if(a[i][j] == 'X'){
					merge(i, j);
				}
			}
		}
		for(auto i = 0; i < n; ++ i){
			for(auto j = 0; j < m; ++ j){
				if(a[i][j] == 'X' && !dsu.share(0, ind(i, j))){
					if(i % 3 == 0){
						if(j + 1 < m && a[i - 2][j + 1] == 'X'){
							a[i - 1][j + 1] = 'X';
							merge(i - 1, j + 1);
						}
						else{
							a[i - 1][j] = 'X';
							merge(i - 1, j);
							a[i - 2][j] = 'X';
							merge(i - 2, j);
						}
					}
					else if(i % 3 == 1){
						assert(false);
					}
					else{
						a[i - 1][j] = 'X';
						merge(i - 1, j);
					}
				}
			}
		}
		for(auto s: a){
			cout << s << "\n";
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