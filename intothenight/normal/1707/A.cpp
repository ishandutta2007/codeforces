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
		int n, iq;
		cin >> n >> iq;
		vector<int> a(n);
		copy_n(istream_iterator<int>(cin), n, a.begin());
		int suff = *ranges::partition_point(ranges::iota_view(0, n + 1), [&](int suff){
			int rem = iq;
			for(auto i = n - suff; i < n; ++ i){
				if(!rem){
					return false;
				}
				if(a[i] > rem){
					-- rem;
				}
			}
			return true;
		}) - 1;
		for(auto i = 0; i < n - suff; ++ i){
			cout << (a[i] <= iq);
		}
		cout << string(suff, '1') << "\n";
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
5 2
5 1 2 4 3

(2, 0)
5
(1, 1), (2, 0)
1
(1, 2), (2, 1)
2
(0, 3), (1, 2), (2, 2)
4
(0, 4), (1, 3), (2, 3)
3
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////