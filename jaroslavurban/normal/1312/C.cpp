#ifndef __PROGTEST__
#include <bits/stdc++.h>
using namespace std;
#endif // __PROGTEST__

typedef long long ll;
typedef long double ld;
#define pb(x) push_back(x)
#define ff first
#define ss second
#define vec vector


int main(){
	ll t, n, k;
	cin >> t;
	for (ll i = 0; i < t; ++i){
		cin >> n >> k;
		ll exps[64] = {}, a[30] = {};
		for (ll i = 0; i < n; ++i)
			cin >> a[i];
		bool fail = false;
		for (ll i = 0; i < n; ++i){
			while (a[i]){
				ll lg = 0;
				while (a[i] > pow(k, lg)) lg++;
				if (a[i] < pow(k, lg)) lg--;
				if (exps[lg]++){
					fail = true;
					break;
				}
				a[i] -= pow(k, lg);
			}
			if (fail) break;
		}
		if (fail) cout << "NO"<< endl;
		else cout << "YES" << endl;
	}
}