#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n, qn;
		string s;
		cin >> n >> qn >> s;
		array<vector<int>, 2> pos;
		for(auto i = 0; i < n; ++ i){
			pos[s[i] - '0'].push_back(i);
		}
		for(auto qi = 0; qi < qn; ++ qi){
			int l, r;
			cin >> l >> r, -- l;
			for(auto jump = l + 1; jump < r; ++ jump){
				for(auto i = l, p = 0; i < r; ++ i){
					auto it = lower_bound(pos[s[i] - '0'].begin(), pos[s[i] - '0'].end(), p + (i == jump));
					if(it == pos[s[i] - '0'].end()){
						goto FAIL;
					}
					p = *it + 1;
				}
				cout << "YES\n";
				goto OK;
				FAIL:;
			}
			cout << "NO\n";
			OK:;
		}
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