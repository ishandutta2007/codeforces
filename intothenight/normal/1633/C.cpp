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
		long long hc, dc, hm, dm, w, a;
		int k;
		cin >> hc >> dc >> hm >> dm >> k >> w >> a;
		for(auto x = 0; x <= k; ++ x){
			if((hm + dc + w * x - 1) / (dc + w * x) <= (hc + a * (k - x) + dm - 1) / dm){
				cout << "YES\n";
				return 0;
			}
		}
		cout << "NO\n";
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