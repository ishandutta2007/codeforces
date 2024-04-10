#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n, m = 5;
		cin >> n;
		vector<array<int, 5>> a(n);
		for(auto i = 0; i < n; ++ i){
			for(auto j = 0; j < m; ++ j){
				cin >> a[i][j];
			}
		}
		auto cmp = [&](auto a, auto b){
			int cnt = 0;
			for(auto j = 0; j < m; ++ j){
				cnt += a[j] > b[j];
			}
			return cnt >= 3;
		};
		int i = max_element(a.begin(), a.end(), cmp) - a.begin();
		for(auto ii = 0; ii < n; ++ ii){
			if(ii != i && !cmp(a[ii], a[i])){
				cout << "-1\n";
				return 0;
			}
		}
		cout << i + 1 << "\n";
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