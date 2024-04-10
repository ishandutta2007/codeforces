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
		if(accumulate(a.begin(), a.end(), 0) == x){
			cout << "NO\n";
			return 0;
		}
		int sum = 0;
		for(auto i = 0; i < n; ++ i){
			sum += a[i];
			if(sum == x){
				swap(a[i], a[i + 1]);
				break;
			}
		}
		cout << "YES\n";
		for(auto i = 0; i < n; ++ i){
			cout << a[i] << " ";
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