#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct dsu {
	vector<int> p, s;

	dsu(int n) : p(n), s(n, 1) {
		iota(p.begin(), p.end(), 0);
	}

	int e(int x) {
		if (x == p[x])
			return x;
		return p[x] = e(p[x]);
	}

	ll spoji(int x, int y) {
		x = e(x);
		y = e(y);
		if (x == y)
			return 0;
		ll r = 1ll * s[x] * s[y];
		p[x] = y;
		s[y] += s[x];
		return r;
	}
} d(200005);

struct edge {
	int u, v, w;
	bool operator< (const edge& b) const {
		return w < b.w;
	}
};

int n, q;
vector<pair<int, int>> e[200005];
ll sol[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q;
	for (int i=1; i<n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[w].emplace_back(u, v);
	}
	ll z = 0;
	for (int i=1; i<=200000; i++) {
		for (auto [u, v] : e[i]) {
			z += d.spoji(u, v);
		}
		sol[i] = z;
	}
	while (q--) {
		int x;
		cin >> x;
		cout << sol[x] << ' ';
	}
	cout << '\n';
}