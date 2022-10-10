#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		const int mx = 1e5;
		int n;
		cin >> n;
		vector<int> a(n);
		vector<array<int, 2>> cnt(mx);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i], -- a[i];
			++ cnt[a[i]][i & 1];
		}
		sort(a.begin(), a.end());
		for(auto i = 0; i < n; ++ i){
			-- cnt[a[i]][i & 1];
		}
		for(auto x = 0; x < mx; ++ x){
			if(cnt[x][0] || cnt[x][1]){
				cout << "NO\n";
				return 0;
			}
		}
		cout << "YES\n";
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