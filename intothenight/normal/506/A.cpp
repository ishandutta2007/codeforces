#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, d;
	cin >> n >> d;
	const int mx = 3e4;
	vector<int> gem(mx + 1);
	for(auto i = 0; i < n; ++ i){
		int x;
		cin >> x;
		++ gem[x];
	}
	int res = numeric_limits<int>::min();
	const int delta = 300;
	vector<vector<int>> dp(mx + 1, vector<int>(delta << 1, numeric_limits<int>::min()));
	dp[d][delta] = gem[d];
	for(auto x = d; x <= mx; ++ x){
		for(auto t = 0; t < delta << 1; ++ t){
			int jump = t + d - delta, profit = dp[x][t];
			if(jump <= 0 || profit < 0){
				continue;
			}
			if(mx < x + max(1, jump - 1)){
				ctmax(res, profit);
			}
			else{
				for(auto njump = max(1, jump - 1); njump <= jump + 1 && x + njump <= mx; ++ njump){
					ctmax(dp[x + njump][njump - d + delta], profit + gem[x + njump]);
				}
			}
		}
		dp[x].clear();
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