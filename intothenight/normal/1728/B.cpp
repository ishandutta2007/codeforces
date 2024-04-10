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
		int n;
		cin >> n;
		if(n == 4){
			cout << "2 1 3 4\n";
			return 0;
		}
		int x = 0;
		for(auto i = 4; i <= n - 2; ++ i){
			cout << i << " ";
			if(x < i){
				x += i;
			}
			else{
				x = 0;
			}
		}
		if(x){
			cout << "3 2 1 ";
		}
		else{
			cout << "2 3 1 ";
		}
		cout << n - 1 << " " << n << "\n";
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