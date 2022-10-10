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
	int n, mxh;
	cin >> n >> mxh;
	vector<array<int, 3>> a(n);
	for(auto &[h, l, r]: a){
		cin >> h >> l >> r;
	}
	a.push_back({mxh, (int)-1e9, (int)1e9});
	a.push_back({0, (int)-1e9, (int)1e9});
	ranges::sort(a | ranges::views::reverse);
	n = (int)a.size();
	map<int, array<vector<array<int, 2>>, 2>> event;
	for(auto i = 1; i < n - 1; ++ i){
		auto [h, l, r] = a[i];
		event[l][0].push_back({h, i});
		event[r][1].push_back({h, i});
	}
	auto calc = [&](int u, int v)->int{
		int w = min(a[u][2], a[v][2]) - max(a[u][1], a[v][1]);
		assert(w >= 0);
		return w;
	};
	map<int, int> state;
	state.insert({mxh, 0});
	state.insert({0, n - 1});
	set<array<int, 3>> edge{{0, n - 1, (int)2e9}};
	for(auto &[x, e]: event){
		for(auto [h, i]: e[1]){
			state.erase(h);
			auto it = state.lower_bound(h);
			int u = it->second;
			int v = prev(it)->second;
			if(edge.contains({u, v, calc(u, v)})){
				edge.erase({u, v, calc(u, v)});
			}
		}
		for(auto [h, i]: e[0]){
			auto it = state.lower_bound(h);
			int u = it->second;
			int v = prev(it)->second;
			if(edge.contains({u, v, calc(u, v)})){
				edge.erase({u, v, calc(u, v)});
			}
			state.insert({h, i});
			edge.insert({u, i, calc(u, i)});
			edge.insert({i, v, calc(i, v)});
		}
	}
	vector<vector<array<int, 2>>> adj(n);
	for(auto [u, v, w]: edge){
		adj[u].push_back({v, w});
	}
	vector<int> res(n);
	res[0] = numeric_limits<int>::max();
	for(auto u = 0; u < n; ++ u){
		for(auto [v, w]: adj[u]){
			ctmax(res[v], min(w, res[u]));
		}
	}
	cout << res[n - 1] << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////