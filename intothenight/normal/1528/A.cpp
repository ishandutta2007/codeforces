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

template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n;
		cin >> n;
		vector<int> l(n), r(n);
		for(auto u = 0; u < n; ++ u){
			cin >> l[u] >> r[u];
		}
		vector<vector<int>> adj(n);
		for(auto i = 0; i < n - 1; ++ i){
			int u, v;
			cin >> u >> v, -- u, -- v;
			adj[u].push_back(v), adj[v].push_back(u);
		}
		vector<array<long long, 2>> dp(n);
		y_combinator([&](auto self, int u, int p)->void{
			for(auto v: adj[u]){
				if(v == p) continue;
				self(v, u);
				dp[u] = {
					dp[u][0] + max(dp[v][0] + abs(l[v] - l[u]), dp[v][1] + abs(r[v] - l[u])),
					dp[u][1] + max(dp[v][0] + abs(l[v] - r[u]), dp[v][1] + abs(r[v] - r[u]))
				};
			}
		})(0, -1);
		cout << max(dp[0][0], dp[0][1]) << "\n";
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