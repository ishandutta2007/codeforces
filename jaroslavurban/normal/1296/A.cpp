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
	ll vals[4000];
	for (ll i = 0; i < t; ++i){
		cin >> n;
		bool is_odd = false;
		bool is_even = false;
		for (ll j = 0; j < n; ++j){
			cin >> vals[j];
			if (vals[j] % 2) is_odd = true;
			else is_even = true;
		}
		if ((n % 2 == 0 && is_odd && is_even) || (n % 2 && is_odd)) cout << "YES"<< endl;
		else cout << "NO" << endl;
	}
}