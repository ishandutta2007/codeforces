#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n;
		cin >> n;
		vector<int> s(n);
		vector<long long> pref(n + 1);
		long long res = 0;
		for(auto i = 0; i < n; ++ i){
			cin >> s[i];
			if(s[i] - 1 >= pref[i]){
				res += s[i] - 1 - pref[i];
			}
			else{
				pref[i + 1] += pref[i] - (s[i] - 1);
			}
			for(auto j = i + 2; j <= min(n, i + s[i]); ++ j){
				++ pref[j];
			}
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