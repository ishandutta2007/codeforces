#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n, k;
		cin >> n >> k;
		vector<array<int, 2>> a(n);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i][0], a[i][1] = i;
		}
		auto cmpr = a;
		sort(cmpr.begin(), cmpr.end());
		vector<int> b;
		for(auto x: a){
			b.push_back(lower_bound(cmpr.begin(), cmpr.end(), x) - cmpr.begin());
		}
		int cnt = 0;
		for(auto i = 0; i < n; ){
			int j = i + 1;
			while(j < n && b[j - 1] + 1 == b[j]){
				++ j;
			}
			++ cnt;
			i = j;
		}
		cnt <= k ? cout << "Yes\n" : cout << "No\n";
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