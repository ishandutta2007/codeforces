#include "bits/stdc++.h"
using namespace std;



int SOLVE(){
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i];
	}
	for(auto i = 0; i < n; ++ i){
		cin >> b[i];
	}
	vector<long long> pref(2 * n + 1);
	for(auto i = 0; i < n; ++ i){
		pref[i + 1] = pref[i] + b[i] - a[i];
	}
	for(auto i = n; i < 2 * n; ++ i){
		pref[i + 1] = pref[i] + b[i - n] - a[i - n];
	}
	vector<long long> mpref(2 * n + 1);
	mpref[2 * n] = pref[2 * n];
	for(auto i = 2 * n; i > 0; -- i){
		mpref[i - 1] = min(mpref[i], pref[i - 1]);
	}
	for(auto i = 0; i < n; ++ i){
		if(b[(i + n - 1) % n] + mpref[i] - pref[i] < 0){
			cout << "NO\n";
			return 0;
		}
	}
	if(accumulate(a.begin(), a.end(), 0LL) > accumulate(b.begin(), b.end(), 0LL)){
		cout << "NO\n";
		return 0;
	}
	cout << "YES\n";
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