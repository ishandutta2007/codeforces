#include <bits/stdc++.h>
using namespace std;
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	auto __solve_tc = [&](int __tc_num){
		int n;
		string s;
		cin >> n >> s;
		static const vector<string> trans{"RL", "RRL", "RLL", "RRLL"};
		static const vector<int> len{2, 3, 3, 4};
		static const int inf = numeric_limits<int>::max() / 2;
		int res = inf;
		for(auto rep = 0; rep < 5; ++ rep){
			rotate(s.begin(), s.begin() + 1, s.end());
			int cur = 0;
			vector<int> dp(n + 1, inf);
			dp[0] = 0;
			for(auto i = 0; i < n; ++ i){
				for(auto t = 0; t < 4; ++ t){
					if(i + len[t] <= n){
						int dif = 0;
						for(auto j = 0; j < len[t]; ++ j){
							dif += s[i + j] != trans[t][j];
						}
						ctmin(dp[i + len[t]], dp[i] + dif);
					}
				}
			}
			ctmin(res, dp[n]);
		}
		cout << res << "\n";
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