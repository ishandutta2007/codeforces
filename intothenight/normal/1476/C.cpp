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
		vector<long long> c(n), a(n), b(n);
		for(auto i = 0; i < n; ++ i){
			cin >> c[i];
		}
		for(auto i = 0; i < n; ++ i){
			cin >> a[i], -- a[i];
		}
		for(auto i = 0; i < n; ++ i){
			cin >> b[i], -- b[i];
			if(a[i] > b[i]){
				swap(a[i], b[i]);
			}
		}
		long long pref = b[1] - a[1] + 2;
		long long res = pref + c[1] - 1;
		for(auto i = 2; i < n; ++ i){
			if(a[i] == b[i]){
				pref = 2;
			}
			else{
				pref = max(pref + c[i - 1] + 1 - (b[i] - a[i]), b[i] - a[i] + 2);
			}
			ctmax(res, pref + c[i] - 1);
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