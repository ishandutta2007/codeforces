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
		int l, r;
		cin >> l >> r, ++ r;
		vector<int> a(r - l);
		copy_n(istream_iterator<int>(cin), r - l, a.begin());
		int res = 0;
		for(auto bit = 16; bit >= 0; -- bit){
			array<int, 2> cnt1{}, cnt2{};
			for(auto x = l; x < r; ++ x){
				++ cnt1[x >> bit & 1];
			}
			for(auto x: a){
				++ cnt2[x >> bit & 1];
			}
			if(cnt1 != cnt2){
				res |= 1 << bit;
				for(auto &x: a){
					x ^= 1 << bit;
				}
			}
		}
		ranges::sort(a);
		for(auto i = 0; i < r - l; ++ i){
			assert(a[i] == l + i);
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
1
2 5
6 0 1 7 
2

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////