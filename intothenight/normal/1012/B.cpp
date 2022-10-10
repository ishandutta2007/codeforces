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
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m, q;
	cin >> n >> m >> q;
	disjoint_set dsu(n + m);
	for(auto i = 0; i < q; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		dsu.merge(u, v + n);
	}
	vector<int> flag(n + m);
	for(auto u = 0; u < n + m; ++ u){
		flag[dsu.root(u)] = true;
	}
	cout << accumulate(flag.begin(), flag.end(), 0) - 1 << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////