#include "bits/stdc++.h"
using namespace std;
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	auto __solve_tc = [&](int __tc_num){
		int n;
		long long s;
		cin >> n >> s;
		vector<vector<array<int, 3>>> adj(n);
		for(auto i = 1; i < n; ++ i){
			int u, v, w, c;
			cin >> u >> v >> w >> c, -- u, -- v;
			adj[u].push_back({v, w, c}), adj[v].push_back({u, w, c});
		}
		vector<int> sz(n);
		multimap<long long, array<int, 2>, greater<>> mp1, mp2; // expected decrease, val, sz
		mp1.insert({0, {{}}}), mp2.insert({0, {{}}});
		long long tot = 0;
		function<void(int, int, int, int)> dfs_sz = [&](int u, int p, int pw, int pc){
			bool is_leaf = true;
			for(auto [v, w, c]: adj[u]){
				if(v ^ p){
					is_leaf = false;
					dfs_sz(v, u, w, c);
					sz[u] += sz[v];
				}
			}
			if(is_leaf){
				sz[u] = 1;
			}
			if(u ^ p){
				tot += 1LL * pw * sz[u];
				(pc == 1 ? mp1 : mp2).insert({1LL * (pw - pw / 2) * sz[u], {{pw, sz[u]}}});
			}
		};
		dfs_sz(0, 0, 0, 0);
		vector<long long> r1(20 * n + 1), r2(20 * n + 1);
		for(auto i = 1; i <= 20 * n; ++ i){
			auto [x, t] = *mp1.begin(); mp1.erase(mp1.begin());
			r1[i] = r1[i - 1] + x;
			t[0] >>= 1;
			mp1.insert({1LL * (t[0] - t[0] / 2) * t[1], t});
			auto [y, u] = *mp2.begin(); mp2.erase(mp2.begin());
			r2[i] = r2[i - 1] + y;
			u[0] >>= 1;
			mp2.insert({1LL * (u[0] - u[0] / 2) * u[1], u});
		}
		int res = numeric_limits<int>::max();
		for(auto i = 0; i <= 20 * n; ++ i){
			int j = lower_bound(r2.begin(), r2.end(), tot - s - r1[i]) - r2.begin();
			if(j <= 20 * n){
				ctmin(res, i + j * 2);
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