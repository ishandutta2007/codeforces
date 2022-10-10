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

void SOLVE(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	const int inf = numeric_limits<int>::max();
	vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(1 << n, vector<int>(n, inf)));
	vector<vector<vector<pair<int, int>>>> prev(n + 1, vector<vector<pair<int, int>>>(1 << n, vector<pair<int, int>>(n)));
	vector<int> sum(1 << n);
	for(auto mask = 1; mask < 1 << n; ++ mask){
		for(auto j = 0; j < n; ++ j){
			if(mask & 1 << j){
				sum[mask] += a[j];
			}
		}
		for(auto j = 0; j < n; ++ j){
			if(mask & 1 << j){
				dp[1][mask][j] = sum[mask];
				//cout << "dp[" << 1 << "][" << mask << "][" << j << "] = " << dp[1][mask][j] << "\n";
			}
		}
	}
	const int mx = (1 << n) - 1;
	for(auto i = 1; i < n; ++ i){
		for(auto mask = 0; mask < 1 << n; ++ mask){
			for(auto j = 0; j < n; ++ j){
				if(dp[i][mask][j] < inf){
					for(auto nmask = mx ^ mask; nmask; nmask = nmask - 1 & (mx ^ mask)){
						if(dp[i][mask][j] < sum[nmask] && nmask >> j){
							int k = j + __builtin_ctz(nmask >> j + 1) + 1;
							if(k < n && dp[i + 1][mask | nmask][k] > sum[nmask]){
								dp[i + 1][mask | nmask][k] = sum[nmask];
								prev[i + 1][mask | nmask][k] = {mask, j};
							}
						}
					}
				}
			}
		}
	}
	int x, y;
	for(auto i = n; i > 0; -- i){
		for(auto j = 0; j < n; ++ j){
			if(dp[i][(1 << n) - 1][j] != inf){
				tie(x, y) = {i, j};
				goto there;
			}
		}
	}
	there:;
	int cmask = (1 << n) - 1;
	vector<pair<int, int>> res;
	vector<int> rem(n);
	iota(rem.begin(), rem.end(), 0);
	while(x){
		auto [pmask, py] = prev[x][cmask][y];
		for(auto i = 0; i < n; ++ i){
			if((cmask ^ pmask) & 1 << i && i != y){
				res.emplace_back(lower_bound(rem.begin(), rem.end(), i) - rem.begin(), lower_bound(rem.begin(), rem.end(), y) - rem.begin());
				rem.erase(lower_bound(rem.begin(), rem.end(), i));
			}
		}
		-- x, cmask = pmask, y = py;
	}
	cout << int(res.size()) << "\n";
	for(auto [x, y]: res){
		cout << x + 1 << " " << y + 1 << "\n";
	}
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int ttt;
	cin >> ttt;
	while(ttt --){
		SOLVE();
	}
	return 0;
}

/*
dp[i][mask][j]: minimum last element when
1. forming an increasing sequence of length i
2. using mask elements
3. and last element originally at position j

2 1 3 5 1 2 4 5

2 1 3 5 5 2 x 5

2 1 3 5 10 2 x x

2 1 13 5 x 2 x x
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////