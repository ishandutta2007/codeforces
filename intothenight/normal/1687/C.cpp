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
		vector<int> a(n), b(n);
		copy_n(istream_iterator<int>(cin), n, a.begin());
		copy_n(istream_iterator<int>(cin), n, b.begin());
		vector<vector<int>> adj(n + 1);
		for(auto i = 0; i < m; ++ i){
			int l, r;
			cin >> l >> r, -- l;
			adj[l].push_back(r);
			adj[r].push_back(l);
		}
		for(auto i = 0; i < n; ++ i){
			if(a[i] == b[i]){
				adj[i].push_back(i + 1);
				adj[i + 1].push_back(i);
			}
		}
		vector<long long> pref(n + 1);
		for(auto i = 0; i < n; ++ i){
			pref[i + 1] = pref[i] + a[i] - b[i];
		}
		if(pref[n]){
			cout << "NO\n";
			return 0;
		}
		vector<int> active(n + 1);
		set<int> inactive;
		for(auto i = 0; i <= n; ++ i){
			inactive.insert(i);
		}
		vector<int> init{0};
		for(auto l = 0; l < n; ){
			int r = l + 1;
			while(r < n && pref[l] != pref[r]){
				++ r;
			}
			init.push_back(r);
			l = r;
		}
		for(auto u: init){
			if(active[u]){
				continue;
			}
			y_combinator([&](auto self, int u)->void{
				active[u] = true;
				inactive.erase(u);
				for(auto v: adj[u]){
					if(active[v]){
						int l = min(u, v);
						int r = max(u, v);
						vector<int> update;
						for(auto it = inactive.lower_bound(l); it != inactive.end() && *it < r; ++ it){
							update.push_back(*it);
						}
						for(auto w: update){
							if(!active[w]){
								self(w);
							}
						}
					}
				}
			})(u);
		}
		accumulate(active.begin(), active.end(), 0) == n + 1 ? cout << "YES\n" : cout << "NO\n";
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