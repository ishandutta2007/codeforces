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
	int n, p, k;
	cin >> n >> p >> k;
	vector<vector<int>> a(n, vector<int>(p + 2));
	for(int i = 0; i < n; ++ i){
		cin >> a[i][0];
	}
	for(int i = 0; i < n; ++ i){
		for(int j = 1; j <= p; ++ j){
			cin >> a[i][j];
		}
		a[i][p + 1] = i;
	}
	sort(a.begin(), a.end());
	const int mx = 1 << p;
	vector<vector<long long>> dp(n + 1, vector<long long>(mx));
	vector<vector<int>> prev(n + 1, vector<int>(mx));
	for(int i = 0; i < n; ++ i){
		for(int j = 0; j < mx; ++ j){
			int cnt = __builtin_popcount(j), rem = n - i;
			if(rem + cnt <= p + k){
				if(dp[i + 1][j] < dp[i][j] + a[i][0]){
					dp[i + 1][j] = dp[i][j] + a[i][0];
					prev[i + 1][j] = j;
				}
			}
			else{
				if(dp[i + 1][j] < dp[i][j]){
					dp[i + 1][j] = dp[i][j];
					prev[i + 1][j] = j;
				}
			}
			for(int bit = 0; bit < p; ++ bit){
				if(!(j & 1 << bit) && dp[i + 1][j ^ 1 << bit] < dp[i][j] + a[i][bit + 1]){
					dp[i + 1][j ^ 1 << bit] = dp[i][j] + a[i][bit + 1];
					prev[i + 1][j ^ 1 << bit] = j;
				}
			}
		}
	}
	vector<int> res(n, -1);
	for(int i = n - 1, mask = mx - 1, cnt = k; i >= 0; -- i){
		int pmask = prev[i + 1][mask];
		if(mask == pmask){
			if(cnt){
				res[a[i][p + 1]] = 0;
				-- cnt;
			}
		}
		else{
			res[a[i][p + 1]] = 1 + __lg(mask - pmask);
		}
		mask = pmask;
	}
	cout << dp[n][mx - 1];
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////