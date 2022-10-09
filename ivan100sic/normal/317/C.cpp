#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct dsu {
	int p[305];

	dsu() {
		iota(p, p+305, 0);
	}

	int e(int x) {
		if (x == p[x])
			return x;
		return p[x] = e(p[x]);
	}

	bool spoji(int x, int y) {
		x = e(x);
		y = e(y);
		if (x == y)
			return false;
		p[x] = y;
		return true;
	}
};

int n, v, m;
set<int> e[305];
vector<array<int, 3>> sol;
ll a[305], b[305];
bool vis[305];

ll test(int x) {
	vis[x] = true;
	ll z = a[x] - b[x];
	for (int y : e[x]) {
		if (!vis[y]) {
			z += test(y);
		}
	}
	return z;
}

void mv(int x, int y, int z) {
	if (!z)
		return;
	a[y] += z;
	a[x] -= z;
	sol.push_back({x, y, z});
}

void push(int x, int p, ll amt) {
	for (int y : e[x]) {
		if (y == p)
			continue;
		push(y, x, v);
		ll z = min({amt, v-a[y], a[x]});
		amt -= z;
		mv(x, y, z);
	}
}

void pull(int x, int p, ll amt) {
	for (int y : e[x]) {
		if (y == p)
			continue;
		pull(y, x, v);
		ll z = min({amt, v-a[x], a[y]});
		amt -= z;
		mv(y, x, z);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> v >> m;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	for (int i=1; i<=n; i++)
		cin >> b[i];
	dsu d;
	for (int i=1; i<=m; i++) {
		int x, y;
		cin >> x >> y;
		if (d.spoji(x, y)) {
			e[x].insert(y);
			e[y].insert(x);
		}
	}

	for (int i=1; i<=n; i++) {
		if (!vis[i]) {
			ll z = test(i);
			if (z != 0) {
				cout << "NO\n";
				return 0;
			}
		}
	}

	// resi
	while (1) {
		bool f = false;
		for (int x=1; x<=n; x++) {
			if (e[x].size() == 1) {
				int y = *e[x].begin();
				if (a[x] > b[x])
					push(x, x, a[x]-b[x]);
				else
					pull(x, x, b[x]-a[x]);

				e[x].erase(y);
				e[y].erase(x);
				f = 1;
				break;
			}
		}

		if (!f)
			break;
	}

	cout << sol.size() << '\n';
	for (auto a : sol)
		cout << a[0] << ' ' << a[1] << ' ' << a[2] << '\n';
}