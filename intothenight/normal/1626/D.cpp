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
		int n;
		cin >> n;
		vector<int> pref(n + 1);
		for(auto i = 0; i < n; ++ i){
			int x;
			cin >> x;
			++ pref[x];
		}
		for(auto x = 0; x < n; ++ x){
			pref[x + 1] += pref[x];
		}
		int res = numeric_limits<int>::max();
		auto eval = [&](int size)->int{
			return size ? size == 1 ? 0 : (1 << __lg(size - 1) + 1) - size : 1;
		};
		for(auto x = 0; x <= n; ++ x){
			for(auto bit = 0; bit < 20; ++ bit){
				int middle = 1 << bit;
				auto ok = [&](int y)->bool{
					return pref[y] - pref[x] <= middle;
				};
				int y = *ranges::partition_point(ranges::iota_view(x + 1, n + 1), ok) - 1;
				ctmin(res, eval(pref[x]) + eval(pref[y] - pref[x]) + eval(pref[n] - pref[y]));
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