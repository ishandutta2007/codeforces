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
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	const int inf = numeric_limits<int>::max() / 2;
	vector<vector<int>> dp(n + 1, vector<int>(3, inf)); // rest, sport, contest
	dp[0][0] = 0;
	for(auto i = 0; i < n; ++ i){
		dp[i + 1][0] = min({dp[i][0], dp[i][1], dp[i][2]}) + 1;
		if(a[i] >= 2) dp[i + 1][1] = min(dp[i][0], dp[i][2]);
		if(a[i] & 1) dp[i + 1][2] = min(dp[i][0], dp[i][1]);
	}
	cout << min({dp[n][0], dp[n][1], dp[n][2]});
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////