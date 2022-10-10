#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		string s;
		cin >> s;
		int n = (int)s.size();
		auto test = [&](string s)->bool{
			array<int, 2> cnt{};
			for(auto i = 0; i < n - 1; ++ i){
				cnt[0] += s[i] == 'a' && s[i + 1] == 'b';
				cnt[1] += s[i] == 'b' && s[i + 1] == 'a';
			}
			return cnt[0] == cnt[1];
		};
		for(auto mask = 0; mask < 4; ++ mask){
			if(mask & 1){
				s.front() ^= 'a' ^ 'b';
			}
			if(mask & 2){
				s.back() ^= 'a' ^ 'b';
			}
			if(test(s)){
				cout << s << "\n";
				return 0;
			}
			if(mask & 1){
				s.front() ^= 'a' ^ 'b';
			}
			if(mask & 2){
				s.back() ^= 'a' ^ 'b';
			}
		}
		assert(false);
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