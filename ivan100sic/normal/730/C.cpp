#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
basic_string<int> e[5005];
int d[5005][5005];

void bfs(int x, int* d) {
	fill(d+1, d+n+1, 123123123);
	basic_string<int> q = {x};
	size_t qs = 0;
	d[x] = 0;
	while (qs != q.size()) {
		int x = q[qs++];
		for (int y : e[x]) {
			if (d[y] == 123123123) {
				d[y] = d[x] + 1;
				q += y;
			}
		}
	}
}

struct prod {
	int c, k, p;
	bool operator< (const prod& b) const {
		return p < b.p;
	}
};

int w, q;
prod a[5005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	for (int i=1; i<=n; i++)
		bfs(i, d[i]);

	cin >> w;
	for (int i=0; i<w; i++)
		cin >> a[i].c >> a[i].k >> a[i].p;
	sort(a, a+w);

	cin >> q;
	while (q--) {
		int grad, kolicina, pare;
		cin >> grad >> kolicina >> pare;

		int l = 0, r = n, o = -1;
		while (l <= r) {
			int m = (l+r) >> 1;
			int ostalo = kolicina;
			ll ukcena = 0;
			for (int i=0; i<w; i++) {
				if (d[a[i].c][grad] <= m) {
					int delta = min(ostalo, a[i].k);
					ukcena += delta * 1ll * a[i].p;
					ostalo -= delta;
				}
			}
			if (ostalo == 0 && ukcena <= pare) {
				o = m;
				r = m - 1;
			} else {
				l = m + 1;
			}
		}

		cout << o << '\n';
	}
}