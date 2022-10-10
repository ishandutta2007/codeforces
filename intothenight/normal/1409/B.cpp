#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int a, b, x, y, n;
		cin >> a >> b >> x >> y >> n;
		if(a < b){
			swap(a, b), swap(x, y);
		}
		if(a + b - x - y <= n){
			cout << 1LL * x * y << "\n";
		}
		else{
			long long p, q;
			if(b - y >= n){
				p = 1LL * a * (b - n);
			}
			else{
				p = 1LL * (a - (n - (b - y))) * y;
			}
			if(a - x >= n){
				q = 1LL * b * (a - n);
			}
			else{
				q = 1LL * (b - (n - (a - x))) * x;
			}
			cout << min(p, q) << "\n";
		}
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
10 11 9 1 10

11 10 1 9 10
9 * 
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////