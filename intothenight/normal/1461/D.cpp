#include <bits/stdc++.h>
using namespace std;



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n, qn;
		cin >> n >> qn;
		vector<int> a(n);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
		}
		sort(a.begin(), a.end());
		vector<long long> sums;
		function<void(int, int)> solve = [&](int l, int r){
			sums.push_back(accumulate(a.begin() + l, a.begin() + r, 0LL));
			if(r - l >= 2){
				int m = upper_bound(a.begin(), a.end(), a[l] + a[r - 1] >> 1) - a.begin();
				if(m != l && m != r){
					solve(l, m), solve(m, r);
				}
			}
		};
		solve(0, n);
		sort(sums.begin(), sums.end());
		for(auto qi = 0; qi < qn; ++ qi){
			int s;
			cin >> s;
			binary_search(sums.begin(), sums.end(), s) ? cout << "Yes\n" : cout << "No\n";
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