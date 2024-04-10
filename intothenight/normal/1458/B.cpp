#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	cout << fixed << setprecision(15);
	int n;
	cin >> n;
	const int mx = 1e4;
	vector dp(n + 1, vector(mx + 1, numeric_limits<int>::min()));
	dp[0][0] = 0;
	int tot = 0;
	for(auto rep = 0; rep < n; ++ rep){
		int a, b;
		cin >> a >> b;
		tot += b;
		for(auto i = n - 1; i >= 0; -- i){
			for(auto x = mx - a; x >= 0; -- x){
				if(dp[i][x] != numeric_limits<int>::min()){
					ctmax(dp[i + 1][x + a], dp[i][x] + b);
				}
			}
		}
	}
	for(auto i = 1; i <= n; ++ i){
		double res = numeric_limits<double>::min();
		for(auto x = 0; x <= mx; ++ x){
			if(dp[i][x] != numeric_limits<int>::min()){
				ctmax(res, min<double>(dp[i][x] + (tot - dp[i][x]) / 2.0, x));
			}
		}
		cout << res << " ";
	}
	cout << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////