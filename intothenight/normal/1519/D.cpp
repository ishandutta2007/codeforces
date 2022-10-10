#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	for(auto i = 0; i < n; ++ i){
		cin >> b[i];
	}
	vector<long long> pref(n + 1);
	for(auto i = 0; i < n; ++ i){
		pref[i + 1] = pref[i] + 1LL * a[i] * b[i];
	}
	long long res = numeric_limits<long long>::min();
	for(auto s = 0; s < 2 * n - 1; ++ s){
		vector<long long> pref2(n + 1);
		for(auto i = 0; i < n; ++ i){
			int j = s - i;
			pref2[i + 1] = pref2[i] + (0 <= j && j < n ? 1LL * a[i] * b[j] : 0);
		}
		for(auto l = 0; l < n; ++ l){
			int r = s + 1 - l;
			if(l < r && r <= n){
				ctmax(res, pref[l] + pref[n] - pref[r] + pref2[r] - pref2[l]);
			}
		}
	}
	cout << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////