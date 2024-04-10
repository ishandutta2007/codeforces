#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif
template<class T> T &ctmin(T &x){ return x; }
template<class T, class Head, class ...Tail> T &ctmin(T &x, const Head &h, const Tail &... t){ return ctmin(x = min<T>(x, h), t...); }
template<class T> T &ctmax(T &x){ return x; }
template<class T, class Head, class ...Tail> T &ctmax(T &x, const Head &h, const Tail &... t){ return ctmax(x = max<T>(x, h), t...); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		string s;
		cin >> s;
		int n = (int)s.size();
		vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
		for(auto i = 0; i <= n; ++ i){
			dp[i][i] = 0;
		}
		for(auto len = 2; len <= n; len += 2){
			for(auto i = 0; i + len <= n; ++ i){
				int j = i + len;
				{
					if(
						(
							dp[i + 2][j] == 1 ||
							dp[i + 2][j] == 0 && s[i] > s[i + 1]
						) && (
							dp[i + 1][j - 1] == 1 ||
							dp[i + 1][j - 1] == 0 && s[i] > s[j - 1]
						)
					){
						ctmax(dp[i][j], 1);
					}
					else if(
						dp[i + 2][j] == 0 && s[i] == s[i + 1] ||
						dp[i + 1][j - 1] == 0 && s[i] == s[j - 1]
					){
						ctmax(dp[i][j], 0);
					}
				}
				{
					if(
						(
							dp[i][j - 2] == 1 ||
							dp[i][j - 2] == 0 && s[j - 1] > s[j - 2]
						) && (
							dp[i + 1][j - 1] == 1 ||
							dp[i + 1][j - 1] == 0 && s[j - 1] > s[i]
						)
					){
						ctmax(dp[i][j], 1);
					}
					else if(
						dp[i][j - 2] == 0 && s[j - 1] == s[j - 2] ||
						dp[i + 1][j - 1] == 0 && s[j - 1] == s[i]
					){
						ctmax(dp[i][j], 0);
					}
				}
			}
		}
		if(dp[0][n] == 1){
			cout << "Alice\n";
		}
		else if(dp[0][n] == 0){
			cout << "Draw\n";
		}
		else{
			cout << "Bob\n";
		}
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