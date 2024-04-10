// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct rac {
	ll p, q;

	rac(ll a=0, ll b=1) : p(a), q(b) {
		if (q < 0) {
			p = -p;
			q = -q;
		} else if (q == 0 && p < 0) {
			p = -p;
		}
	}

	template<class T>
	auto operator- (const T& b) const {
		return rac(p*b.q - b.p*q, q*b.q);
	}
};

int n;
rac x[2005], y[2005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=0; i<n; i++) {
		ll a, b, c, d;
		cin >> a >> b >> c;
		d = a*a + b*b;
		x[i] = rac(a*c, d);
		y[i] = rac(b*c, d);
	}

	ll sol = 0, orig = 0;

	for (int i=0; i<n; i++) {
		map<pair<ll, ll>, int> mp;
		for (int j=0; j<n; j++) {
			if (j == i) continue;
			rac xx = x[j] - x[i];
			rac yy = y[j] - y[i];
			if (xx.p == 0 && yy.p == 0) {
				orig++;
			} else {
				ll p = xx.p;
				ll q = yy.p;
				ll g = gcd(abs(p), abs(q));
				p /= g;
				q /= g;
				if (q < 0 || (q == 0 && p < 0)) {
					p = -p;
					q = -q;
				}

				mp[{p, q}]++;
			}
		}
		for (auto [k, v] : mp) {
			sol += v*(v-1) / 2;
		}
	}

	cerr << sol << '\n';
	cerr << orig << '\n';

	cout << (sol + orig*(n-2)) / 3 << '\n';
}