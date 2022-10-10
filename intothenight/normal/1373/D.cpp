#include "bits/stdc++.h"
using namespace std;
template<typename T, typename U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<typename T, typename U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int SOLVE(){
	int n;
	cin >> n;
	vector<int> a(n);
	long long tot = 0;
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
		if(!(i & 1)){
			tot += a[i];
		}
	}
	vector<long long> pref(n + 1);
	for(auto i = 0; i < n; ++ i){
		pref[i + 1] = pref[i] + (i & 1 ? a[i] : -a[i]);
	}
	array<long long, 2> mval{numeric_limits<long long>::max() / 8, numeric_limits<long long>::max() / 8};
	long long res = tot;
	for(auto r = 0; r <= n; ++ r){
		ctmax(res, tot + pref[r] - ctmin(mval[r & 1], pref[r]));
	}
	cout << res << "\n";
	return 0;
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int ttt;
	cin >> ttt;
	while(ttt --){
		SOLVE();
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