#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n;
		cin >> n;
		vector<long long> a(n);
		int cnt = 0;
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
			cnt += __builtin_ctzll(a[i]);
			a[i] >>= __builtin_ctzll(a[i]);
		}
		*max_element(a.begin(), a.end()) <<= cnt;
		cout << accumulate(a.begin(), a.end(), 0LL) << "\n";
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