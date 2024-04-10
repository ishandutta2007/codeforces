#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		string s;
		cin >> s;
		int n = 10, res = numeric_limits<int>::max();
		for(auto mask = 0; mask < 1 << n; ++ mask){
			bool fail = false;
			for(auto i = 0; i < n; ++ i){
				if(s[i] != '?' && (s[i] & 1) != (mask >> i & 1)){
					fail = true;
					break;
				}
			}
			if(fail){
				continue;
			}
			array<int, 2> cnt{}, rem{n / 2, n / 2};
			for(auto i = 0; i < n; ++ i){
				-- rem[i & 1];
				if(mask & 1 << i){
					++ cnt[i & 1];
				}
				if(i == n - 1 || cnt[i & 1] > cnt[~i & 1] + rem[~i & 1] || cnt[~i & 1] > cnt[i & 1] + rem[i & 1]){
					ctmin(res, i + 1);
					break;
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