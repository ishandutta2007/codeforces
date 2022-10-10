#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n;
		cin >> n;
		array<int, 4> a;
		for(auto i = 0; i < 4; ++ i){
			cin >> a[i];
		}
		for(auto mask = 0; mask < 1 << 4; ++ mask){
			array<int, 4> b{};
			for(auto i = 0; i < 4; ++ i){
				if(mask & 1 << i){
					++ b[i], ++ b[(i + 1) % 4];
				}
			}
			for(auto i = 0; i < 4; ++ i){
				if(a[i] < b[i] || b[i] + n - 2 < a[i]){
					goto NEXT;
				}
			}
			cout << "YES\n";
			return 0;
			NEXT:;
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