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
	int n, h, l, r;
	cin >> n >> h >> l >> r;
	vector<int> a(n);
	copy_n(istream_iterator<int>(cin), n, a.begin());
	vector<vector<int>> dp(n + 1, vector<int>(h, -1));
	dp[0][0] = 0;
	auto inrange = [&](int t){
		return l <= t && t <= r;
	};
	for(int i = 0; i < n; ++ i){
		for(int t = 0; t < h; ++ t){
			if(dp[i][t] != -1){
				ctmax(dp[i + 1][(t + a[i]) % h], dp[i][t] + inrange((t + a[i]) % h));
				ctmax(dp[i + 1][(t + a[i] - 1) % h], dp[i][t] + inrange((t + a[i] - 1) % h));
			}
		}
	}
	cout << *max_element(dp[n].begin(), dp[n].end());
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////