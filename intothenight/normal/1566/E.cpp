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
		vector<vector<int>> adj(n);
		for(auto i = 0; i < n - 1; ++ i){
			int u, v;
			cin >> u >> v, -- u, -- v;
			adj[u].push_back(v), adj[v].push_back(u);
		}
		vector<int> deg(n);
		y_combinator([&](auto self, int u, int p)->void{
			for(auto v: adj[u]){
				if(v == p) continue;
				self(v, u);
				if(!deg[v]){
					++ deg[u];
				}
			}
		})(0, -1);
		int res = 1;
		for(auto u = 0; u < n; ++ u){
			if(deg[u]){
				res += deg[u] - 1;
			}
		}
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