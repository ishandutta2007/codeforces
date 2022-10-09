#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct edge {
	int v, w;
};

int n, k;
basic_string<edge> e[500005];
ll p[500005], q[500005];

struct stvar {
	ll p, q, r;
	bool operator< (const stvar& b) const {
		return q+r-p > b.q+b.r-b.p;
	}
};

ll daj(const basic_string<stvar>& b, int k) {
	ll z = 0;
	for (int i=0; i<(int)b.size(); i++) {
		if (i < k) {
			z += max(b[i].p, b[i].q + b[i].r);
		} else {
			z += b[i].p;
		}
	}
	return z;
}

void dfs(int x, int par) {
	basic_string<stvar> b;
	for (auto [y, w] : e[x]) {
		if (y == par)
			continue;
		dfs(y, x);
		b += {p[y], q[y], w};
	}
	sort(b.begin(), b.end());
	p[x] = daj(b, k);
	q[x] = daj(b, k-1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int qq;
	cin >> qq;
	while (qq--) {
		cin >> n >> k;
		for (int i=1; i<=n; i++)
			e[i] = {};
		for (int i=1; i<n; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			e[u] += {v, w};
			e[v] += {u, w};
		}

		dfs(1, 1);
		cout << max(p[1], q[1]) << '\n';
	}
}