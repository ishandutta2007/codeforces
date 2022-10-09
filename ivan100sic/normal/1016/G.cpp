// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
ll x, y;
ll a[200005];

vector<ll> q;

vector<ll> refine(vector<ll> q) {
	while (1) {
		bool found = false;
		int n = q.size();
		for (int i=0; i<n; i++) {
			for (int j=i+1; j<n; j++) {
				if (q[i] != q[j]) {
					ll g = gcd(q[i], q[j]);
					if (g > 1) {
						ll a = q[i] / g;
						ll b = q[j] / g;
						q[i] = q[j] = g;
						if (a > 1) q.push_back(a);
						if (b > 1) q.push_back(b);
						i = 321321321;
						found = true;
						break;
					}
				}
			}
		}
		if (!found) break;
	}
	return q;
}

int b[200005], c[200005], m;
int d[1 << 15];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> x >> y;
	for (int i=0; i<n; i++)
		cin >> a[i];

	if (y % x) {
		cout << "0\n";
		return 0;
	}

	if (x == y) {
		ll u=0, v=0;
		for (int i=0; i<n; i++) {
			if (a[i] % x == 0)
				u++;
			if (y % a[i] == 0)
				v++;
		}
		cout << u*v << '\n';
		return 0;
	}

	if (x == 1) {
		q = {y};
	} else {
		q = {x, y/x};
	}

	for (int i=0; i<n; i++) {
		vector<ll> q2;
		ll x = a[i];
		for (ll y : q) {
			ll g = gcd(x, y);
			if (g != 1 && g != y) {
				q2.push_back(g);
				q2.push_back(y / g);
			} else {
				q2.push_back(y);
			}
		}

		if (q2 != q) {
			q = refine(q2);
		}
	}

	map<ll, int> mp;
	for (ll x : q)
		mp[x]++;

	auto v = vector<pair<ll, int>>(begin(mp), end(mp));
	m = v.size();

	auto evec = [&](ll t) {
		vector<int> e(m);
		for (int i=0; i<m; i++) {
			while (t % v[i].first == 0) {
				e[i]++;
				t /= v[i].first;
			}
		}
		return e;
	};

	auto xvec = evec(x);
	auto yvec = evec(y);

	for (int i=0; i<n; i++) {
		auto ivec = evec(a[i]);

		if (a[i] % x == 0) {
			for (int j=0; j<m; j++) {
				if (ivec[j] == xvec[j]) {
					b[i] |= 1 << j;
				}
			}
		} else {
			b[i] = -1;
		}

		if (y % a[i] == 0) {
			for (int j=0; j<m; j++) {
				if (ivec[j] == yvec[j]) {
					c[i] |= 1 << j;
				}
			}
		} else {
			c[i] = -1;
		}
	}

	for (int i=0; i<n; i++) {
		if (b[i] != -1) {
			d[b[i]]++;
		}
	}

	for (int g=1; g<(1<<m); g<<=1) {
		for (int mask=0; mask<(1<<m); mask++) {
			if (mask & g) {
				d[mask - g] += d[mask];
			}
		}
	}

	ll sol = 0;

	for (int i=0; i<n; i++) {
		if (c[i] != -1) {
			sol += d[(1<<m) - 1 - c[i]];
		}
	}

	cout << sol << '\n';
}