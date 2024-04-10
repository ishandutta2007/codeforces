#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		string s;
		cin >> s;
		int n = (int)s.size();
		array<array<int, 2>, 2> cnt{};
		long long res = 0;
		for(auto i = 0, j = 0; i < n; ++ i){
			while(j < n && (s[j] == '?' || !cnt[j & 1][~s[j] & 1] && !cnt[~j & 1][s[j] & 1])){
				if(s[j] != '?'){
					++ cnt[j & 1][s[j] & 1];
				}
				++ j;
			}
			res += j - i;
			if(s[i] != '?'){
				-- cnt[i & 1][s[i] & 1];
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