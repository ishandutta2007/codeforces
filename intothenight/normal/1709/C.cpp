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
		int n = (int)s.size();
		int cnt = 0, balance = 0;
		for(auto c: s){
			if(c == '('){
				++ balance;
			}
			else if(c == ')'){
				-- balance;
			}
			else{
				++ cnt;
			}
			if(cnt && cnt - 2 + balance < 0){
				balance += cnt;
				cnt = 0;
			}
		}
		int x = cnt - balance >> 1;
		int y = cnt - x;
		!x || !y ? cout << "YES\n" : cout << "NO\n";
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
x - (cnt - x) + balance = 0;
x = cnt - bl
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////