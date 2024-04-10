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
	const int mx = 51;
	vector<vector<int>> dp(mx, vector<int>(mx, numeric_limits<int>::max() / 2));
	dp[0][0] = 0;
	auto is_square = [&](int x)->int{
		int y = sqrt(x);
		while((y + 1) * (y + 1) <= x){
			++ y;
		}
		return y * y == x;
	};
	for(auto x = 0; x < mx; ++ x){
		for(auto y = 0; y < mx; ++ y){
			for(auto px = 0; px <= x; ++ px){
				for(auto py = 0; py <= y; ++ py){
					if((px < x || py < y) && is_square((x - px) * (x - px) + (y - py) * (y - py))){
						ctmin(dp[x][y], dp[px][py] + 1);
					}
				}
			}
		}
	}
	auto __solve_tc = [&](auto __tc_num)->int{
		int x, y;
		cin >> x >> y;
		cout << dp[x][y] << "\n";
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