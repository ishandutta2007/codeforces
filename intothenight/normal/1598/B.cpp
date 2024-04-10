#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n;
		cin >> n;
		vector<vector<int>> a(n, vector<int>(5));
		for(auto i = 0; i < n; ++ i){
			for(auto j = 0; j < 5; ++ j){
				cin >> a[i][j];
			}
		}
		for(auto x = 0; x < 5; ++ x){
			for(auto y = x + 1; y < 5; ++ y){
				array<int, 4> cnt{};
				for(auto i = 0; i < n; ++ i){
					++ cnt[a[i][x] | a[i][y] << 1];
				}
				if(!cnt[0] && cnt[1] <= n / 2 && cnt[2] <= n / 2){
					cout << "YES\n";
					return 0;
				}
			}
		}
		cout << "NO\n";
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