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

	ll g = 0;
	int n;
	cin >> n;
	while (n--) {
		ll x;
		cin >> x;
		g = gcd(g, x);
	}
	ll z = 0;
	for (ll i=1; i*i<=g; i++) {
		if (g % i == 0)
			z += 2;
		if (i*i == g)
			z -= 1;
	}
	cout << z << '\n';
}