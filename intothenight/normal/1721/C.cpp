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
		vector<int> a(n), b(n);
		copy_n(istream_iterator<int>(cin), n, a.begin());
		copy_n(istream_iterator<int>(cin), n, b.begin());
		for(auto x: a){
			cout << *ranges::lower_bound(b, x) - x << " ";
		}
		cout << "\n";
		vector<int> flag(n);
		for(auto i = n - 1; i > 0; -- i){
			if(b[i - 1] >= a[i]){
				flag[i] = true;
			}
		}
		vector<int> reach(n);
		reach[n - 1] = n - 1;
		for(auto i = n - 2; i >= 0; -- i){
			if(flag[i + 1]){
				reach[i] = reach[i + 1];
			}
			else{
				reach[i] = i;
			}
		}
		for(auto i = 0; i < n; ++ i){
			cout << b[reach[i]] - a[i] << " ";
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