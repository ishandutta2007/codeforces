#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n;
		cin >> n;
		vector<int> excluded(n + 1), exclude;
		auto csqrt = [&](int x){
			int y = sqrt(x);
			while(y * y < x){
				++ y;
			}
			return y;
		};
		for(auto x = n; x > 2; x = csqrt(x)){
			excluded[x] = true;
			exclude.push_back(x);
		}
		exclude.push_back(2);
		vector<array<int, 2>> res;
		for(auto x = 3; x < n; ++ x){
			if(!excluded[x]){
				res.push_back({x, n});
			}
		}
		for(auto i = 1; i < (int)exclude.size(); ++ i){
			res.push_back({exclude[i - 1], exclude[i]});
			res.push_back({exclude[i - 1], exclude[i]});
		}
		cout << (int)res.size() << "\n";
		for(auto [x, y]: res){
			cout << x << " " << y << "\n";
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