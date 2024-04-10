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
		vector<array<int, 2>> a(n);
		for(auto &[l, r]: a){
			cin >> l >> r, ++ r;
		}
		ranges::sort(a, [&](auto x, auto y){ return x[1] - x[0] > y[1] - y[0]; });
		for(auto [l, r]: a){
			if(r - l == 1){
				cout << l << " " << r - 1 << " " << l << "\n";
			}
			else{
				for(auto [ll, rr]: a){
					if((l != ll || r != rr) && l <= ll && rr <= r){
						if(l == ll){
							cout << l << " " << r - 1 << " " << rr << "\n";
						}
						else{
							cout << l << " " << r - 1 << " " << ll - 1 << "\n";
						}
						break;
					}
				}
			}
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