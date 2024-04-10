#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"
#include "ext/pb_ds/tree_policy.hpp"
#include "ext/rope"
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
#define lambdify(x) [&](auto &&...args){ return x(forward<decltype(args)>(args)...); }
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<int> tot(3);
	for(auto i = 0; i < 3; ++ i){
		cin >> tot[i];
	}
	vector<vector<int>> adj(n);
	for(auto i = 0; i < m; ++ i){
		int u, v;
		cin >> u >> v, -- u, -- v;
		adj[u].push_back(v), adj[v].push_back(u);
	}
	vector<int> col(n, -1);
	vector<array<int, 2>> cnt;
	vector<vector<int>> comp;
	for(auto u = 0; u < n; ++ u){
		if(!~col[u]){
			function<void(int)> dfs = [&](int u){
				for(auto v: adj[u]){
					if(!~col[v]){
						col[v] = !col[u];
						++ cnt.back()[col[v]];
						comp.back().push_back(v);
						dfs(v);
					}
					else if(col[v] == col[u]){
						cout << "NO\n";
						exit(0);
					}
				}
			};
			col[u] = 0;
			cnt.push_back({1, 0});
			comp.push_back({u});
			dfs(u);
		}
	}
	vector<int> dp(n + 1);
	vector<vector<int>> prev(int(cnt.size()) + 1, vector<int>(n + 1));
	dp[0] = true;
	for(int i = 0; i < int(cnt.size()); ++ i){
		static vector<int> dp_next(n + 1);
		fill(dp_next.begin(), dp_next.end(), 0);
		for(int t = 0; t < 2; ++ t){
			for(auto j = 0; j <= n; ++ j){
				if(dp[j]){
					dp_next[j + cnt[i][t]] = true;
					prev[i + 1][j + cnt[i][t]] = t;
				}
			}
		}
		swap(dp, dp_next);
	}
	if(dp[tot[1]]){
		vector<int> res;
		int i = int(cnt.size()), j = tot[1];
		for(auto REP = 0; REP < int(cnt.size()); ++ REP){
			res.push_back(prev[i][j]);
			tie(i, j) = pair<int, int>{i - 1, j - cnt[i - 1][prev[i][j]]};
		}
		reverse(res.begin(), res.end());
		string ans(n, '2');
		for(auto i = 0; i < int(cnt.size()); ++ i){
			for(auto u: comp[i]){
				if(col[u] ^ res[i]){
					if(tot[0]){
						ans[u] = '1';
						-- tot[0];
					}
					else{
						ans[u] = '3';
					}
				}
			}
		}
		cout << "YES\n" << ans << "\n";
	}
	else{
		cout << "NO\n";
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