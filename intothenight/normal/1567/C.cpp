#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		string s;
		cin >> s;
		array<string, 2> t{"0", "0"};
		for(auto i = 0; i < (int)s.size(); ++ i){
			t[i & 1].push_back(s[i]);
		}
		array<int, 2> x{stoi(t[0]), stoi(t[1])};
		if(x[0] > x[1]){
			swap(x[0], x[1]);
		}
		if(x[0] == 0){
			cout << x[1] - 1 << "\n";
		}
		else{
			cout << (x[0] + 1) * (x[1] + 1) - 2 << "\n";
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