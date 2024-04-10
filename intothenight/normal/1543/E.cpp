#include <bits/stdc++.h>
using namespace std;

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
		int n;
		cin >> n;
		vector<vector<array<int, 2>>> adj(1 << n);
		for(auto i = 0; i < n * (1 << n - 1); ++ i){
			int u, v;
			cin >> u >> v;
			adj[u].push_back({v, -1}), adj[v].push_back({u, -1});
		}
		for(auto u = 0; u < 1 << n; ++ u){
			sort(adj[u].begin(), adj[u].end());
		}
		vector<int> rp(1 << n);
		auto connected = [&](int u, int v)->bool{
			return binary_search(adj[u].begin(), adj[u].end(), array{v, 0}, [&](auto u, auto v){ return u[0] < v[0]; });
		};
		vector<int> was(1 << n, -1);
		for(auto i = 0; i < n; ++ i){
			vector<int> l, r;
			y_combinator([&](auto self, int u, int uu)->void{
				l.push_back(u), r.push_back(uu);
				was[u] = i, was[uu] = i;
				for(auto [v, w]: adj[u]){
					if(was[v] == i){
						continue;
					}
					for(auto [vv, ww]: adj[uu]){
						if(was[vv] == i){
							continue;
						}
						if(connected(v, vv)){
							self(v, vv);
							break;
						}
					}
				}
			})(0, adj[0][i][0]);
			sort(l.begin(), l.end());
			sort(r.begin(), r.end());
			for(auto u: r){
				rp[u] |= 1 << i;
			}
			for(auto u: l){
				for(auto &[v, w]: adj[u]){
					if(binary_search(r.begin(), r.end(), v)){
						assert(!~w);
						w = i;
					}
				}
			}
			for(auto u: r){
				for(auto &[v, w]: adj[u]){
					if(binary_search(l.begin(), l.end(), v)){
						assert(!~w);
						w = i;
					}
				}
			}
		}
		vector<int> p(1 << n);
		for(auto u = 0; u < 1 << n; ++ u){
			p[rp[u]] = u;
		}
		for(auto x: p){
			cout << x << " ";
		}
		cout << "\n";
		if(__builtin_popcount(n) != 1){
			cout << "-1\n";
			return 0;
		}
		vector<int> c(1 << n, -1);
		c[0] = 0;
		y_combinator([&](auto self, int u)->void{
			for(auto [v, w]: adj[u]){
				if(~c[v]) continue;
				assert(~w);
				c[v] = c[u] ^ w;
				self(v);
			}
		})(0);
		for(auto x: c){
			cout << x << " ";
		}
		cout << "\n";
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