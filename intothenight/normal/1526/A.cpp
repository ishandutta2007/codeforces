#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n;
		cin >> n;
		vector<int> a(n << 1);
		for(auto i = 0; i < n << 1; ++ i){
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		vector<int> res(n << 1);
		for(auto i = 0; i < n; ++ i){
			res[i << 1] = a[i];
		}
		for(auto i = n; i < n << 1; ++ i){
			res[i - n << 1 | 1] = a[i];
		}
		for(auto x: res){
			cout << x << " ";
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