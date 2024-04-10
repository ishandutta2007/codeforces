#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n, x, y;
		cin >> n >> x >> y;
		pair<int, vector<int>> res{numeric_limits<int>::max(), {}};
		for(auto s = 1; s <= min(x, y); ++ s){
			for(auto d = 1; d <= 50; ++ d){
				if((x - s) % d == 0 && (y - s) % d == 0 && max((x - s) / d, (y - s) / d) < n && res.first > s + d * (n - 1)){
					res.first = s + d * (n - 1);
					res.second.clear();
					for(auto i = 0; i < n; ++ i){
						res.second.push_back(s + i * d);
					}
				}
			}
		}
		for(auto x: res.second){
			cout << x << " ";
		}
		cout << "\n";
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