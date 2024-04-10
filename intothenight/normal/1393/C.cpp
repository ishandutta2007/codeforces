#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	auto __solve_tc = [&](int __tc_num){
		int n;
		cin >> n;
		vector<int> cnt(n);
		for(auto i = 0; i < n; ++ i){
			int x;
			cin >> x, -- x;
			++ cnt[x];
		}
		int x = *max_element(cnt.begin(), cnt.end()), xcnt = count(cnt.begin(), cnt.end(), x), rem = n - x * xcnt;
		cout << xcnt - 1 + rem / (x - 1) << "\n";
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