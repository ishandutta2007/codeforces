#include "bits/stdc++.h"
using namespace std;

struct disjoint_set{
	vector<int> p, cycle;
	disjoint_set(int n): p(n, -1), cycle(n){ }
	bool share(int a, int b){ return root(a) == root(b); }
	int sz(int u){ return -p[root(u)]; }
	int root(int u){ return p[u] < 0 ? u : root(p[u]); }
	bool merge(int u, int v){
		u = root(u), v = root(v);
		if(u == v) return false;
		if(p[u] > p[v]) swap(u, v);
		p[u] += p[v], p[v] = u;
		if(cycle[v]){
			cycle[u] = true;
		}
		return true;
	}
	bool has_cycle(int u){
		return cycle[root(u)];
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<array<int, 3>> a(m);
	for(auto &[w, u, v]: a){
		cin >> u >> v >> w, -- u, -- v;
	}
	sort(a.rbegin(), a.rend());
	long long res = 0;
	disjoint_set dsu(n);
	for(auto &[w, u, v]: a){
		if(dsu.share(u, v)){
			if(!dsu.has_cycle(u)){
				res += w;
				dsu.cycle[dsu.root(u)] = true;
			}
		}
		else if(!dsu.has_cycle(u) || !dsu.has_cycle(v)){
			res += w;
			dsu.merge(u, v);
		}
	}
	cout << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////