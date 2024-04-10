#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	vector<int> a(n);
	copy_n(istream_iterator<int>(cin), n, a.begin());
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
	function<int(int, int)> solve = [&](int l, int r)->int{
		if(dp[l][r] != -1){
			return dp[l][r];
		}
		if(l + 1 == r){
			return dp[l][r] = a[l];
		}
		for(int i = l + 1; i < r; ++ i){
			if(solve(l, i) == solve(i, r) && solve(l, i)){
				return dp[l][r] = solve(l, i) + 1;
			}
		}
		return dp[l][r] = 0;
	};
	solve(0, n);
	const int inf = numeric_limits<int>::max();
	vector<int> res(n + 1, inf);
	res[0] = 0;
	for(int i = 0; i < n; ++ i){
		for(int j = i + 1; j <= n; ++ j){
			if(dp[i][j]){
				ctmin(res[j], res[i] + 1);
			}
		}
	}
	cout << res[n];
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////