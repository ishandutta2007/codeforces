#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n, k;
		cin >> n >> k;
		if(n & 1){
			cout << n / 2 << " " << n / 2 << " " << 1 << "\n";
		}
		else if(n & 3){
			cout << 2 << " " << (n - 2) / 2 << " " << (n - 2) / 2 << "\n";
		}
		else{
			cout << n / 4 << " " << n / 4 << " " << n / 2 << "\n";
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