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
		int n;
		string s;
		cin >> n >> s;
		for(auto i = 0; i < n; ){
			while(i < n && s[i] == 'W'){
				++ i;
			}
			if(i < n){
				int j = i;
				array<int, 2> flag{};
				while(j < n && s[j] != 'W'){
					flag[s[j] == 'B'] = true;
					++ j;
				}
				if(!flag[0] || !flag[1]){
					cout << "No\n";
					return 0;
				}
				i = j;
			}
		}
		cout << "Yes\n";
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