#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n;
		cin >> n;
		vector<int> a(n);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
		}
		#ifdef LOCAL
		const int mx = 40;
		#else
		const int mx = 40;
		#endif
		int res = 2;
		vector<array<int, mx>> dp(n);
		for(auto i = 0; i < n; ++ i){
			fill(dp[i].begin(), dp[i].end(), -1);
		}
		vector<int> eqlen(n);
		for(auto i = 1; i < n; ++ i){
			if(a[i] == a[i - 1]){
				eqlen[i] = eqlen[i - 1] + 1;
			}
		}
		for(auto i = 1; i < n; ++ i){
			dp[i][2] = i - 1;
			for(auto len = 2; len < mx; ++ len){
				ctmax(dp[i][len], dp[i - 1][len]);
				if(int j = dp[i][len]; ~j){
					ctmax(res, len + eqlen[j]);
					int k = lower_bound(a.begin() + i + 1, a.end(), 2 * a[i] - a[j]) - a.begin(); 
					if(len + 1 < mx && k < n){
						ctmax(dp[k][len + 1], dp[i][len]);
					}
				}
			}
		}
		cout << n - res << "\n";
		return 0;
	};
	int __tc_cnt;
	cin >> __tc_cnt;
	for(auto __tc_num = 0; __tc_num < __tc_cnt; ++ __tc_num){
		__solve_tc(__tc_num);
	}
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////