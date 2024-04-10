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
		string s;
		cin >> n >> s;
		vector<int> a(n);
		copy_n(istream_iterator<int>(cin), n, a.begin());
		array<int, 2> dp{0, 0};
		for(auto i = 0, last = -1; i < n; ++ i){
			if(s[i] == '1'){
				dp = {
					max(dp[0], dp[1]) + a[i],
					max(dp[0] + (last + 1 < i ? a[i - 1] : numeric_limits<int>::min() / 2), dp[1] + (i > 0 ? a[i - 1] : numeric_limits<int>::min() / 2))
				};
				last = i;
			}
		}
		cout << max(dp[0], dp[1]) << "\n";
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