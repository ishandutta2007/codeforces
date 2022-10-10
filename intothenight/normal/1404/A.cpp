#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n, k;
		string s;
		cin >> n >> k >> s;
		for(auto rem = 0; rem < k; ++ rem){
			bool zero = false, one = false;
			for(auto i = rem; i < n; i += k){
				if(s[i] == '0'){
					zero = true;
				}
				else if(s[i] == '1'){
					one = true;
				}
			}
			if(zero && one){
				cout << "NO\n";
				return 0;
			}
			if(zero || one){
				for(auto i = rem; i < n; i += k){
					s[i] = one + '0';
				}
			}
		}
		int zero = 0, one = 0;
		for(auto i = 0; i < k; ++ i){
			if(s[i] == '0'){
				++ zero;
			}
			else if(s[i] == '1'){
				++ one;
			}
		}
		max(zero, one) * 2 > k ? cout << "NO\n" : cout << "YES\n";
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