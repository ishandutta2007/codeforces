#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll x;
	cin >> x;
	ll u=1, v=x;
	for (ll i=1; i*i<=x; i++) {
		ll j = x / i;
		if (gcd(i, j) == 1 && x % i == 0)
			u=i, v=j;
	}
	cout << u << ' ' << v << '\n';
}