#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
		}
		if(k == 1){
			for(auto i = 0; i < n; ++ i){
				if(a[i] != a[0]){
					cout << "-1\n";
					return 0;
				}
			}
			cout << "1\n";
		}
		else{
			int cnt = 0;
			for(auto i = 1; i < n; ++ i){
				if(a[i] != a[i - 1]){
					++ cnt;
				}
			}
			cout << max(1, (cnt + k - 2) / (k - 1)) << "\n";
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