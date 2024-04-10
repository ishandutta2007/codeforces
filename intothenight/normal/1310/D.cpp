#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::steady_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	vector<vector<int>> a(n, vector<int>(n));
	for(auto &s: a){
		for(auto &x: s){
			cin >> x;
		}
	}
	const int inf = 1e9;
	int REP = 5000, res = inf;
	vector<int> col(n), dp(n), dp_next(n);
	while(REP --){
		for(int u = 0; u < n; ++ u){
			col[u] = rng() & 1;
		}
		dp[0] = 0, dp_next[0] = inf;
		for(int i = 1; i < n; ++ i){
			dp[i] = dp_next[i] = inf;
		}
		for(int tt = 0; tt < k; ++ tt){
			for(int i = 0; i < n; ++ i){
				dp_next[i] = inf;
			}
			for(int i = 0; i < n; ++ i){
				for(int j = 0; j < n; ++ j){
					ctmin(dp_next[j], dp[i] + (col[i] == col[j] ? inf : a[i][j]));
				}
			}
			swap(dp, dp_next);
		}
		ctmin(res, dp[0]);
	}
	cout << res;
	return 0;
}

/*
10^4
----------
2
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////