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
		vector<int> a(n + 1);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i + 1];
			a[i + 1] += a[i];
		}
		for(auto i = n; i >= 0; -- i){
			int j = ranges::lower_bound(a, a[n] - a[i]) - a.begin();
			if(j <= n && a[j] == a[n] - a[i] && i <= j){
				cout << i + n - j << "\n";
				return 0;
			}
		}
		assert(false);
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