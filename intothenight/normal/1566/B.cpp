#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		string s;
		cin >> s;
		if(count(s.begin(), s.end(), '0') == 0){
			cout << "0\n";
			return 0;
		}
		if(count(s.begin(), s.end(), '1') == 0){
			cout << "1\n";
			return 0;
		}
		int l = 0, r = (int)s.size() - 1;
		while(s[l] == '1'){
			++ l;
		}
		while(s[r] == '1'){
			-- r;
		}
		if(count(s.begin() + l, s.begin() + r + 1, '0') == r - l + 1){
			cout << "1\n";
		}
		else{
			cout << "2\n";
		}
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