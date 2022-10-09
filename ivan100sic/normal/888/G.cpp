#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct dsu {
	vector<int> p;

	dsu(int n) : p(n) {
		iota(p.begin(), p.end(), 0);
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

ll brut(vector<int> a) {
	int n = a.size();
	vector<array<int, 3>> g;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			g.push_back({a[i] ^ a[j], i, j});
		}
	}
	sort(g.begin(), g.end());
	dsu d(n);
	ll z = 0;
	for (auto a : g)
		if (d.spoji(a[1], a[2]))
			z += a[0];
	return z;
}

ll pokusaj(vector<int> a, int b = 1 << 29) {
	if (b == 0 || a.size() == 0)
		return 0;
	vector<int> l, r;
	ll z = 0;
	for (int x : a)
		if (x & b)
			l.push_back(x);
		else
			r.push_back(x - b);
	if (l.size() && r.size())
		z += b;
	return z + pokusaj(l, b >> 1) + pokusaj(r, b >> 1);
}

struct node {
	int l, r;
} b[200000 * 32]; int bsz;

int n;
int a[200005];
ll sol;

void scan(int l, int r, const int v, const int bi) {
	if (l == r)
		return;
	int lo = 1e9;
	for (int i=l; i<r; i++) {
		int x = a[i], z = 0;
		int u = v, bit = bi >> 1;
		// cerr << "seeking " << x << " in " << v << " bit " << bit << '\n';
		while (bit > 0) {
			if (x & bit) {
				if (b[u].r) {
					u = b[u].r;
				} else {
					z += bit;
					u = b[u].l;
				}
			} else {
				if (b[u].l) {
					u = b[u].l;
				} else {
					z += bit;
					u = b[u].r;
				}
			}
			bit >>= 1;
		}
		// cerr << "ended up in " << u << ' ' << z << '\n';
		lo = min(lo, z);
	}
	sol += lo + bi;
}

int resi(int l, int r, int bit) {
	if (l == r)
		return 0;
	if (bit == 0)
		return ++bsz;
	int m = find_if(a+l, a+r, [&](int x) { return x & bit; }) - a;
	int u = resi(l, m, bit >> 1);
	int v = resi(m, r, bit >> 1);
	if (m-l < r-m) {
		scan(l, m, v, bit);
	} else {
		scan(m, r, u, bit);
	}
	int z = ++bsz;
	b[z].l = u;
	b[z].r = v;
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];
	sort(a, a+n);
	resi(0, n, 1 << 29);
	cout << sol << '\n';
}