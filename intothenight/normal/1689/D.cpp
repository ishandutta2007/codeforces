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
		int n, m;
		cin >> n >> m;
		vector<string> a(n);
		copy_n(istream_iterator<string>(cin), n, a.begin());
		int smin = numeric_limits<int>::max();
		int smax = numeric_limits<int>::min();
		int dmin = numeric_limits<int>::max();
		int dmax = numeric_limits<int>::min();
		for(auto i = 0; i < n; ++ i){
			for(auto j = 0; j < m; ++ j){
				if(a[i][j] == 'B'){
					ctmin(smin, i + j);
					ctmax(smax, i + j);
					ctmin(dmin, i - j);
					ctmax(dmax, i - j);
				}
			}
		}
		int s = smin + smax >> 1, d = dmin + dmax >> 1;
		int ix = s + d >> 1, iy = s - d >> 1;
		array<int, 3> res{numeric_limits<int>::max()};
		for(auto x = ix - 1; x <= ix + 1; ++ x){
			for(auto y = iy - 1; y <= iy + 1; ++ y){
				if(min(x, y) < 0 || x >= n || y >= m){
					continue;
				}
				int cur = numeric_limits<int>::min();
				for(auto i = 0; i < n; ++ i){
					for(auto j = 0; j < m; ++ j){
						if(a[i][j] == 'B'){
							ctmax(cur, abs(i - x) + abs(j - y));
						}
					}
				}
				ctmin(res, array{cur, x, y});
			}
		}
		cout << res[1] + 1 << " " << res[2] + 1 << "\n";
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