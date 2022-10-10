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
		int n;
		cin >> n;
		vector<int> a(n);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
		}
		long long res = numeric_limits<long long>::max() / 2;
		for(auto one = 0; one <= 2; ++ one){
			for(auto two = 0; two <= 2; ++ two){
				long long three = numeric_limits<long long>::min() / 2;
				for(auto w: a){
					long long three_local = numeric_limits<long long>::max() / 2;
					for(auto x = 0; x <= one; ++ x){
						for(auto y = 0; y <= two; ++ y){
							if(x + 2 * y <= w && (w - x - 2 * y) % 3 == 0){
								ctmin(three_local, (w - x - 2 * y) / 3);
							}
						}
					}
					ctmax(three, three_local);
				}
				ctmin(res, one + two + three);
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