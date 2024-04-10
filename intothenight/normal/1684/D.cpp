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
		copy_n(istream_iterator<int>(cin), n, a.begin());
		vector<int> order(n);
		iota(order.begin(), order.end(), 0);
		ranges::stable_sort(order, [&](int i, int j){ return a[i] + i < a[j] + j; });
		vector<int> state(n);
		for(auto i: order | ranges::views::take(n - k)){
			state[i] = true;
		}
		long long res = 0;
		int delta = 0;
		for(auto i = 0; i < n; ++ i){
			if(state[i]){
				res += a[i] + delta;
			}
			else{
				++ delta;
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