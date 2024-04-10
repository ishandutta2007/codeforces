#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m, cost;
	cin >> n >> m >> cost;
	vector<array<int, 3>> a(n);
	for(auto i = 0; i < n; ++ i){
		int money, monitors, k, mask = 0;
		cin >> money >> monitors >> k;
		for(auto j = 0; j < k; ++ j){
			int p;
			cin >> p, -- p;
			mask |= 1 << p;
		}
		a[i] = {monitors, money, mask};
	}
	sort(a.begin(), a.end());
	vector<long long> dp(1 << m, numeric_limits<long long>::max() / 2);
	dp[0] = 0;
	long long res = numeric_limits<long long>::max() / 2;
	for(auto [monitors, money, nmask]: a){
		if(dp[nmask] > money){
			for(auto mask = 0; mask < 1 << m; ++ mask){
				if((mask & nmask) == mask){
					ctmin(dp[mask], money);
				}
			}
			for(auto mask = 0; mask < 1 << m; ++ mask){
				ctmin(dp[mask], dp[mask ^ (mask & nmask)] + money);
			}
		}
		ctmin(res, dp.back() + 1LL * cost * monitors);
	}
	if(res < numeric_limits<long long>::max() / 2){
		cout << res << "\n";
	}
	else{
		cout << "-1\n";
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