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
		int n, m;
		cin >> n >> m;
		vector dp(n, vector(m, array{numeric_limits<int>::max(), numeric_limits<int>::min()}));
		for(auto i = 0; i < n; ++ i){
			for(auto j = 0; j < m; ++ j){
				int x;
				cin >> x;
				if(!i && !j){
					dp[i][j].fill(x);
					continue;
				}
				if(i){
					ctmin(dp[i][j][0], x + dp[i - 1][j][0]);
					ctmax(dp[i][j][1], x + dp[i - 1][j][1]);
				}
				if(j){
					ctmin(dp[i][j][0], x + dp[i][j - 1][0]);
					ctmax(dp[i][j][1], x + dp[i][j - 1][1]);
				}
			}
		}
		n + m & 1 && dp[n - 1][m - 1][0] <= 0 && dp[n - 1][m - 1][1] >= 0 ? cout << "YES\n" : cout << "NO\n";
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