#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif
template<class T> T &ctmin(T &x){ return x; }
template<class T, class Head, class ...Tail> T &ctmin(T &x, const Head &h, const Tail &... t){ return ctmin(x = min<T>(x, h), t...); }
template<class T> T &ctmax(T &x){ return x; }
template<class T, class Head, class ...Tail> T &ctmax(T &x, const Head &h, const Tail &... t){ return ctmax(x = max<T>(x, h), t...); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n, delta;
		cin >> n >> delta;
		vector<int> a(n);
		vector<long long> pref(n + 1);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
			pref[i + 1] = pref[i] + a[i];
		}
		vector<long long> opt(n + 1, numeric_limits<long long>::min());
		for(auto len = 0; len <= n; ++ len){
			for(auto l = 0; l + len <= n; ++ l){
				ctmax(opt[len], pref[l + len] - pref[l]);
			}
		}
		for(auto k = 0; k <= n; ++ k){
			long long res = 0;
			for(auto i = 0; i <= n; ++ i){
				ctmax(res, opt[i] + 1LL * min(k, i) * delta);
			}
			cout << res << " ";
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