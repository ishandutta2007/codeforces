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
		array<int, 26> cnt0{}, cnt1{};
		array<array<int, 26>, 26> cnt2{};
		long long res = 0;
		for(auto i = 0; i < n; ++ i){
			string s;
			cin >> s;
			res += cnt0[s[0] - 'a'] + cnt1[s[1] - 'a'] - 2 * cnt2[s[0] - 'a'][s[1] - 'a'];
			++ cnt0[s[0] - 'a'];
			++ cnt1[s[1] - 'a'];
			++ cnt2[s[0] - 'a'][s[1] - 'a'];
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