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
	ll t, n;
	cin >> t;
	for (ll i = 0; i < t; ++i){
		cin >> n;
		vec<ll> vals;
		ll duplicates = 0;
		for (ll j = 0; j < n; ++j){
			ll val;
			cin >> val;
			vals.pb(val);
		}
		sort(vals.begin(),vals.end());
		for (ll i = 0; i < n; ++i)
			if (i && vals[i-1] == vals[i]) duplicates++;
		cout << n - duplicates << endl;
	}
}