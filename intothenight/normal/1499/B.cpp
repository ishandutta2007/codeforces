#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		string s;
		cin >> s;
		int n = (int)s.size();
		for(auto i = 0; i <= n; ++ i){
			vector<int> ind;
			for(auto j = 0; j < i; ++ j){
				if(s[j] & 1){
					ind.push_back(j);
				}
			}
			for(auto j = i; j < n; ++ j){
				if(~s[j] & 1){
					ind.push_back(j);
				}
			}
			for(auto i = 1; i < (int)ind.size(); ++ i){
				if(ind[i - 1] + 1 == ind[i]){
					goto NEXT;
				}
			}
			cout << "YES\n";
			return 0;
			NEXT:;
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