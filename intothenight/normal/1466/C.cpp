#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	const int inf = numeric_limits<int>::max() / 2;
	auto __solve_tc = [&](int __tc_num){
		string s;
		cin >> s;
		int n = (int)s.size();
		if(n == 1){
			cout << "0\n";
			return 0;
		}
		array<vector<int>, 4> dp;
		for(auto mask = 0; mask < 4; ++ mask){
			dp[mask].assign(n, inf);
			dp[mask][1] = __builtin_popcount(mask);
			if(!mask && s[0] == s[1]){
				dp[0][1] = inf;
			}
		}
		for(auto i = 2; i < n; ++ i){
			for(auto mask = 0; mask < 8; ++ mask){
				bool ok = true;
				for(auto p = 0; p < 3; ++ p) if(~mask & 1 << p){
					for(auto q = p + 1; q < 3; ++ q) if(~mask & 1 << q){
						if(s[i - p] == s[i - q]){
							ok = false;
						}
					}
				}
				if(ok){
					ctmin(dp[mask & 3][i], dp[mask >> 1][i - 1] + (mask & 1));
				}
			}
		}
		int res = inf;
		for(auto mask = 0; mask < 4; ++ mask){
			ctmin(res, dp[mask][n - 1]);
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
bbbb
bbb
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////