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
		int n;
		cin >> n;
		cout << *ranges::partition_point(ranges::iota_view(1, (int)1e9), [&](int x){
			array<int, 3> a{x / 3, x / 3, x / 3};
			for(auto r = 0; r < x % 3; ++ r){
				++ a[r];
			}
			long long cur = 0;
			for(auto i = 0; i < 3; ++ i){
				cur += 2LL * a[i] * a[(i + 1) % 3];
			}
			return cur < n;
		}) << "\n";
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