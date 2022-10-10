#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	auto __solve_tc = [&](int __tc_num){
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
		}
		for(auto i = 0; i < n; ++ i){
			cin >> b[i];
		}
		int mina = *min_element(a.begin(), a.end()), minb = *min_element(b.begin(), b.end());
		long long res = 0;
		for(auto i = 0; i < n; ++ i){
			res += max(a[i] - mina, b[i] - minb);
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