#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define pb(x) push_back(x)

int main(){
	ll t;
	cin >> t;
	for (ll i = 0; i < t; ++i){
		ll n;
		cin >> n;
		ll f, s, out;
		cin >> f;
		if (n != 1)
			cin >> s;
		for (ll j = min(n, (ll) 2); j < n; ++j)
			cin >> out;
		if (n == 1 && f % 2) cout << -1 << endl;
		else if (n == 1) cout << 1 << endl << 1 << endl;
		else if (f % 2 && s % 2) cout << 2 << endl << "1 2" << endl;
		else if (f % 2 == 0) cout << 1 << endl << 1 << endl;
		else if (s % 2 == 0) cout << 1 << endl << 2 << endl;
	}
}