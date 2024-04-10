#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, m;
	cin >> n >> m;
	vector<int> a(n), g(n + 1), bad(m);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
		g[i + 1] = gcd(g[i], a[i]);
	}
	for(auto i = 0; i < m; ++ i){
		cin >> bad[i];
	}
	sort(bad.begin(), bad.end());
	auto eval = [&](int p){
		return binary_search(bad.begin(), bad.end(), p) ? -1 : 1;
	};
	auto calc = [&](int x){
		int res = 0;
		for(auto p = 2; p * p <= x; ++ p){
			while(x % p == 0){
				res += eval(p);
				x /= p;
			}
		}
		if(x > 1){
			res += eval(x);
		}
		return res;
	};
	vector<int> val(n), pref(n + 1), gval(n + 1);
	for(auto i = 0; i < n; ++ i){
		val[i] = calc(a[i]);
		pref[i + 1] = pref[i] + val[i];
		gval[i + 1] = calc(g[i + 1]);
	}
	vector<int> dp(n + 1);
	for(auto i = n - 1; i >= 0; -- i){
		dp[i] = pref[n] - pref[i];
		for(auto j = i + 1; j <= n; ++ j){
			ctmax(dp[i], dp[j] + pref[j] - pref[i] - (j - i) * gval[j]);
		}
	}
	cout << dp[0] << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////