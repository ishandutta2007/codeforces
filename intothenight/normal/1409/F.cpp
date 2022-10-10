#include <bits/stdc++.h>
using namespace std;
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, k;
	string s, t;
	cin >> n >> k >> s >> t;
	// looking till i-th index, used x operations, j number of t[0]
	const int minf = numeric_limits<int>::min() / 2;
	vector dp(n, vector(k + 1, vector(n + 1, minf)));
	dp[0][0][s[0] == t[0]] = 0;
	if(k) dp[0][1][1] = dp[0][1][t[0] == t[1]] = 0;
	int res = minf;
	for(auto i = 1; i < n; ++ i){
		for(auto x = 0; x <= k; ++ x){
			for(auto j = 0; j <= n; ++ j){
				if(j >= (s[i] == t[0])){
					dp[i][x][j] = dp[i - 1][x][j - (s[i] == t[0])] + (j - (s[i] == t[0])) * (s[i] == t[1]);
				}
				if(x && j){
					ctmax(dp[i][x][j], dp[i - 1][x - 1][j - 1] + (j - 1) * (t[0] == t[1]));
				}
				if(x && j >= (t[0] == t[1])){
					ctmax(dp[i][x][j], dp[i - 1][x - 1][j - (t[0] == t[1])] + j - (t[0] == t[1]));
				}
				ctmax(res, dp[i][x][j]);
			}
		}
	}
	cout << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////