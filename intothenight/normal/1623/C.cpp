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
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
		}
		vector<long long> c(n);
		auto check = [&](int x)->bool{
			ranges::copy(a, begin(c));
			for(auto i = n - 1; i >= 2; -- i){
				if(c[i] < x){
					return false;
				}
				long long d = min<long long>((c[i] - x) / 3, a[i] / 3);
				c[i] -= d * 3;
				c[i - 1] += d;
				c[i - 2] += d * 2;
			}
			return c[0] >= x && c[1] >= x;
		};
		cout << *ranges::partition_point(ranges::iota_view(0, (int)2e9), check) - 1 << "\n";
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