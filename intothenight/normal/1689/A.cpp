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
		int n, m, k;
		array<string, 2> s;
		cin >> n >> m >> k >> s[0] >> s[1];
		for(auto &x: s){
			ranges::sort(x | ranges::views::reverse);
		}
		int last = 0, rep = 0;
		string res;
		while(!s[0].empty() && !s[1].empty()){
			if(rep == k){
				last = !last;
				rep = 0;
				++ rep;
				res.push_back(s[last].back());
				s[last].pop_back();
			}
			else{
				int cur = s[1].back() < s[0].back();
				if(last == cur){
					++ rep;
				}
				else{
					last = cur;
					rep = 1;
				}
				res.push_back(s[cur].back());
				s[cur].pop_back();
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