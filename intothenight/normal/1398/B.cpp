#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	auto __solve_tc = [&](int __tc_num){
		string s;
		cin >> s;
		int n = int(s.size());
		vector<int> a;
		for(auto i = 0; i < n; ){
			while(i < n && s[i] == '0'){
				++ i;
			}
			if(i == n) break;
			int j = i;
			while(j < n && s[j] == '1'){
				++ j;
			}
			a.push_back(j - i);
			i = j;
		}
		sort(a.rbegin(), a.rend());
		int res = 0;
		for(auto i = 0; i < int(a.size()); i += 2){
			res += a[i];
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