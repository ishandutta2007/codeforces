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
		int n, m;
		cin >> n >> m;
		if(m < n){
			cout << "No\n";
			return 0;
		}
		if(n == m){
			cout << "Yes\n";
			for(auto i = 0; i < n; ++ i){
				cout << "1 ";
			}
			cout << "\n";
			return 0;
		}
		if(n & 1){
			cout << "Yes\n";
			for(auto i = 0; i < n - 1; ++ i){
				cout << "1 ";
			}
			cout << m - (n - 1) << "\n";
			return 0;
		}
		if(m & 1){
			cout << "No\n";
			return 0;
		}
		// n < m and n%2=0 and m%2=0
		cout << "Yes\n";
		for(auto i = 0; i < n - 2; ++ i){
			cout << "1 ";
		}
		for(auto i = 0; i < 2; ++ i){
			cout << (m - (n - 2)) / 2 << " ";
		}
		cout << "\n";
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