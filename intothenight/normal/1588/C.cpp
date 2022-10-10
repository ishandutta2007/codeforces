#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n;
		cin >> n;
		map<int, int> cnt;
		int c = -1, d = 0;
		long long res = 0;
		for(auto i = 0; i < n; ++ i){
			int x;
			cin >> x;
			if(c >= 1){
				while(!cnt.empty() && cnt.rbegin()->first * c + d > x){
					cnt.erase(prev(cnt.end()));
				}
			}
			else{
				while(!cnt.empty() && cnt.begin()->first * c + d > x){
					cnt.erase(cnt.begin());
				}
			}
			c = -c;
			d = x - d;
			++ cnt[(x - d) * c];
			res += cnt[-d * c];
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