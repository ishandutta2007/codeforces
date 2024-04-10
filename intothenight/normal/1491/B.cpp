#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n, x, y;
		cin >> n >> x >> y;
		vector<int> a(n);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
		}
		for(auto i = 1; i < n; ++ i){
			if(abs(a[i - 1] - a[i]) >= 2){
				cout << "0\n";
				return 0;
			}
		}
		for(auto i = 1; i < n; ++ i){
			if(abs(a[i - 1] - a[i]) == 1){
				cout << min(x, y) << "\n";
				return 0;
			}
		}
		cout << y + min(x, y) << "\n";
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