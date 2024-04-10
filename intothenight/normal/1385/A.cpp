#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	auto __solve_tc = [&](){
		array<int, 3> x;
		for(auto i = 0; i < 3; ++ i){
			cin >> x[i];
		}
		int mx = max({x[0], x[1], x[2]});
		int cnt = 0, t;
		for(auto i = 0; i < 3; ++ i){
			if(x[i] < mx){
				++ cnt;
				t = x[i];
			}
		}
		if(cnt >= 2){
			cout << "NO\n";
		}
		else{
			cout << "YES\n";
			if(cnt == 1){
				cout << mx << " " << t << " " << t << "\n";
			}
			else{
				cout << mx << " " << mx << " " << mx << "\n";
			}
		}
		return 0;
	};
	int __tc_cnt;
	cin >> __tc_cnt;
	for(auto __tc_it = 0; __tc_it < __tc_cnt; ++ __tc_it){
		__solve_tc();
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