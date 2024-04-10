#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	auto __solve_tc = [&](int __tc_num){
		int n;
		cin >> n;
		vector<int> a(n), cnt(31);
		const int mx = 30;
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
			for(auto bit = mx; bit >= 0; -- bit){
				if(a[i] & 1 << bit){
					++ cnt[bit];
				}
			}
		}
		if(all_of(cnt.begin(), cnt.end(), [&](int x){ return ~x & 1; })){
			cout << "DRAW\n";
		}
		else{
			int bit = 30;
			while(~cnt[bit] & 1){
				-- bit;
			}
			cnt[bit] % 4 == 3 && ~(n - cnt[bit]) & 1 ? cout << "LOSE\n" : cout << "WIN\n";
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