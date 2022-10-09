#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <list>
#include <bitset>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int N = 131072;
int n, m;
vector<int> e[100005];
int a[100005], b[100005], l[100005], inv[100005], t, r[100005];

bitset<1024> mmask, pmask;

struct node {
	bitset<1024> a;
	int extra; // redukovano mod m

	node() : extra(0) {}
};

struct segtree {
	vector<node> a;

	segtree() : a(2 * N) {}

	void init() {
		for (int i = 1; i <= n; i++) {
			a[i + N - 1].a[b[i]] = 1;
		}
		for (int i = N - 1; i > 0; i--) {
			a[i].a = a[2 * i].a | a[2 * i + 1].a;
		}
	}

	void push(int x) {
		if (a[x].extra == 0) {
			return;
		}
		if (x < N) {
			a[2 * x].extra += a[x].extra;
			if (a[2 * x].extra >= m) {
				a[2 * x].extra -= m;
			}
			a[2 * x + 1].extra += a[x].extra;
			if (a[2 * x + 1].extra >= m) {
				a[2 * x + 1].extra -= m;
			}
		}
		auto tmp = a[x].a >> (m - a[x].extra);
		a[x].a = (a[x].a << a[x].extra) ^ tmp;
		a[x].a &= mmask;
		a[x].extra = 0;
	}

	bitset<1024> get(int l, int r, int x, int xl, int xr) {
		push(x);
		if (r < xl || xr < l) {
			return bitset<1024>();
		}
		if (l <= xl && xr <= r) {
			return a[x].a;
		}
		int xm = (xl + xr) >> 1;
		return get(l, r, 2 * x + 0, xl, xm) | get(l, r, 2 * x + 1, xm + 1, xr);
	}

	void update(int l, int r, int y, int x, int xl, int xr) {
		if (r < xl || xr < l) {
			push(x);
			return;
		}
		if (l <= xl && xr <= r) {
			a[x].extra += y;
			if (a[x].extra >= m) {
				a[x].extra -= m;
			}
			push(x);
			return;
		}

		push(x);
		int xm = (xl + xr) >> 1;
		update(l, r, y, 2 * x, xl, xm);
		update(l, r, y, 2 * x + 1, xm + 1, xr);
		a[x].a = a[2 * x].a | a[2 * x + 1].a;
	}
};

void dfs(int x, int p) {
	l[x] = ++t;
	inv[t] = x;
	for (int y : e[x]) {
		if (y != p) {
			dfs(y, x);
		}
	}
	r[x] = t;
}

vector<int> prosti;
int f[1005];

void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] %= m;
	}

	for (int i = 1; i < n; i++) {
		int x, y;
		cin >> x >> y;
		e[x].push_back(y);
		e[y].push_back(x);
	}

	for (int i = 2; i < m; i++) {
		if (f[i] == 0) {
			prosti.push_back(i);
			for (int j = i * i; j < m; j += i) {
				f[j] = 1;
			}
		}
	}

	for (int p : prosti) {
		pmask[p] = 1;
	}

	for (int i = 0; i < m; i++) {
		mmask[i] = 1;
	}

	dfs(1, 1);
	for (int i = 1; i <= n; i++) {
		b[i] = a[inv[i]];
	}

	segtree drvo;
	drvo.init();

	int q;
	cin >> q;
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int v, x;
			cin >> v >> x;
			x %= m;
			drvo.update(l[v], r[v], x, 1, 1, N);
		}
		else {
			int v;
			cin >> v;
			cout << (drvo.get(l[v], r[v], 1, 1, N) & pmask).count() << '\n';
		}
	}
}

int main() {
	solve();
#ifdef _MSVC_STL_VERSION
	system("pause");
#endif
}