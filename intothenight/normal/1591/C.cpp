#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
		}
		ranges::sort(a);
		long long res = numeric_limits<long long>::max();
		for(auto rep = 2; rep; -- rep){
			int p = ranges::lower_bound(a, 0) - begin(a);
			if(p < n){
				long long cur = a[n - 1];
				for(auto i = n - 1 - k; i >= p; i -= k){
					cur += a[i] * 2;
				}
				for(auto i = 0; i < p; i += k){
					cur += -a[i] * 2;
				}
				ctmin(res, cur);
			}
			for(auto &x: a) x = -x;
			ranges::reverse(a);
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