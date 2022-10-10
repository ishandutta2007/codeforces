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
		vector<vector<int>> a(n << 1, vector<int>(n << 1));
		long long res = 0;
		for(auto i = 0; i < n << 1; ++ i){
			for(auto j = 0; j < n << 1; ++ j){
				cin >> a[i][j];
				if((i < n) == (j < n)){
					res += a[i][j];
				}
			}
		}
		int extra = numeric_limits<int>::max();
		for(auto i: {0, n - 1, n, 2 * n - 1}){
			for(auto j: {0, n - 1, n, 2 * n - 1}){
				if((i < n) != (j < n)){
					ctmin(extra, a[i][j]);
				}
			}
		}
		cout << res + extra << "\n";
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