#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n, k, x;
	cin >> n >> k >> x;
	vector<vector<long long>> a(n, vector<long long>(k + 1));
	vector<long long> pref(n + 1), suff(n + 1);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i][0];
		for(auto j = 1; j <= k; ++ j){
			a[i][j] = a[i][j - 1] * x;
		}
		pref[i + 1] = pref[i] | a[i][0];
	}
	for(auto i = n - 1; i >= 0; -- i){
		suff[i] = suff[i + 1] | a[i][0];
	}
	long long res = 0;
	for(auto i = 0; i < n; ++ i){
		ctmax(res, pref[i] | a[i][k] | suff[i + 1]);
	}
	cout << res << "\n";
	return 0;
}

/*
5 1 5
783369063 704521063 283307245 729170369 122152034 
*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////