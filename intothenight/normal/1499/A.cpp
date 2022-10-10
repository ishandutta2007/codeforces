#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n, k1, k2, w, b;
		cin >> n >> k1 >> k2 >> w >> b;
		w <= min(k1 / 2 + (k2 + 1) / 2, (k1 + 1) / 2 + k2 / 2) && b <= min((n - k1) / 2 + (n - k2 + 1) / 2, (n - k1 + 1) / 2 + (n - k2) / 2) ? cout << "YES\n" : cout << "NO\n";
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