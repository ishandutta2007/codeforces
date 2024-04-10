#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int l, r;
		cin >> l >> r;
		array<int, 11> cnt{};
		for(auto len = 0, obj = 0; len <= 9; ++ len){
			obj = max(1, obj * 10);
			cnt[len] = r / obj - l / obj;
		}
		long long res = 0;
		for(auto len = 0; len <= 9; ++ len){
			cnt[len] -= cnt[len + 1];
			res += cnt[len] * (len + 1);
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