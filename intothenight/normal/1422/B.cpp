#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n, m;
		cin >> n >> m;
		vector a(n, vector<int>(m));
		for(auto i = 0; i < n; ++ i){
			for(auto j = 0; j < m; ++ j){
				cin >> a[i][j];
			}
		}
		long long res = 0;
		for(auto i = 0; i < (n + 1) / 2; ++ i){
			for(auto j = 0; j < (m + 1) / 2; ++ j){
				if(2 * i + 1 == n && 2 * j + 1 == m){
					continue;
				}
				else if(2 * i + 1 == n){
					res += abs(a[i][j] - a[i][m - 1 - j]);
				}
				else if(2 * j + 1 == m){
					res += abs(a[i][j] - a[n - 1 - i][j]);
				}
				else{
					vector<int> cur{a[i][j], a[i][m - 1 - j], a[n - 1 - i][j], a[n - 1 - i][m - 1 - j]};
					sort(cur.begin(), cur.end());
					for(auto x: cur){
						res += abs(cur[1] - x);
					}
				}
			}
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