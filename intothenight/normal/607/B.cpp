#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	vector<vector<int>> dp(n + 1, vector<int>(n + 1, numeric_limits<int>::max() / 2));
	for(auto i = 0; i <= n; ++ i){
		dp[i][i] = 0;
	}
	for(auto i = 0; i < n; ++ i){
		dp[i][i + 1] = 1;
	}
	for(auto len = 2; len <= n; ++ len){
		for(auto i = 0; i <= n - len; ++ i){
			int j = i + len;
			ctmin(dp[i][j], dp[i + 1][j] + 1);
			for(auto k = i + 1; k < j; ++ k){
				if(a[i] == a[k]){
					ctmin(dp[i][j], max(dp[i + 1][k], 1) + dp[k + 1][j]);
				}
			}
		}
	}
	cout << dp[0][n] << "\n";
	return 0;
}

/*
7
1 4 4 2 3 2 1

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////