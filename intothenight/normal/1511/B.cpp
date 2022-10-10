#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int a, b, c;
		cin >> a >> b >> c;
		auto sz = [&](int x){
			int res = 0;
			while(x){
				x /= 10;
				++ res;
			}
			return res;
		};
		int x = 2, y = 3;
		while(sz(x) < a - c + 1){
			x *= 2;
		}
		while(sz(y) < b - c + 1){
			y *= 3;
		}
		for(auto rep = 0; rep < c - 1; ++ rep){
			x *= 10;
			y *= 10;
		}
		cout << x << " " << y << "\n";
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