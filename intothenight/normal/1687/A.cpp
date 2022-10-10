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
		vector<long long> pref(n + 1);
		for(auto i = 0; i < n; ++ i){
			pref[i + 1] = pref[i] + a[i];
		}
		long long res = 0;
		for(auto i = 0; i + min(n, k) <= n; ++ i){
			res = max(res, pref[i + min(n, k)] - pref[i]);
		}
		if(n == 1){
			res += k - 1;
		}
		else if(k < n){
			res += 1LL * k * (k - 1) / 2;
		}
		else{
			res += 1 + (k - (n - 2) - 2) * 2;
			res += 1LL * (n - 2) * (n - 3) / 2 + 1LL * (n - 2) * (k - (n - 2));
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
k = 7, n = 5
3 2 1 2 3 4 5

0 1 2 2 4 5 6


1 2 1 2 3 4 5
0 1 2 2 4 5 6
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////