#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n;
		cin >> n;
		vector<int> a(n);
		vector<vector<int>> cnt(n + 1, vector<int>(n + 1));
		for(auto i = 0; i < n; ++ i){
			cin >> a[i], -- a[i];
			++ cnt[i + 1][a[i] + 1];
		}
		for(auto i = 0; i < n; ++ i){
			for(auto j = 0; j < n; ++ j){
				cnt[i + 1][j + 1] += cnt[i][j + 1] + cnt[i + 1][j] - cnt[i][j];
			}
		}
		long long res = 0;
		for(auto b = 0; b < n; ++ b){
			for(auto c = b + 1; c < n; ++ c){
				res += cnt[b][a[c]] * (cnt[n][a[b]] - cnt[c + 1][a[b]]);
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