#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int u, v;
		cin >> u >> v;
		if(u > v){
			cout << "No\n";
			return 0;
		}
		vector<int> posu, posv;
		for(auto bit = 0; bit < 30; ++ bit){
			if(u & 1 << bit){
				posu.push_back(bit);
			}
		}
		for(auto bit = 0; bit < 30; ++ bit){
			if(v & 1 << bit){
				posv.push_back(bit);
			}
		}
		if((int)posu.size() < (int)posv.size()){
			cout << "No\n";
			return 0;
		}
		for(auto i = 0; i < (int)posv.size(); ++ i){
			if(posu[i] > posv[i]){
				cout << "No\n";
				return 0;
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