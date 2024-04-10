#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		string s, t;
		cin >> s >> t;
		int len = lcm((int)s.size(), (int)t.size());
		for(auto l = 1; l <= min((int)s.size(), (int)t.size()); ++ l){
			if((int)s.size() % l || (int)t.size() % l){
				continue;
			}
			string c = s.substr(0, l);
			string res;
			for(auto i = 0; i < (int)s.size(); i += l){
				if(c != s.substr(i, l)){
					goto FAIL;
				}
			}
			for(auto i = 0; i < (int)t.size(); i += l){
				if(c != t.substr(i, l)){
					goto FAIL;
				}
			}
			for(auto rep = 0; rep < len / l; ++ rep){
				res += c;
			}
			cout << res << "\n";
			return 0;
			FAIL:;
		}
		cout << "-1\n";
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