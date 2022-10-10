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
	auto __solve_tc = [&](auto __tc_num)->int{
		int n, m;
		cin >> n >> m;
		vector<array<int, 3>> edge(n - 1);
		vector<vector<array<int, 2>>> adj(n);
		for(auto &[u, v, w]: edge){
			cin >> u >> v >> w, -- u, -- v;
			if(~w){
				adj[u].push_back({v, __builtin_popcount(w) & 1});
				adj[v].push_back({u, __builtin_popcount(w) & 1});
			}
		}
		for(auto i = 0; i < m; ++ i){
			int u, v, p;
			cin >> u >> v >> p, -- u, -- v;
			adj[u].push_back({v, p});
			adj[v].push_back({u, p});
		}
		vector<int> color(n, -1);
		bool fail = false;
		for(auto u = 0; u < n; ++ u){
			if(!~color[u]){
				color[u] = 0;
				y_combinator([&](auto self, int u)->void{
					for(auto [v, w]: adj[u]){
						if(!~color[v]){
							color[v] = color[u] ^ w;
							self(v);
						}
						else if(color[u] ^ color[v] ^ w){
							fail = true;
						}
					}
				})(u);
			}
		}
		if(fail){
			cout << "NO\n";
			return 0;
		}
		cout << "YES\n";
		for(auto [u, v, w]: edge){
			if(!~w){
				w = color[u] ^ color[v];
			}
			cout << u + 1 << " " << v + 1 << " " << w << "\n";
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