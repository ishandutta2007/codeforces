#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	auto __solve_tc = [&](){
		int n;
		string a, b;
		cin >> n >> a >> b;
		vector<int> res;
		int cur = a[0] - '0';
		for(auto i = 1; i < n; ++ i){
			if(a[i] != a[i - 1]){
				res.push_back(i - 1);
				cur ^= 1;
			}
		}
		for(auto i = n - 1; i >= 0; -- i){
			if(b[i] - '0' != cur){
				res.push_back(i);
				cur ^= 1;
			}
		}
		cout << int(res.size()) << " ";
		for(auto i: res){
			cout << i + 1 << " ";
		}
		cout << "\n";
		return 0;
	};
	int __tc_cnt;
	cin >> __tc_cnt;
	for(auto __tc_it = 0; __tc_it < __tc_cnt; ++ __tc_it){
		__solve_tc();
	}
	return 0;
}

/*
01011
11011
00011
11111
00000


11100

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////