#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		string s;
		cin >> s;
		reverse(s.begin(), s.end());
		int res = numeric_limits<int>::max();
		for(auto x: {"00", "52", "05", "57"}){
			int i = 0;
			while(i < (int)s.size() && s[i] != x[0]){
				++ i;
			}
			++ i;
			while(i < (int)s.size() && s[i] != x[1]){
				++ i;
			}
			++ i;
			res = min(res, i - 2);
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