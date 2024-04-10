#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int x = n % k, y = k - x, xlen = n / k + 1, ylen = n / k;
	vector dp(x + 1, vector<int>(y + 1, numeric_limits<int>::max()));
	dp[0][0] = 0;
	for(auto i = 0; i <= x; ++ i){
		for(auto j = 0; j <= y; ++ j){
			int cur = xlen * i + ylen * j;
			if(i < x){
				ctmin(dp[i + 1][j], dp[i][j] + a[cur + xlen - 1] - a[cur]);
			}
			if(j < y){
				ctmin(dp[i][j + 1], dp[i][j] + a[cur + ylen - 1] - a[cur]);
			}
		}
	}
	cout << dp[x][y] << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////