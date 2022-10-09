#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll x[255], y[255];
int n, m;

bool mozda[1000005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++)
		cin >> x[i] >> y[i];

	for (int i=0; i<m; i++)
		for (int j=i+1; j<m; j++) {
			if (y[i] != y[j]) {
				ll p = x[j]*y[i] - x[i]*y[j];
				ll q = y[i] - y[j];

				if (q < 0) {
					p = -p;
					q = -q;
				}

				if (p % q)
					continue;

				p /= q;
				if (p < 1 || p > n)
					continue;

				mozda[p] = 1;
			}
		}

	ll sol = 0;

	for (int i=1; i<=n; i++) {
		if (!mozda[i]) {
			sol += 1;
			continue;
		}

		map<pair<ll, ll>, int> mp;

		for (int j=0; j<m; j++) {
			ll p = x[j] - i;
			ll q = y[j];

			ll g = gcd(p, q);
			p /= g;
			q /= g;

			mp[{p, q}]++;
		}

		int hi = 0;
		for (auto p : mp)
			hi = max(hi, p.second);

		sol += hi;
	}

	cout << sol << '\n';
}