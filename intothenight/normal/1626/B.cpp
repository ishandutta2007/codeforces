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
		string s;
		cin >> s;
		for(auto i = (int)s.size() - 2; i >= 0; -- i){
			int x = s[i] - '0', y = s[i + 1] - '0';
			if(x + y >= 10){
				cout << s.substr(0, i) << x + y << s.substr(i + 2) << "\n";
				return 0;
			}
		}
		int i = 1;
		while(i < (int)s.size() && s[i] == '0'){
			++ i;
		}
		if(i == (int)s.size()){
			cout << s.substr(0, (int)s.size() - 1) << "\n";
		}
		else{
			int x = s[i - 1] - '0', y = s[i] - '0';
			cout << s.substr(0, i - 1) << x + y << s.substr(i + 1) << "\n";
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
10050

1050
1005
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////