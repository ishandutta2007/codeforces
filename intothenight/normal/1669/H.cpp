#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n, k;
		cin >> n >> k;
		array<int, 31> cnt{};
		for(auto i = 0; i < n; ++ i){
			int x;
			cin >> x;
			for(auto bit = 0; bit < 31; ++ bit){
				if(x & 1 << bit){
					++ cnt[bit];
				}
			}
		}
		int res = 0;
		for(auto bit = 30; bit >= 0; -- bit){
			if(n - cnt[bit] <= k){
				k -= n - cnt[bit];
				res |= 1 << bit;
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