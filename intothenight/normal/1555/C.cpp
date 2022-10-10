#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](auto __tc_num)->int{
		int n;
		cin >> n;
		array<vector<int>, 2> pref;
		for(auto i = 0; i < 2; ++ i){
			pref[i].resize(n + 1);
			for(auto j = 0; j < n; ++ j){
				cin >> pref[i][j + 1];
				pref[i][j + 1] += pref[i][j];
			}
		}
		int res = numeric_limits<int>::max();
		for(auto j = 0; j < n; ++ j){
			ctmin(res, max(pref[1][j], pref[0][n] - pref[0][j + 1]));
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