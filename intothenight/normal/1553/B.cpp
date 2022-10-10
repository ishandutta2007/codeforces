#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		string s, t;
		cin >> s >> t;
		int n = (int)s.size(), m = (int)t.size();
		for(auto p = 0; p < n; ++ p){
			for(auto q = p; q < n; ++ q){
				if(q - p + 1 <= m){
					for(auto i = p; i <= q; ++ i){
						if(s[i] != t[i - p]){
							goto NEXT;
						}
					}
					for(auto i = q - 1; i >= q - (m - (q - p + 1)); -- i){
						if(i < 0 || s[i] != t[q - p + 1 + (q - 1 - i)]){
							goto NEXT;
						}
					}
					cout << "YES\n";
					return 0;
					NEXT:;
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