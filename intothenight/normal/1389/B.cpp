#include "bits/stdc++.h"
using namespace std;
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	auto __solve_tc = [&](int __tc_num){
		int n, k, z;
		cin >> n >> k >> z;
		vector<int> a(n);
		for(auto i = 0; i < n; ++ i){
			cin >> a[i];
		}
		long long res = 0;
		for(auto left = 0; left <= min(z, k >> 1); ++ left){
			int right = k - 2 * left;
			long long cur = accumulate(a.begin(), a.begin() + right + 1, 0LL);
			int t = 0;
			for(auto i = 0; i <= min(right, n - 2); ++ i){
				ctmax(t, a[i] + a[i + 1]);
			}
			ctmax(res, cur + 1LL * t * left);
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