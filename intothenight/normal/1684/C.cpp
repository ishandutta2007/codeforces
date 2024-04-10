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
		vector<vector<int>> a(n, vector<int>(m));
		for(auto &x: ranges::views::join(a)){
			cin >> x;
		}
		vector<int> res;
		for(auto i = 0; i < n; ++ i){
			auto b = a[i];
			ranges::sort(b);
			vector<int> dif;
			for(auto j = 0; j < m; ++ j){
				if(a[i][j] != b[j]){
					dif.push_back(j);
				}
			}
			if((int)dif.size() > 2){
				cout << "-1\n";
				return 0;
			}
			assert((int)dif.size() != 1);
			if((int)dif.size() == 2){
				res = dif;
			}
		}
		if(res.empty()){
			res = {0, 0};
		}
		for(auto i = 0; i < n; ++ i){
			swap(a[i][res[0]], a[i][res[1]]);
			if(!ranges::is_sorted(a[i])){
				cout << "-1\n";
				return 0;
			}
		}
		cout << res[0] + 1 << " " << res[1] + 1 << "\n";
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