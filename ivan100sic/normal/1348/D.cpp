// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		ll c = 1, w = 1;
		vector<ll> z;
		while (w < n) {
			z.push_back(c);
			c += c;
			w += c;
		}

		int u = z.size();

		if (w > n) {
			ll q = w - n;
			z.back() -= q;
			w -= q;
		}

		if (z.back() < 0) {
			ll q = -z.back() / 2;
			z[u-2] -= q;
			z.back() += 2*q;
		}

		if (z.back() == -1) {
			z[u-2] -= 1;
			z[u-1] += 2;
		}

		cout << z.size() << '\n';
		for (ll x : z)
			cout << x << ' ';
		cout << '\n';
	}
}