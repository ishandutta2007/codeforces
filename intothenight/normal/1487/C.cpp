#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n;
		cin >> n;
		vector<vector<int>> res(n, vector<int>(n));
		for(auto i = 0; i < n; ++ i){
			for(auto t = 1; t <= n - 1 >> 1; ++ t){
				res[i][(i + t) % n] = 1;
				res[(i + t) % n][i] = -1;
			}
		}
		for(auto i = 0; i < n; ++ i){
			for(auto j = i + 1; j < n; ++ j){
				cout << res[i][j] << " ";
			}
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