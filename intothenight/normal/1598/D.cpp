#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n;
		cin >> n;
		vector<array<int, 2>> a(n);
		vector<array<int, 2>>	cnt(n);
		for(auto i = 0; i < n; ++ i){
			for(auto j = 0; j < 2; ++ j){
				cin >> a[i][j], -- a[i][j];
				++ cnt[a[i][j]][j];
			}
		}
		sort(a.begin(), a.end());
		long long res = 1LL * n * (n - 1) * (n - 2) / 6;
		for(auto [x, y]: a){
			res -= 1LL * (cnt[x][0] - 1) * (cnt[y][1] - 1);
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
o o ?
x ? x

o o ?
? x x

o ? o
x x ?
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////