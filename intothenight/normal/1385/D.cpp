#include "bits/stdc++.h"
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	auto __solve_tc = [&](){
		int n;
		string s;
		cin >> n >> s;
		function<int(int, int, char)> solve = [&](int l, int r, char c){
			if(r - l == 1){
				return (int)(s[l] != c);
			}
			int m = l + (r - l >> 1), left = 0, right = 0;
			for(auto i = l; i < m; ++ i){
				left += s[i] != c;
			}
			for(auto i = m; i < r; ++ i){
				right += s[i] != c;
			}
			return min(left + solve(m, r, c + 1), right + solve(l, m, c + 1));
		};
		cout << solve(0, n, 'a') << "\n";
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