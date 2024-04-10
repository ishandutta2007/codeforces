#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		string n;
		int k;
		cin >> n >> k;
		{
			array<int, 10> cnt{};
			for(auto x: n){
				++ cnt[x - '0'];
			}
			if(10 - count(cnt.begin(), cnt.end(), 0) <= k){
				cout << n << "\n";
				return 0;
			}
		}
		for(auto p = (int)n.size() - 1; p >= 0; -- p){
			for(char x = n[p] + 1; x <= '9'; ++ x){
				array<int, 10> cnt{};
				++ cnt[x - '0'];
				for(auto i = 0; i < p; ++ i){
					++ cnt[n[i] - '0'];
				}
				int dif = 10 - count(cnt.begin(), cnt.end(), 0);
				if(dif > k){
					continue;
				}
				if(dif == k){
					char y = find_if(cnt.begin(), cnt.end(), [&](int x){ return x; }) - cnt.begin() + '0';
					cout << n.substr(0, p) + x + string((int)n.size() - p - 1, y) << "\n";
				}
				else{
					cout << n.substr(0, p) + x + string((int)n.size() - p - 1, '0') << "\n";
				}
				return 0;
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