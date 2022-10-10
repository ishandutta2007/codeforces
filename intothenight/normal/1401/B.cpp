#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	auto __solve_tc = [&](int __tc_num){
		array<int, 3> cnta{}, cntb{};
		for(auto i = 0; i < 3; ++ i){
			cin >> cnta[i];
		}
		for(auto i = 0; i < 3; ++ i){
			cin >> cntb[i];
		}
		int x = min(cnta[2], cntb[1]), res = 2 * x;
		cnta[2] -= x, cntb[1] -= x;
		x = min(cnta[1], cntb[0]);
		cnta[1] -= x, cntb[0] -= x;
		if(cnta[1]){
			x = min(cnta[1], cntb[1]);
			cnta[1] -= x, cntb[1] -= x;
			if(cnta[1]){
				res -= 2 * cnta[1];
			}
		}
		cout << res << "\n";
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