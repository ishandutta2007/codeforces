#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n, k;
		cin >> n >> k;
		auto plus = [&](int x, int y)->int{
			array<int, 22> d;
			int sz = 0;
			while(x || y){
				d[sz ++] = ((x % k) + (y % k)) % k;
				x /= k, y /= k;
			}
			int res = 0;
			while(sz --){
				res = res * k + d[sz];
			}
			return res;
		};
		auto minus = [&](int x, int y)->int{
			array<int, 22> d;
			int sz = 0;
			while(x || y){
				d[sz ++] = ((x % k) - (y % k) + k) % k;
				x /= k, y /= k;
			}
			int res = 0;
			while(sz --){
				res = res * k + d[sz];
			}
			return res;
		};
		int alt_sum = 0;
		for(auto x = 0; x < n; ++ x){
			int y = x & 1 ? minus(alt_sum, x) : plus(alt_sum, x);
			cout << y << endl;
			int resp;
			cin >> resp;
			if(!~resp){
				exit(0);
			}
			if(resp){
				return 0;
			}
			alt_sum = minus(y, alt_sum);
		}
		assert(false);
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
3

3

2

0
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////