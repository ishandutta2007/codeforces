#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n;
		long long k;
		cin >> n >> k;
		vector<long long> a(n);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		long long g = 0;
		for(auto i = 1; i < n; ++ i){
			g = gcd(g, a[i] - a[i - 1]);
		}
		(a[0] - k) % g == 0 ? cout << "YES\n" : cout << "NO\n";
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