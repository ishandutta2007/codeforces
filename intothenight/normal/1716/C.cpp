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
		vector<vector<int>> a(2, vector<int>(n));
		for(auto &x: a | ranges::views::join){
			cin >> x, ++ x;
		}
		-- a[0][0];
		int res = numeric_limits<int>::max();
		for(auto t = 0; t < 2; ++ t){
			auto b = a[t];
			for(auto i = n - 1; i >= 0; -- i){
				b.push_back(a[!t][i]);
			}
			for(auto i = 0; i < n << 1; ++ i){
				b[i] -= i;
				if(i){
					ctmax(b[i], b[i - 1]);
				}
			}
			if(t == 0){
				int enter = 0;
				ctmin(res, 2 * n - 1 + b.back());
				for(auto pref = 2; pref <= n; pref += 2){
					int s = pref - 2 << 1;
					ctmax(enter, max({
						a[0][pref - 2] - s,
						a[1][pref - 2] - s - 1,
						a[1][pref - 1] - s - 2,
						a[0][pref - 1] - s - 3
					}));
					ctmin(res, 2 * n - 1 + max(enter, pref == n ? numeric_limits<int>::min() : b[2 * n - 1 - pref] - pref));
				}
			}
			else{
				int enter = 0;
				ctmax(enter, a[0][0]);
				ctmax(enter, a[1][0] - 1);
				ctmin(res, 2 * n - 1 + max(enter, b[2 * n - 2] - 1));
				for(auto pref = 3; pref <= n; pref += 2){
					int s = pref - 2 << 1;
					ctmax(enter, max({
						a[1][pref - 2] - s,
						a[0][pref - 2] - s - 1,
						a[0][pref - 1] - s - 2,
						a[1][pref - 1] - s - 3
					}));
					ctmin(res, 2 * n - 1 + max(enter, pref == n ? numeric_limits<int>::min() : b[2 * n - 1 - pref] - pref));
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