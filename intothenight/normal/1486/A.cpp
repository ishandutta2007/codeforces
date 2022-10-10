#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n;
		cin >> n;
		vector<int> h(n);
		for(auto i = 0; i < n; ++ i){
			cin >> h[i];
		}
		for(auto i = 0; i < n; ++ i){
			if(accumulate(h.begin(), h.begin() + i + 1, 0LL) < 1LL * i * (i + 1) / 2){
				cout << "NO\n";
				return 0;
			}
		}
		cout << "YES\n";
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