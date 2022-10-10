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
		string s;
		cin >> n >> s;
		if(auto x = ranges::count(s, '1'); x == 0 || x & 1){
			cout << "NO\n";
			return 0;
		}
		vector<int> id(n);
		iota(id.begin(), id.end(), 0);
		ranges::rotate(id, id.begin() + (ranges::find(s, '1') - s.begin()));
		ranges::rotate(s, ranges::find(s, '1'));
		vector<array<int, 2>> res;
		vector<int> pos;
		for(auto i = 0; i < n; ++ i){
			if(s[i] == '1'){
				pos.push_back(i);
			}
		}
		for(auto t = 1; t < (int)pos.size(); ++ t){
			vector<int> path{0};
			for(auto i = pos[t - 1] + 1; i <= pos[t]; ++ i){
				path.push_back(i);
			}
			for(auto i = 1; i < (int)path.size(); ++ i){
				res.push_back({path[i - 1], path[i]});
			}
		}
		auto [y, x] = res.back();
		res.pop_back();
		vector<int> path{x};
		for(auto i = pos.back() + 1; i < n; ++ i){
			path.push_back(i);
		}
		path.push_back(y);
		for(auto i = 1; i < (int)path.size(); ++ i){
			res.push_back({path[i - 1], path[i]});
		}
		cout << "YES\n";
		for(auto [i, j]: res){
			cout << id[i] + 1 << " " << id[j] + 1 << "\n";
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