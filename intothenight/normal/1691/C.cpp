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
		string s;
		cin >> n >> k >> s;
		int i = n - 1;
		while(i >= 0 && s[i] == '0'){
			-- i;
		}
		if(i >= 0 && n - 1 - i <= k){
			rotate(s.begin() + i, s.begin() + i + 1, s.end());
			k -= n - 1 - i;
		}
		i = 0;
		while(i < n - 1 && s[i] == '0'){
			++ i;
		}
		if(i < n - 1 && i <= k){
			rotate(s.begin(), s.begin() + i, s.begin() + i + 1);
			k -= i;
		}
		int res = 0;
		for(auto i = 0; i < n - 1; ++ i){
			res += (s[i] - '0') * 10 + s[i + 1] - '0';
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