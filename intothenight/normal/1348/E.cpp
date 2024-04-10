#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	vector<array<int, 2>> a(n);
	long long tot = 0;
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < 2; ++ j){
			cin >> a[i][j];
			tot += a[i][j];
		}
	}
	vector<vector<int>> dp(n + 1, vector<int>(k));
	dp[0][0] = 1;
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j < k; ++ j){
			if(dp[i][j]){
				int rem = (a[i][0] + a[i][1]) % k;
				for(auto x = 0; x < min(k, a[i][0] + 1); ++ x){
					int y = (rem - x + k) % k;
					if(y <= a[i][1]){
						dp[i + 1][(j + x) % k] = 1;
					}
				}
			}
		}
	}
	long long res = 0;
	for(auto j = 0; j < k; ++ j){
		if(dp[n][j]){
			int jj = (tot - j) % k;
			ctmax(res, (tot - j - jj) / k);
		}
	}
	cout << res;
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////