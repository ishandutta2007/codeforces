#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n;
		cin >> n;
		if(n % 4 == 0){
			cout << n / 4 << "\n";
		}
		else if(n % 4 == 1){
			if(n <= 5){
				cout << "-1\n";
			}
			else{
				cout << 1 + (n - 9) / 4 << "\n";
			}
		}
		else if(n % 4 == 2){
			if(n == 2){
				cout << "-1\n";
			}
			else{
				cout << 1 + (n - 6) / 4 << "\n";
			}
		}
		else{
			if(n <= 11){
				cout << "-1\n";
			}
			else{
				cout << 2 + (n - 15) / 4 << "\n";
			}
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
4, 6, 9, 10, 
mod4
0 -> n/4
1 -> 5: -1, 9: 1, 13: 2
2 -> 
3 -> 3, 7, 11, 15
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////