#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		string s;
		cin >> s;
		int cnt1 = 0, cnt2 = 0, res = 0;
		for(auto c: s){
			if(c == '('){
				++ cnt1;
			}
			else if(c == ')'){
				if(cnt1){
					++ res;
					-- cnt1;
				}
			}
			else if(c == '['){
				++ cnt2;
			}
			else{
				if(cnt2){
					++ res;
					-- cnt2;
				}
			}
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