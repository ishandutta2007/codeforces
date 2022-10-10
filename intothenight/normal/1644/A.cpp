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
		string s;
		cin >> s;
		vector<int> conv(300);
		conv['r'] = 0, conv['g'] = 1, conv['b'] = 2;
		array<int, 3> cnt{};
		for(auto c: s){
			if(islower(c)){
				++ cnt[conv[c]];
			}
			else{
				c = tolower(c);
				if(!cnt[conv[c]]){
					cout << "NO\n";
					return 0;
				}
			}
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