#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

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
	int n;
	cin >> n;
	vector<vector<int>> lca_w(n, vector<int>(n));
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < n; ++ j){
			cin >> lca_w[i][j];
		}
	}
	vector<int> w(n);
	vector<array<int, 2>> edges;
	function<int(vector<int>)> solve = [&](vector<int> a){
		if((int)a.size() == 1){
			w[a[0]] = lca_w[a[0]][a[0]];
			return a[0];
		}
		int n = (int)a.size(), mxw = -1;
		for(auto i = 0; i < n; ++ i){
			for(auto j = i + 1; j < n; ++ j){
				ctmax(mxw, lca_w[a[i]][a[j]]);
			}
		}
		disjoint_set dsu(n);
		for(auto i = 0; i < n; ++ i){
			for(auto j = i + 1; j < n; ++ j){
				if(mxw != lca_w[a[i]][a[j]]){
					dsu.merge(i, j);
				}
			}
		}
		int root = (int)w.size();
		w.push_back(mxw);
		for(auto g: dsu.group_up()){
			for(auto &i: g){
				i = a[i];
			}
			edges.push_back({solve(g), root});
		}
		return root;
	};
	vector<int> leaves(n);
	iota(leaves.begin(), leaves.end(), 0);
	int head = solve(leaves);
	cout << (int)edges.size() + 1 << "\n";
	for(auto x: w){
		cout << x << " ";
	}
	cout << "\n" << head + 1 << "\n";
	for(auto [u, v]: edges){
		cout << u + 1 << " " << v + 1 << "\n";
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