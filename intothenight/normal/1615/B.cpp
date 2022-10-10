#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif
template<class T>
T &ctmin(T &x){
	return x;
}
template<class T, class Head, class ...Tail>
T &ctmin(T &x, const Head &h, const Tail &... t){
	return ctmin(x = min<T>(x, h), t...);
}
template<class T>
T &ctmax(T &x){
	return x;
}
template<class T, class Head, class ...Tail>
T &ctmax(T &x, const Head &h, const Tail &... t){
	return ctmax(x = max<T>(x, h), t...);
}



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int l, r;
		cin >> l >> r;
		int res = numeric_limits<int>::max();
		for(auto bit = 20; bit >= 0; -- bit){
			int x = l / (1 << bit);
			int y = r / (1 << bit);
			if(x != y){
				int a = l, b = r, cur = 0;
				if(~a & 1 << bit){
					cur += (a / (1 << bit) + 1) * (1 << bit) - a;
				}
				a = (a / (1 << bit) + 1) * (1 << bit);
				if(~b & 1 << bit){
					cur += b - (b / (1 << bit) * (1 << bit) - 1);
				}
				b = b / (1 << bit) * (1 << bit) - 1;
				if(a & 1 << bit){
					cur += (b / (1 << bit) - a / (1 << bit) + 1) / 2 * (1 << bit);
				}
				else{
					cur += (b / (1 << bit) - a / (1 << bit) + 2) / 2 * (1 << bit);
				}
				ctmin(res, cur);
			}
			else if(l & 1 << bit){
				res = 0;
				break;
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