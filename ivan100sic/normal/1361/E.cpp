// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count());

// global
int n;
basic_string<int> e[100005], sol;

// rundfs global
bool st[100005];
int t[100005], dt;
int c[100005], d[100005];
ll h[100005];
bool ok;
vector<pair<int, int>> bck;
basic_string<int> f[100005];

void be(int x, int y) {
	bck.emplace_back(x, y);
	f[x] += y;
}

void dfs1(int x) {
	st[x] = 1;
	t[x] = dt++;
	for (int y : e[x]) {
		if (st[y]) {
			// back-edge
			be(x, y);
		} else if (t[y] != -1) {
			ok = 0;
			// cross ili fwd edge
		} else {
			dfs1(y);
		}
	}
	st[x] = 0;
}

void dfs2(int x) {
	for (int y : e[x]) {
		if (t[y] > t[x]) {
			dfs2(y);
			c[x] += c[y];
			h[x] += h[y];
		}
	}
}

// obradi 1-2
void dfs3(int x) {
	d[x] = c[x];
	if (c[x] == 1) {
		// prove your worth
		int anc = h[x];
		if (d[anc] > 1) {
			d[x] = 2;
		}
	}

	for (int y : e[x]) {
		if (t[y] > t[x]) {
			dfs3(y);
		}
	}
}

// obradi 0
void dfs4(int x) {
	for (int y : e[x]) {
		if (t[y] > t[x]) {
			if (d[x] == 0) {
				d[y] = 0;
			}
			dfs4(y);
		}
	}
}

bool rundfs(int r) {
	dt = 0;
	ok = 1;
	bck = {};
	for (int i=0; i<n; i++) {
		st[i] = 0;
		t[i] = -1;
		c[i] = 0;
		h[i] = 0;
		f[i] = {};
	}

	dfs1(r);

	if (!ok) return 0;
	for (int i=0; i<n; i++) if (t[i] == -1) return 0;

	// ok looks good
	for (auto [x, y] : bck) {
		c[x]++;
		h[x] += y;
		c[y]--;
		h[y] -= y;
	}

	sol = {};
	dfs2(r);
	c[r] = 1;
	h[r] = r;

	// cerr << "root = " << r << '\n';
	// for (int i=0; i<n; i++) {
	// 	cerr << "info " << i << ' ' << c[i] << '\n';
	// }

	dfs3(r);
	dfs4(r);
	// cerr << '\n';

	// for (int i=0; i<n; i++) {
	// 	cerr << "info " << i << ' ' << d[i] << '\n';
	// }

	for (int i=0; i<n; i++) if (d[i] == 1) sol += i;

	return true;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int m;
		cin >> n >> m;
		for (int i=0; i<n; i++) e[i] = {};
		sol = {};
		while (m--) {
			int x, y;
			cin >> x >> y;
			x--, y--;
			e[x] += y;
		}

		int rep = 60;
		while (rep > 0) {
			rep--;
			int x = uniform_int_distribution<int>(0, n-1)(eng);
			if (rundfs(x)) {

				// cerr << "huh?\n";
				// cerr << sol.size() << '\n';

				if ((int)sol.size() * 5 < n) {
					cout << "-1\n";
					rep = 1;
					break;
				}

				sort(begin(sol), end(sol));
				for (int x : sol) cout << x+1 << ' ';
				cout << '\n';
				rep = 1;
				break;
			}
		}

		if (!rep) {
			cout << "-1\n";
		}
	}
}