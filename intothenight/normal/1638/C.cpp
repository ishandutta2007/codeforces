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
		vector<array<int, 2>> res;
		for(auto i = 0; i < n; ++ i){
			int x;
			cin >> x;
			int l = x, r = x + 1;
			while(!res.empty() && l < res.back()[1]){
				l = min(l, res.back()[0]);
				r = max(r, res.back()[1]);
				res.pop_back();
			}
			res.push_back({l, r});
		}
		cout << (int)res.size() << "\n";
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