#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	auto __solve_tc = [&](int __tc_num){
		int n, p, k, x, y;
		string s;
		cin >> n >> p >> k >> s >> x >> y, -- p;
		vector<int> cnt(n);
		long long res = numeric_limits<long long>::max();
		for(auto i = n - 1; i >= p; -- i){
			if(i + k < n){
				cnt[i] = cnt[i + k];
			}
			if(s[i] == '0'){
				++ cnt[i];
			}
			ctmin(res, y * (i - p) + x * cnt[i]);
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