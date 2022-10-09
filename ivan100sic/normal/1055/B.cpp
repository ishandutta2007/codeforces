#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct dsu {
	vector<int> p;
	int cc;

	dsu(int n) : p(n) {
		iota(p.begin(), p.end(), 0);
		cc = 0;
	}

	int e(int x) {
		if (x == p[x])
			return x;
		return p[x] = e(p[x]);
	}

	void merge(int x, int y) {
		x = e(x);
		y = e(y);
		if (x == y)
			return;
		p[x] = y;
		cc++;
	}
};

int n, q, l;
ll a[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q >> l;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	dsu ds(n+1);

	int active = 0;

	for (int i=1; i<=n; i++) {
		if (a[i] > l) {
			active++;
			if (a[i-1] > l) {
				ds.merge(i, i-1);
			}
		}
	}

	while (q--) {
		int t;
		cin >> t;
		if (t == 0) {
			cout << active - ds.cc << '\n';
		} else {
			int x, y;
			cin >> x >> y;
			if (a[x] + y > l && a[x] <= l)
				active++;
			a[x] += y;
			if (a[x] > l) {
				if (a[x-1] > l)	ds.merge(x, x-1);
				if (a[x+1] > l)	ds.merge(x, x+1);
			}
		}
	}

}