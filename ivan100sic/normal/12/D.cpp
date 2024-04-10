// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
int a[500005], b[500005], c[500005];

void compress(int* a) {
	vector<pair<int, int>> v(n);
	for (int i=0; i<n; i++)
		v[i] = {a[i], i};
	sort(begin(v), end(v));

	int z = 0;
	for (int i=0; i<n; i++) {
		if (i && v[i].first == v[i-1].first) {
			a[v[i].second] = z;
		} else {
			a[v[i].second] = ++z;
		}
	}
}

int e[500005];

const int maxn = 1 << 19;

struct segtree {
	vector<int> a;

	segtree() : a(2*maxn, -1) {}

	void update(int x, int y) {
		x += maxn;
		while (x > 0) {
			a[x] = max(a[x], y);
			x >>= 1;
		}
	}

	int read(int l, int r, int x=1, int xl=0, int xr=maxn) {
		if (r <= xl || xr <= l)
			return -1;
		if (l <= xl && xr <= r)
			return a[x];
		int xm = (xl+xr) >> 1;
		return max(read(l, r, 2*x, xl, xm), read(l, r, 2*x+1, xm, xr));
	}

	int operator() (int l, int r) {
		return read(l, r);
	}
};

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i], e[i] = i;
	for (int i=0; i<n; i++)
		cin >> b[i];
	for (int i=0; i<n; i++)
		cin >> c[i];

	compress(a);
	compress(b);
	compress(c);

	sort(e, e+n, [&](int i, int j) {
		return a[i] > a[j];
	});

	segtree tree;

	int solution = 0;

	for (int i=0; i<n;) {
		int j = i;
		while (j < n && a[e[i]] == a[e[j]])
			j++;
		//
		// (b, c),  x = b+1 ... N, is there as y, s.t. (x, y)   (b', c') : b' > b, c' > c
		for (int k=i; k<j; k++) {
			int id = e[k];
			int result = tree(b[id]+1, maxn);
			if (result > c[id]) {
				solution++;
			}
		}

		for (int k=i; k<j; k++) {
			int id = e[k];
			tree.update(b[id], c[id]);
		}

		i = j;
	}

	cout << solution << '\n';
}