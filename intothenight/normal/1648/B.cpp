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
		int n, c;
		cin >> n >> c;
		vector<int> appear(c + 1), pref(c + 2);
		for(auto i = 0; i < n; ++ i){
			int x;
			cin >> x;
			appear[x] = true;
			pref[x + 1] = 1;
		}
		for(auto x = 0; x <= c; ++ x){
			pref[x + 1] += pref[x];
		}
		for(auto y = 1; y <= c; ++ y){
			if(appear[y]){
				for(auto x = y; x <= c; x += y){
					if(pref[min(x + y, c + 1)] - pref[x] && !appear[x / y]){
						cout << "No\n";
						return 0;
					}
				}
			}
		}
		cout << "Yes\n";
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