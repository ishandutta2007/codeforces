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
		copy_n(istream_iterator<int>(cin), n, a.begin());
		int res = numeric_limits<int>::max();
		for(auto i = 0; i < n; ++ i){
			for(auto j = i + 1; j < n; ++ j){
				for(auto k = j + 1; k < n; ++ k){
					int x = a[i] - max({a[i], a[j], a[k]}) + a[j] - min({a[i], a[j], a[k]}) + a[k];
					res = min(res, abs(x - a[i]) + abs(x - a[j]) + abs(x - a[k]));
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