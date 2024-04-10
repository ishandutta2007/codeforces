#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n;
		cin >> n;
		vector<int> a(n + 1);
		for(auto i = 0; i < n; ++ i){
			int x;
			cin >> x;
			a[i + 1] = a[i] ^ x;
		}
		if(!a[n]){
			cout << "YES\n";
			return 0;
		}
		for(auto l = 1; l <= n; ++ l){
			for(auto m = 1; m <= n - l; ++ m){
				if(a[l] == a[n] && !a[l + m]){
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