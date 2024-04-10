#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct segtree {
	int maxn;
	vector<int> a;

	segtree(int n) {
		maxn = 1;
		while (maxn < n)
			maxn <<= 1;
		a.resize(2*maxn, 2e9);
	}

	void update(int x, int y) {
		x += maxn;
		a[x] = y;
		while (x > 1) {
			x >>= 1;
			a[x] = min(a[2*x], a[2*x+1]);
		}
	}

	int query(int l, int r, int x, int xl, int xr) {
		if (r < xl || xr < l)
			return 2e9;
		if (l <= xl && xr <= r)
			return a[x];
		int xm = (xl+xr) >> 1;
		return min(query(l, r, 2*x, xl, xm),
			query(l, r, 2*x+1, xm+1, xr));
	}

	int query(int l, int r) {
		return query(l, r, 1, 0, maxn-1);
	}
};

bool solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	segtree drvo(n);
	for (int i=0; i<n; i++) {
		cin >> a[i];
		drvo.update(i, a[i]);
	}
	for (int i=0; i<n; i++)
		cin >> b[i];

	vector<vector<int>> posa(n+1);
	for (int i=0; i<n; i++)
		posa[a[i]].push_back(i);
	for (int i=1; i<=n; i++)
		reverse(posa[i].begin(), posa[i].end());


	for (int i=0; i<n; i++) {
		int x = b[i];
		if (posa[x].empty())
			return false;
		int j = posa[x].back();
		posa[x].pop_back();
		if (drvo.query(0, j) != x)
			return false;
		drvo.update(j, 2e9);
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		cout << (solve() ? "YES\n" : "NO\n");
	}
}