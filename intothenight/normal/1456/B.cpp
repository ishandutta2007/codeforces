#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> a(n), pref(n + 1);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
		pref[i + 1] = pref[i] ^ a[i];
	}
	for(auto i = 0; i + 3 <= n; ++ i){
		if(__lg(a[i]) == __lg(a[i + 1]) && __lg(a[i]) == __lg(a[i + 2])){
			cout << "1\n";
			return 0;
		}
	}
	int res = numeric_limits<int>::max();
	for(auto l = 0; l < n; ++ l){
		for(auto m = l + 1; m < n; ++ m){
			for(auto r = m + 1; r <= n; ++ r){
				if((pref[m] ^ pref[l]) > (pref[r] ^ pref[m])){
					ctmin(res, r - l - 2);
				}
			}
		}
	}
	res == numeric_limits<int>::max() ? cout << "-1\n" : cout << res << "\n";
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////