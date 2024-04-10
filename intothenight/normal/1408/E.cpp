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
	int m, n;
	cin >> m >> n;
	vector<int> a(m), b(n);
	for(auto i = 0; i < m; ++ i){
		cin >> a[i];
	}
	for(auto i = 0; i < n; ++ i){
		cin >> b[i];
	}
	vector<array<int, 3>> edges;
	long long tot = 0;
	for(auto i = 0; i < m; ++ i){
		int s;
		cin >> s;
		for(auto rep = 0; rep < s; ++ rep){
			int j;
			cin >> j, -- j;
			edges.push_back({a[i] + b[j], i, j + m});
			tot += a[i] + b[j];
		}
	}
	sort(edges.rbegin(), edges.rend());
	disjoint_set dsu(n + m);
	for(auto [w, u, v]: edges){
		if(dsu.merge(u, v)){
			tot -= w;
		}
	}
	cout << tot << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////