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
		int n, x, y;
		string s, t;
		cin >> n >> x >> y >> s >> t;
		x = min(x, 2 * y);
		vector<int> a(n), pos;
		for(auto i = 0; i < n; ++ i){
			a[i] = s[i] != t[i];
			if(a[i]){
				pos.push_back(i);
			}
		}
		if((int)pos.size() & 1){
			cout << "-1\n";
			return 0;
		}
		if(x >= y){
			long long res = 0;
			for(auto i = 0; i < (int)pos.size() / 2; ++ i){
				res += pos[i] + 1 == pos[i + (int)pos.size() / 2] ? x : y;
			}
			cout << res << "\n";
		}
		else{ // x < y
			n = (int)pos.size();
			const long long inf = numeric_limits<long long>::max() / 2;
			auto get = [&](int l, int r)->int{
				assert(l < r);
				return l + 1 == r ? x : min<long long>(1LL * (r - l) * x, y);
			};
			vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, inf));
			dp[0][0] = 0;
			for(auto i = 0; i < n; ++ i){
				for(auto x = 0; x <= i + 1; ++ x){
					if(x){
						ctmin(dp[i + 1][x], dp[i][x - 1]);
					}
					if(i){
						ctmin(dp[i + 1][x], dp[i - 1][x] + get(pos[i - 1], pos[i]));
					}
				}
			}
			long long res = inf;
			for(auto x = 0; x <= n; ++ x){
				if(x & 1){
					assert(dp[n][x] == inf);
				}
				else{
					ctmin(res, dp[n][x] + 1LL * (x >> 1) * y);
				}
			}
			cout << res << "\n";
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