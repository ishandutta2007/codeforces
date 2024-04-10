#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n;
		string s;
		cin >> n >> s;
		if(s == string(n, '1')){
			cout << "DRAW\n";
			return 0;
		}
		auto rs = s;
		reverse(rs.begin(), rs.end());
		if(n & 1){
			if(s[n >> 1] & 1){
				cout << "BOB\n";
			}
			else if(count(s.begin(), s.end(), '0') == 1){
				cout << "BOB\n";
			}
			else{
				cout << "ALICE\n";
			}
		}
		else{
			cout << "BOB\n";
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