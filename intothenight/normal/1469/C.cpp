#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n, k, h0;
		cin >> n >> k >> h0;
		int low = h0, high = h0 + 1;
		bool fail = false;
		for(auto i = 1; i < n; ++ i){
			int h;
			cin >> h;
			low -= k - 1, high += k - 1;
			ctmax(low, h), ctmin(high, h + k);
			if(low >= high || i == n - 1 && (h < low || high <= h)){
				fail = true;
			}
		}
		fail ? cout << "NO\n" : cout << "YES\n";
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