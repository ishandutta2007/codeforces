#include <bits/stdc++.h>
using namespace std;
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n, k;
		cin >> n >> k;
		vector<int> a(n);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
		}
		for(auto i = 0; i < n; ++ i){
			int ignore;
			cin >> ignore;
		}
		sort(a.begin(), a.end());
		vector<int> reach(n + 1, n), suff(n + 1);
		int res = 0;
		for(auto i = n - 1; i >= 0; -- i){
			reach[i] = upper_bound(a.begin(), a.end(), a[i] + k) - a.begin();
			suff[i] = max(suff[i + 1], reach[i] - i);
			ctmax(res, reach[i] - i + suff[reach[i]]);
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