#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll res(ll n, ll t) {
	ll p = 1;
	for (ll i=0; i<t; i++) {
		p *= n-i;
		p /= (i+1);
	}
	return p;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll n;
	cin >> n;
	cout << res(n, 7) + res(n, 6) + res(n, 5);
}