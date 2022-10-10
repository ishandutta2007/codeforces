#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	auto __solve_tc = [&](int __tc_num){
		int n, m;
		cin >> n >> m;
		vector<string> a(n);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
		}
		int res = 0;
		for(auto i = 0; i < n - 1; ++ i){
			res += a[i][m - 1] == 'R';
		}
		for(auto j = 0; j < m - 1; ++ j){
			res += a[n - 1][j] == 'D';
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