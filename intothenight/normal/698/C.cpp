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
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	vector<double> p(n);
	int cnt = n;
	for(auto i = 0; i < n; ++ i){
		cin >> p[i];
		if(p[i] < 1e-9){
			-- cnt;
		}
	}
	k = ctmin(cnt, k);
	const int mx = 1 << n;
	vector<double> sum(mx);
	vector<vector<double>> dp(mx, vector<double>(n)); // probability of mask occupying first segment with u oldest
	for(auto mask = 0; mask < 1 << n; ++ mask){
		for(auto u = 0; u < n; ++ u){
			if(mask & 1 << u){
				sum[mask] += p[u];
			}
		}
	}
	vector<double> res(n);
	for(auto mask = 1; mask < 1 << n; ++ mask){
		if(__builtin_popcount(mask) == 1){
			dp[mask][__lg(mask)] = p[__lg(mask)];
		}
		for(auto u = 0; u < n; ++ u){
			if(mask & 1 << u){
				dp[mask][u] /= (1 - sum[mask ^ 1 << u]);
				for(auto v = 0; v < n; ++ v){
					if(!(mask & 1 << v)){
						dp[mask | 1 << v][u] += dp[mask][u] * p[v];
					}
				}
			}
		}
		if(__builtin_popcount(mask) <= k){
			for(auto u = 0; u < n; ++ u){
				if(mask & 1 << u){
					res[u] += dp[mask][u];
				}
			}
		}
	}
	cout << fixed << setprecision(15);
	for(auto p: res){
		cout << p << " ";
	}
	cout << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////