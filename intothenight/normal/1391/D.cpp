#include "bits/stdc++.h"
using namespace std;
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	if(n >= 4){
		cout << "-1\n";
		return 0;
	}
	vector<string> a(n);
	for(auto &s: a){
		cin >> s;
	}
	int left = 0;
	for(auto i = 0; i < n; ++ i){
		if(a[i][0] == '1'){
			left += 1 << i;
		}
	}
	vector<int> dp(1 << n);
	for(auto mask = 0; mask < 1 << n; ++ mask){
		dp[mask] = __builtin_popcount(mask ^ left);
	}
	vector<vector<int>> ok(1 << n, vector<int>(1 << n, 1));
	for(auto pmask = 0; pmask < 1 << n; ++ pmask){
		for(auto mask = 0; mask < 1 << n; ++ mask){
			for(auto i = 0; i + 2 <= n; ++ i){
				if(~(!!(pmask & 1 << i) + !!(pmask & 1 << i + 1) + !!(mask & 1 << i) + !!(mask & 1 << i + 1)) & 1){
					ok[pmask][mask] = false;
				}
			}
		}
	}
	for(auto j = 1; j < m; ++ j){
		int cur = 0;
		for(auto i = 0; i < n; ++ i){
			if(a[i][j] == '1'){
				cur += 1 << i;
			}
		}
		static const int inf = numeric_limits<int>::max();
		static vector<int> dp_next; dp_next.assign(1 << n, inf);
		for(auto mask = 0; mask < 1 << n; ++ mask){
			for(auto pmask = 0; pmask < 1 << n; ++ pmask){
				if(dp[pmask] != inf && ok[pmask][mask]){
					ctmin(dp_next[mask], dp[pmask] + __builtin_popcount(mask ^ cur));
				}
			}
		}
		swap(dp, dp_next);
	}
	cout << *min_element(dp.begin(), dp.end()) << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////