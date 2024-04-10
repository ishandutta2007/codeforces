#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n, x;
		cin >> n >> x;
		vector<int> a(n);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
		}
		int res = 0;
		for(auto i = 0; i < n; ++ i){
			if(is_sorted(a.begin() + i, a.end())){
				cout << res << "\n";
				return 0;
			}
			if(*min_element(a.begin() + i, a.end()) < min(a[i], x)){
				cout << "-1\n";
				return 0;
			}
			if(a[i] > x){
				swap(x, a[i]);
				++ res;
			}
		}
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