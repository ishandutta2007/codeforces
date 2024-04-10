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
		string s;
		cin >> n >> s;
		if(s[0] != '9'){
			for(auto c: s){
				cout << char('9' - c + '0');
			}
			cout << "\n";
		}
		else{
			string res(n, '?');
			for(auto i = n - 1, carry = 0; i >= 0; -- i){
				int ncarry = 0, x = 1 + carry, y = s[i] - '0';
				if(x < y){
					-- ncarry;
					x += 10;
				}
				res[i] = x - y + '0';
				carry = ncarry;
			}
			cout << res << "\n";
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