#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	auto __solve_tc = [&](int __tc_num){
		int m, d, w;
		cin >> m >> d >> w;
		int t = w / gcd(w, d - 1), s = (min(m, d) - 1) / t;
		cout << 1LL * s * min(m, d) - 1LL * s * (s + 1) / 2 * t << "\n";
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
0 <= x < y <= min(m, d) - 1

(x * d + y) % w == (y * d + x) % w
(x-y) * (d-1) == 0 mod w
x - y is a multiple of t = w / gcd(w, d-1), s = (min(m, d) - 1) / t

sum{i=1 ~ s}( min(m, d) - i * t )
= s * min(m, d) - t * s * (s + 1) / 2;
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////