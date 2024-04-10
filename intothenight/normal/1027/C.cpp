#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	auto __solve_tc = [&](){
		int n;
		cin >> n;
		map<int, int> mp;
		for(auto i = 0; i < n; ++ i){
			int x;
			cin >> x;
			++ mp[x];
		}
		vector<int> a;
		for(auto [x, cnt]: mp){
			if(cnt >= 4){
				for(auto i = 0; i < 4; ++ i){
					cout << x << " ";
				}
				cout << "\n";
				return 0;
			}
			else if(cnt >= 2){
				a.push_back(x);
			}
		}
		sort(a.begin(), a.end());
		array<int, 2> cur{1, 0};
		int ind = -1;
		for(auto i = 1; i < int(a.size()); ++ i){
			if(cur[0] * a[i - 1] > a[i] * cur[1]){
				cur = {a[i], a[i - 1]};
				ind = i - 1;
			}
		}
		cout << a[ind] << " " << a[ind] << " " << a[ind + 1] << " " << a[ind + 1] << "\n";
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

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////