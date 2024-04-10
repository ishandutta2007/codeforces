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
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for(auto i = n - k; i < n; ++ i){
			cin >> a[i];
		}
		for(auto i = n - 1; i > n - k; -- i){
			a[i] -= a[i - 1];
		}
		if(!ranges::is_sorted(a | ranges::views::drop(n - k + 1)) || k >= 2 && a[n - k] > 1LL * a[n - k + 1]  * (n - k + 1)){
			cout << "NO\n";
		}
		else{
			cout << "YES\n";
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