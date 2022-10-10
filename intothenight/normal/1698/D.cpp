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
		auto query = [&](int l, int r)->bool{
			cout << "? " << l + 1 << " " << r << endl;
			int res = 0;
			for(auto i = 0; i < r - l; ++ i){
				int x;
				cin >> x;
				if(!~x){
					exit(0);
				}
				-- x;
				res += l <= x && x < r;
			}
			return res & 1;
		};
		int l = 0, r = n;
		while(r - l >= 2){
			int m = l + r >> 1;
			query(l, m) ? r = m : l = m;
		}
		cout << "! " << r << endl;
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