#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	auto __solve_tc = [&](int __tc_num){
		int n;
		cin >> n;
		string a;
		for(auto i = 0; i < n; ++ i){
			a.append("1001");
		}
		for(auto i = 0; i < n; ++ i){
			if(i % 4 != 3){
				a[4 * n - 1 - i] = '0';
			}
		}
		for(auto i = 0; i < n; ++ i){
			int cur = 0;
			for(auto j = 0; j < 4; ++ j){
				if(a[4 * i + (3 - j)] == '1'){
					cur += 1 << j;
				}
			}
			cout << cur;
		}
		cout << "\n";
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