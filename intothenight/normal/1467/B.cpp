#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n;
		cin >> n;
		vector<int> a(n);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
		}
		int res = 0;
		auto check = [&](int i){
			return i > 0 && i < n - 1 && (a[i] > a[i - 1] && a[i] > a[i + 1] || a[i] < a[i - 1] && a[i] < a[i + 1]);
		};
		int delta = 0;
		for(auto i = 1; i < n - 1; ++ i){
			res += check(i);
			int cur = check(i - 1) + check(i) + check(i + 1);
			int prev = a[i];
			a[i] = a[i - 1];
			ctmax(delta, cur - check(i - 1) - check(i) - check(i + 1));
			a[i] = a[i + 1];
			ctmax(delta, cur - check(i - 1) - check(i) - check(i + 1));
			a[i] = prev;
		}
		cout << res - delta << "\n";
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