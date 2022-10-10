#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	vector<long long> power(19, 1);
	for(auto x = 1; x <= 18; ++ x){
		power[x] = power[x - 1] * 10;
	}
	auto __solve_tc = [&](auto __tc_num)->int{
		int n, k;
		cin >> n >> k;
		vector<int> a(n + 1, 18);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
		}
		long long sum = 0;
		for(auto i = 0; i < n; ++ i){
			if(k < sum + power[a[i + 1] - a[i]] - 1){
				cout << k - sum + 1 << string(a[i], '9') << "\n";
				return 0;
			}
			sum += power[a[i + 1] - a[i]] - 1;
		}
		assert(false);
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