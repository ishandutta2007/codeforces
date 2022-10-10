#include <bits/stdc++.h>
using namespace std;
template<class T, class U> T &ctmax(T &x, const U &y){ return x = max<T>(x, y); }
template<class T, class U> T &ctmin(T &x, const U &y){ return x = min<T>(x, y); }



int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(ios::badbit | ios::failbit);
	int n;
	cin >> n;
	vector<int> a(n), firstpos(n, -1), lastpos(n, -1), cnt(n);
	for(auto i = 0; i < n; ++ i){
		cin >> a[i], -- a[i];
		lastpos[a[i]] = i;
		++ cnt[a[i]];
	}
	for(auto i = n - 1; i >= 0; -- i){
		firstpos[a[i]] = i;
	}
	vector<int> pref(n + 1);
	for(auto i = 0; i < n; ++ i){
		pref[i + 1] = pref[i];
		if(lastpos[a[i]] == i){
			ctmax(pref[i + 1], pref[firstpos[a[i]]] + cnt[a[i]]);
		}
	}
	vector<int> suffcnt(n);
	int res = numeric_limits<int>::max();
	for(auto i = n - 1; i >= 0; -- i){
		++ suffcnt[a[i]];
		ctmin(res, n - pref[i] - suffcnt[a[i]]);
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