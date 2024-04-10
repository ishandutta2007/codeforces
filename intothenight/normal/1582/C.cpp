#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n;
		string s;
		cin >> n >> s;
		int res = numeric_limits<int>::max();
		for(auto c = 'a'; c <= 'z'; ++ c){
			vector<int> pos{-1};
			for(auto i = 0; i < n; ++ i){
				if(s[i] != c){
					pos.push_back(i);
				}
			}
			pos.push_back(n);
			bool fail = false;
			for(auto t = 1; t < (int)pos.size() - 1; ++ t){
				if(s[pos[t]] != s[pos[(int)pos.size() - 1 - t]]){
					fail = true;
					break;
				}
			}
			if(fail){
				continue;
			}
			int cur = 0;
			auto l = 1, r = (int)pos.size() - 2;
			for(; l <= r; ++ l, -- r){
				int left = pos[l] - pos[l - 1] - 1;
				int right = pos[r + 1] - pos[r] - 1;
				cur += max(left, right) - min(left, right);
			}
			res = min(res, cur);
		}
		res == numeric_limits<int>::max() ? cout << "-1\n" : cout << res << "\n";
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
rprarlap
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////