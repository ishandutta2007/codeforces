#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n, k;
		cin >> n >> k;
		vector<array<int, 2>> a(n);
		for(auto i = 0; i < n; ++ i){
			for(auto j = 0; j < 2; ++ j){
				cin >> a[i][j];
			}
		}
		for(auto p: a){
			if(all_of(a.begin(), a.end(), [&](auto q){ return abs(p[0] - q[0]) + abs(p[1] - q[1]) <= k; })){
				cout << "1\n";
				return 0;
			}
		}
		cout << "-1\n";
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