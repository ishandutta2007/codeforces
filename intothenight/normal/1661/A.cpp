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
		long long res = 0;
		for(auto i = 1; i < n; ++ i){
			res += min(abs(a[i] - a[i - 1]) + abs(b[i] - b[i - 1]), abs(a[i] - b[i - 1]) + abs(b[i] - a[i - 1]));
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