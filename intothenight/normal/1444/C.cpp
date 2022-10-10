#include <bits/stdc++.h>
using namespace std;

struct rollback_disjoint_set{
	vector<int> p;
	vector<pair<int, int>> log;
	rollback_disjoint_set(int n): p(n, -1){ }
	bool share(int a, int b){ return root(a) == root(b); }
	int sz(int u){ return -p[root(u)]; }
	int root(int u){ return p[u] < 0 ? u : root(p[u]); } // O(log n)
	bool merge(int u, int v){
		u = root(u), v = root(v);
		if(u == v) return false;
		if(p[u] > p[v]) swap(u, v);
		log.emplace_back(v, p[v]);
		p[u] += p[v], p[v] = u;
		return true;
	}
	int time(){ return (int)log.size(); }
	void reverse_to(int t = 0){
		for(int i = time(); i --> t; ){
			auto [v, pv] = log[i]; int u = p[v];
			p[u] -= pv, p[v] = pv;
		}
		log.resize(t);
	}
};

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> gn(n);
	for(auto u = 0; u < n; ++ u){
		cin >> gn[u], -- gn[u];
	}
	rollback_disjoint_set dsu(2 * n);
	vector<int> isbad(k);
	vector<pair<int, int>> edges, badpair;
	for(auto i = 0; i < m; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		if(gn[u] == gn[v]){
			dsu.merge(u, v + n), dsu.merge(u + n, v);
			if(dsu.share(u, u + n)){
				isbad[gn[u]] = true;
			}
		}
		else{
			if(gn[u] > gn[v]){
				swap(u, v);
			}
			edges.push_back({u, v});
		}
	}
	m = (int)edges.size();
	sort(edges.begin(), edges.end(), [&](auto e, auto f){ return pair{gn[e.first], gn[e.second]} < pair{gn[f.first], gn[f.second]}; });
	for(auto i = 0, j = 0, ti = dsu.time(); i < m; ){
		while(j < m && pair{gn[edges[i].first], gn[edges[i].second]} == pair{gn[edges[j].first], gn[edges[j].second]}){
			if(!isbad[gn[edges[i].first]] && !isbad[gn[edges[i].second]]){
				dsu.merge(edges[j].first, n + edges[j].second);
				dsu.merge(n + edges[j].first, edges[j].second);
				if(dsu.share(edges[j].first, n + edges[j].first)){
					badpair.push_back({gn[edges[j].first], gn[edges[j].second]});
				}
			}
			++ j;
		}
		dsu.reverse_to(ti);
		i = j;
	}
	sort(badpair.begin(), badpair.end()), badpair.erase(unique(badpair.begin(), badpair.end()), badpair.end());
	int bad = accumulate(isbad.begin(), isbad.end(), 0);
	cout << 1LL * k * (k - 1) / 2 - 1LL * bad * (bad - 1) / 2 - 1LL * bad * (k - bad) - (int)badpair.size() << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////