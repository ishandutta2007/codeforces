#include "bits/stdc++.h"
using namespace std;

struct disjoint_set{
	vector<int> p;
	disjoint_set(int n): p(n, -1){ }
	bool share(int a, int b){ return root(a) == root(b); }
	int sz(int u){ return -p[root(u)]; }
	int root(int u){ return p[u] < 0 ? u : p[u] = root(p[u]); }
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
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> s(n), a(k);
	for(auto i = 0; i < k; ++ i){
		cin >> a[i], -- a[i];
		s[a[i]] = true;
	}
	vector<array<int, 3>> edges(m);
	for(auto &[w, u, v]: edges){
		cin >> u >> v >> w, -- u, -- v;
	}
	sort(edges.begin(), edges.end());
	int cnt = k;
	array<int, 3> res;
	disjoint_set dsu(n);
	for(auto [w, u, v]: edges){
		res = {w, u, v};
		u = dsu.root(u), v = dsu.root(v);
		if(u == v){
			continue;
		}
		else if(s[u] && s[v]){
			if(cnt == 2){
				break;
			}
			-- cnt;
			dsu.merge(u, v);
		}
		else if(s[u] || s[v]){
			dsu.merge(u, v);
			u = dsu.root(u);
			s[u] = true;
		}
		else{
			dsu.merge(u, v);
		}
	}
	for(auto i = 0; i < k; ++ i){
		cout << res[0] << " ";
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