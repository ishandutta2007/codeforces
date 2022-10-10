#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int x, d;
		cin >> x >> d;
		int cnt = 0;
		while(x % d == 0){
			x /= d;
			++ cnt;
		}
		auto prime = [&](int x)->bool{
			if(x == 1){
				return false;
			}
			for(auto p = 2; p * p <= x; ++ p){
				if(x % p == 0){
					return false;
				}
			}
			return true;
		};
		if(cnt == 1){
			cout << "NO\n";
			return 0;
		}
		// cnt >= 2
		if(prime(d) || cnt == 2){
			if(x == 1 || prime(x)){
				cout << "NO\n";
			}
			else{
				cout << "YES\n";
			}
			return 0;
		}
		// cnt >= 3
		if(prime(x) && cnt == 3 && 1LL * x * x == d){
			cout << "NO\n";
		}
		else{
			cout << "YES\n";
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
d = 4

4 4 4 (2)
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////