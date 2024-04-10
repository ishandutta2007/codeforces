#include "bits/stdc++.h"
using namespace std;
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	array<int, 3> n;
	for(auto i = 0; i < 3; ++ i){
		cin >> n[i];
	}
	array<vector<int>, 3> a;
	for(auto i = 0; i < 3; ++ i){
		a[i].resize(n[i]);
		for(auto j = 0; j < n[i]; ++ j){
			cin >> a[i][j];
		}
		sort(a[i].begin(), a[i].end());
	}
	vector<vector<vector<int>>> dp(n[0] + 1, vector<vector<int>>(n[1] + 1, vector<int>(n[2] + 1)));
	for(auto i = 0; i <= n[0]; ++ i){
		for(auto j = 0; j <= n[1]; ++ j){
			for(auto k = 0; k <= n[2]; ++ k){
				if(i < n[0] && j < n[1]){
					ctmax(dp[i + 1][j + 1][k], dp[i][j][k] + a[0][i] * a[1][j]);
				}
				if(j < n[1] && k < n[2]){
					ctmax(dp[i][j + 1][k + 1], dp[i][j][k] + a[1][j] * a[2][k]);
				}
				if(k < n[2] && i < n[0]){
					ctmax(dp[i + 1][j][k + 1], dp[i][j][k] + a[2][k] * a[0][i]);
				}
			}
		}
	}
	cout << dp[n[0]][n[1]][n[2]] << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////