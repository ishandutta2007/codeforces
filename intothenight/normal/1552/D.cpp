#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n;
		cin >> n;
		vector<int> a(n);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
			a[i] = abs(a[i]);
		}
		sort(a.begin(), a.end());
		if(!a[0]){
			cout << "YES\n";
			return 0;
		}
		vector<int> sum(1 << n);
		for(auto mask = 0; mask < 1 << n; ++ mask){
			for(auto i = 0; i < n; ++ i){
				if(mask & 1 << i){
					sum[mask] += a[i];
				}
			}
		}
		for(auto mask = 1; mask < 1 << n; ++ mask){
			for(auto smask = mask - 1 & mask; smask; smask = (smask - 1) & mask){
				if(sum[smask] == sum[mask ^ smask]){
					cout << "YES\n";
					return 0;
				}
			}
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