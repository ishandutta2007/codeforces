#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		long long n;
		int s;
		cin >> n >> s;
		auto calc = [&](){
			int sum = 0;
			for(auto x = n; x; x /= 10){
				sum += x % 10;
			}
			return sum;
		};
		long long res = 0;
		while(calc() > s){
			long long p = 1;
			while(n % (10 * p) == 0){
				p *= 10;
			}
			int q = n / p % 10;
			res += p * (10 - q);
			n += p * (10 - q);
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