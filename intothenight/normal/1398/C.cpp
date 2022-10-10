#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	auto __solve_tc = [&](int __tc_num){
		int n;
		string s;
		cin >> n >> s;
		vector<int> pref(n + 1);
		for(auto i = 0; i < n; ++ i){
			pref[i + 1] = pref[i] + s[i] - '1';
		}
		map<int, int> cnt;
		long long res = 0;
		for(auto x: pref){
			res += cnt[x];
			++ cnt[x];
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