// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

map<string, pair<int, int>> dirmp = {
	{"UL", {-1, -1}},
	{"UR", {-1, 1}},
	{"DL", {1, -1}},
	{"DR", {1, 1}}
};

template<class T>
T eea(T a, T b, T& x, T& y) {
	if (!b) {
		x = 1;
		y = 0;
		return a;
	}

	T x1, y1;
	T g = eea(b, a % b, x1, y1);
	x = y1;
	y = x1 - (a / b) * y1;
	return g;
}

ll resiga(int n, int m, int x0, int y0, int x11, int y11, int dx, int dy) {
	// transliraj u virtualne brojke
	n--;
	m--;
	n *= 2;
	m *= 2;
	ll lo = 9.01e18;
	// najmanje t >= 0 takvo da je x0 + t dx = x1, y0 + t dy = y1 (mod n)
	// negativni znak znaci menjamo jednakost
	for (int x1 : {x11, -x11}) {
		for (int y1 : {y11, -y11}) {
			int a, b;
			if (dx == 1)
				a = x1 - x0 + n + n;
			else
				a = x0 - x1 + n + n;
			a %= n;

			if (dy == 1)
				b = y1 - y0 + m + m;
			else
				b = y0 - y1 + m + m;
			b %= m;

			// t = a mod n
			// t = b mod m

			int g = gcd(n, m);
			if (a % g != b % g) {
				continue;
			}

			int u=0, v=0;

			eea(n, m, u, v);
			ll t = (a*1ll*v*m + b*1ll*u*n) / g;
			ll p = n*1ll*m / g;
			t = (t % p + p) % p;

			lo = min(lo, t);
		}
	}

	if (lo > 9e18) {
		return -1;
	}

	return lo + 1;
}

ll proper_solve(int n, int m, int dx, int dy, int x, int y) {
	ll sol = 0;
	for (int u=0; u<n; u++) {
		int step = m-1;
		if (u == 0 || u == n-1) {
			step = 1;
		}
		for (int v=0; v<m; v+=step) {
			if ((u+v) % 2 != (x+y) % 2)
				continue;
			ll ttl = resiga(n, m, x, y, u, v, dx, dy);
			if (ttl == -1) {
				return -1;
			} else {
				sol = max(sol, ttl);
			}
		}
	}
	return sol;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int n, m, x, y;
	string dir;
	cin >> n >> m >> x >> y >> dir;
	x--, y--;
	auto [dx, dy] = dirmp[dir];
	cout<< proper_solve(n, m, dx, dy, x, y) << '\n';
}