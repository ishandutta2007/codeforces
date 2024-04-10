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
		int n;
		cin >> n;
		vector<int> a(n);
		copy_n(istream_iterator<int>(cin), n, a.begin());
		vector<vector<int>> pos(n);
		for(auto i = 0; i < n; ++ i){
			-- a[i];
			pos[a[i]].push_back(i);
		}
		vector<vector<int>> valid(n + 1, vector<int>(n + 1));
		for(auto i = 0; i <= n; ++ i){
			valid[i][i] = true;
			vector<int> cnt(n);
			int mxcnt = 0;
			for(auto j = i + 2; j <= n; j += 2){
				ctmax(mxcnt, ++ cnt[a[j - 2]]);
				ctmax(mxcnt, ++ cnt[a[j - 1]]);
				valid[i][j] = j - i >= mxcnt << 1;
			}
		}
		int res = 0;
		for(auto x = 0; x < n; ++ x){
			int m = (int)pos[x].size();
			vector<int> dp(m);
			for(auto i = 0; i < m; ++ i){
				if(valid[0][pos[x][i]]){
					dp[i] = 1;
				}
				for(auto j = 0; j < i; ++ j){
					if(dp[j] && valid[pos[x][j] + 1][pos[x][i]]){
						ctmax(dp[i], dp[j] + 1);
					}
				}
				if(dp[i] && valid[pos[x][i] + 1][n]){
					ctmax(res, dp[i]);
				}
			}
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