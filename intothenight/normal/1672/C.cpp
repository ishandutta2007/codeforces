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
		vector<int> a(n);
		int _eq = 0;
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
		}
		vector<int> eq(n - 1);
		for(auto i = 0; i < n - 1; ++ i){
			_eq += eq[i] = a[i] == a[i + 1];
		}
		if(_eq <= 1){
			cout << "0\n";
			return 0;
		}
		int l = 0, r = n - 2;
		while(!eq[l]){
			++ l;
		}
		while(!eq[r]){
			-- r;
		}
		cout << max(1, r - l - 1) << "\n";
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