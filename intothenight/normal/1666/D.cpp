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
		string s, t;
		cin >> s >> t;
		array<bool, 26> check{};
		for(auto i = (int)s.size() - 1; auto c: t | ranges::views::reverse){
			if(check[c - 'A']){
				cout << "NO\n";
				return 0;
			}
			while(i >= 0 && s[i] != c){
				check[s[i] - 'A'] = true;
				-- i;
			}
			if(i < 0){
				cout << "NO\n";
				return 0;
			}
			-- i;
		}
		cout << "YES\n";
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