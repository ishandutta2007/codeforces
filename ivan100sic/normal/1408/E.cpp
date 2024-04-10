// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct union_find {
	vector<int> p;
	union_find(int n) : p(n) { iota(begin(p), end(p), 0); }
	bool operator() (int x, int y) { return e(x) == e(y); }
	int e(int x) {
		if (p[x] == x) return x;
		return p[x] = e(p[x]);
	}
	bool join(int x, int y) {
		x = e(x), y = e(y);
		if (x == y) return false;
		p[x] = y;
		return true;
	}
};

int m, n;
ll sol;
int a[100005], b[100005];
vector<tuple<int, int, int>> g;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> m >> n;
	for (int i=1; i<=m; i++) cin >> a[i];
	for (int i=1; i<=n; i++) cin >> b[i];

	for (int i=1; i<=m; i++) {
		int t;
		cin >> t;
		while (t--) {
			int x;
			cin >> x;
			// grana
			g.emplace_back(a[i] + b[x], i, m+x);
		}
	}

	union_find uf(n+m+1);

	sort(begin(g), end(g));
	reverse(begin(g), end(g));
	for (auto [w, x, y] : g) {
		if (!uf(x, y)) {
			uf.join(x, y);
		} else {
			sol += w;
		}
	}

	cout << sol << '\n';
}