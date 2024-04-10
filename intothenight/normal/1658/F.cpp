#include <bits/stdc++.h>
using namespace std;
#if __cplusplus > 201703L
#include <ranges>
using namespace numbers;
#endif



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n, m;
		string s;
		cin >> n >> m >> s;
		int x = ranges::count(s, '1');
		if(1LL * x * m % n){
			cout << "-1\n";
			return 0;
		}
		int y = 1LL * x * m / n;
		vector<int> pref(n + 1);
		for(auto i = 0; i < n; ++ i){
			pref[i + 1] = pref[i] + (s[i] & 1);
		}
		for(auto i = 0; i + m <= n; ++ i){
			if(pref[i + m] - pref[i] == y){
				cout << "1\n" << i + 1 << " " << i + m << "\n";
				return 0;
			}
		}
		for(auto r = 1; r < m; ++ r){
			int l = n - (m - r);
			if(pref[r] + pref[n] - pref[l] == y){
				cout << "2\n" << 1 << " " << r << "\n" << l + 1 << " " << n << "\n";
				return 0;
			}
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