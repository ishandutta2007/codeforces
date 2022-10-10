#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif
template<class T> T &ctmin(T &x){ return x; }
template<class T, class Head, class ...Tail> T &ctmin(T &x, const Head &h, const Tail &... t){ return ctmin(x = min<T>(x, h), t...); }
template<class T> T &ctmax(T &x){ return x; }
template<class T, class Head, class ...Tail> T &ctmax(T &x, const Head &h, const Tail &... t){ return ctmax(x = max<T>(x, h), t...); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> adj(n), radj(n);
	vector<int> outdeg(n);
	for(auto i = 0; i < m; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		adj[u].push_back(v);
		radj[v].push_back(u);
		++ outdeg[u];
	}
	const int inf = numeric_limits<int>::max() / 2;
	vector<int> dist(n, inf);
	dist[n - 1] = 0;
	set<array<int, 2>> s;
	for(auto u = 0; u < n; ++ u){
		s.insert({dist[u], u});
	}
	vector<int> done(n);
	while(!s.empty()){
		auto [d, u] = *s.begin();
		s.erase(s.begin());
		done[u] = true;
		for(auto v: radj[u]){
			if(done[v]){
				continue;
			}
			s.erase({dist[v], v});
			-- outdeg[v];
			ctmin(dist[v], dist[u] + 1 + outdeg[v]);
			s.insert({dist[v], v});
		}
	}
	cout << dist[0] << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////