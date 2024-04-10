#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;


int main() {
	ll n, p, q;
	set<ll> s;
	cin >> n >> p;
	for(ll i = 0; i < p; i++) {
		ll x; cin >> x; s.insert(x);
	}
	cin >> q;
	for(ll i = 0; i < q; i++) {
		ll x; cin >> x; s.insert(x);
	}
	cout << (s.size() == n ? "I become the guy." : "Oh, my keyboard!") << endl;
	return 0;
}