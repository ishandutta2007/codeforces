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
	int n;
	cin >> n;
	vector<vector<int>> adj(n << 1);
	long long res = 0;
	auto count = [&](
		int left_lowerbound,
		int left_low,
		int left_high,
		int left_upperbound,
		int right_lowerbound,
		int right_low,
		int right_high,
		int right_upperbound
	)->long long{
		return 1LL * (left_low - left_lowerbound) * (left_upperbound - left_high) * (right_low - right_lowerbound) * (right_upperbound - right_high);
	};
	for(auto i = 0; i < n << 1; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		res += count(-1, u, u, n, n - 1, v, v, n * 2);
		adj[u].push_back(v), adj[v].push_back(u);
	}
	for(auto u = 0; u < n; ++ u){
		static vector<int> vis(n << 1);
		if(vis[u]){
			continue;
		}
		vector<int> cycle;
		y_combinator([&](auto self, int u)->void{
			vis[u] = true;
			cycle.push_back(u);
			for(auto v: adj[u]){
				if(!vis[v]){
					self(v);
				}
			}
		})(u);
		const int m = (int)cycle.size();
		assert(~m & 1);
		for(auto l = 0; l < m; ++ l){
			int left_low = numeric_limits<int>::max();
			int left_high = numeric_limits<int>::min();
			int right_low = numeric_limits<int>::max();
			int right_high = numeric_limits<int>::min();
			for(auto size = 0, i = l; size <= m - 2; ++ size, i = (i + 1) % m){
				int u = cycle[i];
				if(u < n){
					ctmin(left_low, u);
					ctmax(left_high, u);
				}
				else{
					ctmin(right_low, u);
					ctmax(right_high, u);
				}
				if(size & 1){
					bool bad = false;
					int left_lowerbound = -1;
					int left_upperbound = n;
					int right_lowerbound = n - 1;
					int right_upperbound = n * 2;
					for(auto u: {cycle[(l + m - 1) % m], cycle[(i + 1) % m]}){
						if(u < n){
							if(left_low <= u && u <= left_high){
								bad = true;
								break;
							}
							if(u < left_low){
								ctmax(left_lowerbound, u);
							}
							else{
								ctmin(left_upperbound, u);
							}
						}
						else{
							if(right_low <= u && u <= right_high){
								bad = true;
								break;
							}
							if(u < right_low){
								ctmax(right_lowerbound, u);
							}
							else{
								ctmin(right_upperbound, u);
							}
						}
					}
					if(!bad){
						res += count(
							left_lowerbound,
							left_low,
							left_high,
							left_upperbound,
							right_lowerbound,
							right_low,
							right_high,
							right_upperbound
						);
					}
				}
			}
		}
	}
	assert(~res & 1);
	cout << (res >> 1) << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////