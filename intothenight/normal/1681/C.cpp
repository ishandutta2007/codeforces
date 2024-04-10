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
		vector<array<int, 2>> a(n);
		for(auto j = 0; j < 2; ++ j){
			for(auto i = 0; i < n; ++ i){
				cin >> a[i][j];
			}
		}
		vector<array<int, 2>> res;
		for(auto i = 0; i < n; ++ i){
			for(auto j = i + 1; j < n; ++ j){
				if(a[i] > a[j]){
					swap(a[i], a[j]);
					res.push_back({i, j});
				}
			}
		}
		for(auto i = 1; i < n; ++ i){
			if(a[i - 1][1] > a[i][1]){
				cout << "-1\n";
				return 0;
			}
		}
		cout << (int)res.size() << "\n";
		for(auto [i, j]: res){
			cout << i + 1 << " " << j + 1 << "\n";
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