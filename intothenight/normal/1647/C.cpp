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
		int n, m;
		cin >> n >> m;
		vector<string> a(n);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
		}
		if(a[0][0] & 1){
			cout << "-1\n";
			return 0;
		}
		vector<array<int, 4>> res;
		for(auto i = n - 1; i >= 0; -- i){
			for(auto j = m - 1; j >= !i; -- j){
				if(a[i][j] & 1){
					if(i){
						res.push_back({i - 1, j, i, j});
					}
					else{
						res.push_back({i, j - 1, i, j});
					}
				}
				else{
					res.push_back({i, j, i, j});
				}
			}
		}
		cout << (int)res.size() << "\n";
		for(auto p: res){
			for(auto i = 0; i < 4; ++ i){
				cout << p[i] + 1 << " ";
			}
			cout << "\n";
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