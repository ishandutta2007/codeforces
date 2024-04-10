#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int h, w;
		cin >> h >> w;
		vector<string> res(h, string(w, '0'));
		for(auto i = 0; i < h; i += 2){
			res[i][0] = '1';
		}
		for(auto j = 0; j < w; j += 2){
			res[0][j] = '1';
		}
		for(auto i = (~w & 1) * 2; i < h; i += 2){
			res[i][w - 1] = '1';
		}
		for(auto j = (~h & 1) * 2; j < w; j += 2){
			res[h - 1][j] = '1';
		}
		if(~h & 1 && ~w & 1){
			res[h - 1][w - 2] = '0';
		}
		else if((h ^ w) & 1){
			res[h - 1][w - 1] = '0';
		}
		for(auto s: res){
			cout << s << "\n";
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