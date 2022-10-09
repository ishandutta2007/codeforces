// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

ll f(ll x, ll n) {
	return x-1 + (n+x-1)/x-1;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		ll z = 2e9;
		for (ll x=1; x*x <= 2*n; x++) {
			z = min(z, f(x, n));
		}
		cout << z << '\n';
	}
}