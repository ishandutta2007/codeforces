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
		int n, k;
		cin >> n >> k;
		vector<int> p(n, -1), s(n);
		vector<vector<int>> adj(n);
		for(auto u = 1; u < n; ++ u){
			cin >> p[u], -- p[u];
			adj[p[u]].push_back(u);
		}
		copy_n(istream_iterator<int>(cin), n, s.begin());
		vector<int> opt(n);
		y_combinator([&](auto self, int u)->void{
			for(auto v: adj[u]){
				self(v);
				opt[u] = max(opt[u], opt[v]);
			}
			opt[u] += s[u];
		})(0);
		long long res = 0;
		y_combinator([&](auto self, int u, int k)->int{
			res += 1LL * s[u] * k;
			if(adj[u].empty()){
				return s[u];
			}
			vector<int> b;
			for(auto v: adj[u]){
				b.push_back(self(v, k / (int)adj[u].size()));
			}
			k %= (int)adj[u].size();
			ranges::sort(b | ranges::views::reverse);
			for(auto i = 0; i < k; ++ i){
				res += b[i];
			}
			return s[u] + b[k];
		})(0, k);
		cout << res << "\n";
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