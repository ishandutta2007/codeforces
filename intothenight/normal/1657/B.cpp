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
		int n, b, x, y;
		cin >> n >> b >> x >> y;
		vector<int> a(n + 1);
		for(auto i = 1; i <= n; ++ i){
			if(a[i - 1] + x <= b){
				a[i] = a[i - 1] + x;
			}
			else{
				a[i] = a[i - 1] - y;
			}
		}
		cout << accumulate(a.begin(), a.end(), 0LL) << "\n";
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
1, 2, 3, 4, 
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////