#include <bits/stdc++.h>
using namespace std;
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	vector<long long> pref(n + 1);
	for(auto i = 0; i < n; ++ i){
		pref[i + 1] = pref[i] + a[i];
	}
	vector dp(n + 1, vector(k + 1, 0LL));
	for(auto i = 0; i < n; ++ i){
		for(auto j = 0; j <= k; ++ j){
			ctmax(dp[i + 1][j], dp[i][j]);
			if(i + m <= n && j < k){
				ctmax(dp[i + m][j + 1], dp[i][j] + pref[i + m] - pref[i]);
			}
		}
	}
	cout << dp[n][k] << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////