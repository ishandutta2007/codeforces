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
		long long x;
		cin >> x;
		if(x & 1 || x == 2){
			cout << "-1\n";
			return 0;
		}
		if(x % 6 == 0){
			cout << x / 6 << " ";
		}
		else if(x % 6 == 2){
			cout << 2 + (x - 8) / 6 << " ";
		}
		else{
			cout << 1 + (x - 4) / 6 << " ";
		}
		if(x % 4 == 0){
			cout << x / 4 << "\n";
		}
		else{
			cout << 1 + (x - 6) / 4 << "\n";
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

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////