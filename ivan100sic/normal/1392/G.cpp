// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, m, k, u, v;

struct perm {
	int a[20];

	perm() {
		iota(a, a+k, 0);
	}

	perm operator* (const perm& b) const {
		perm c;
		for (int i=0; i<k; i++) {
			c.a[i] = b.a[a[i]];
		}
		return c;
	}

	int operator() (int x) const {
		int y = 0;
		for (int i=0; i<k; i++) {
			if (x & (1 << i)) {
				y += 1 << a[i];
			}
		}
		return y;
	}
};

perm zi[1000005];
int ui[1000005], vi[1000005];

int d[21][1 << 20];

int rds() {
	int x = 0;
	string s;
	cin >> s;
	for (int i=0; i<k; i++) {
		if (s[i] == '1') {
			x += 1 << i;
		}
	}
	return x;
}

void mn(int& x, int y) {
	x = min(x, y);
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m >> k;
	u = rds();
	v = rds();

	zi[0] = {};
	for (int i=0; i<n; i++) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		perm t;
		swap(t.a[x], t.a[y]);
		zi[i+1] = t * zi[i];
	}

	for (int i=0; i<=n; i++) {
		ui[i] = zi[i](u);
		vi[i] = zi[i](v);
	}

	memset(d, 63, sizeof d);

	for (int i=0; i<=n; i++) {
		int x = ui[i];
		mn(d[0][x], i);
	}

	for (int j=0; j<k; j++) {
		for (int x=0; x<(1<<k); x++) {
			mn(d[j+1][x], d[j][x]);
			for (int r=0; r<k; r++) {
				mn(d[j+1][x^(1<<r)], d[j][x]);
			}
		}
	}

	int doo = 123123123, lo = -1, ro = -1;

	for (int j=m; j<=n; j++) {
		int x = vi[j];
		for (int dd=0; dd<=k; dd++) {
			if (d[dd][x] <= j-m) {
				if (dd < doo) {
					doo = dd;
					lo = d[dd][x];
					ro = j;
				}
			}
		}
	}

	cout << k-doo << '\n' << lo+1 << ' ' << ro << '\n';
}