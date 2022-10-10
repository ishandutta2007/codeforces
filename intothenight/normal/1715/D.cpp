#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif

template<class F>
struct y_combinator_result{
	F f;
	template<class T> explicit y_combinator_result(T &&f): f(forward<T>(f)){ }
	template<class ...Args> decltype(auto) operator()(Args &&...args){ return f(ref(*this), forward<Args>(args)...); }
};
template<class F>
decltype(auto) y_combinator(F &&f){
	return y_combinator_result<decay_t<F>>(forward<F>(f));
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<vector<array<int, 2>>> adj(n);
	for(auto i = 0; i < m; ++ i){
		int u, v, x;
		cin >> u >> v >> x, -- u, -- v;
		adj[u].push_back({v, x});
		adj[v].push_back({u, x});
	}
	vector<int> res(n), was(n, -1), forced_zero(n);
	for(auto bit = 0; bit < 30; ++ bit){
		ranges::fill(forced_zero, false);
		for(auto u = 0; u < n; ++ u){
			for(auto [v, x]: adj[u]){
				if(~x & 1 << bit){
					forced_zero[u] = true;
					break;
				}
			}
		}
		for(auto u = 0; u < n; ++ u){
			for(auto [v, x]: adj[u]){
				if(x & 1 << bit && (forced_zero[v] || v < u && ~res[v] & 1 << bit)){
					res[u] |= 1 << bit;
					break;
				}
			}
			if(~res[u] & 1 << bit){
				for(auto [v, x]: adj[u]){
					if(x & 1 << bit){
						res[v] |= 1 << bit;
					}
				}
			}
		}
	}
	ranges::copy(res, ostream_iterator<int>(cout, " "));
	cout << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////