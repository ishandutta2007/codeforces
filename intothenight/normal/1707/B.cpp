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
		vector<array<int, 2>> a;
		for(auto i = 0; i < n; ++ i){
			int x;
			cin >> x;
			if(a.empty() || a.back()[0] != x){
				a.push_back({x, 1});
			}
			else{
				++ a.back()[1];
			}
		}
		vector<array<int, 2>> b;
		while(n >= 2){
			b.clear();
			for(auto [x, freq]: a){
				if(freq >= 2){
					b.push_back({0, freq - 1});
				}
			}
			for(auto i = 0; i < (int)a.size() - 1; ++ i){
				b.push_back({a[i + 1][0] - a[i][0], 1});
			}
			ranges::sort(b);
			swap(a, b);
			b.clear();
			for(auto [x, freq]: a){
				if(b.empty() || x != b.back()[0]){
					b.push_back({x, freq});
				}
				else{
					b.back()[1] += freq;
				}
			}
			swap(a, b);
			-- n;
		}
		cout << a[0][0] << "\n";
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