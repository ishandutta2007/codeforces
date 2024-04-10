#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, root;
int a[100005], el[100005], er[100005], dfst;
basic_string<int> e[100005];
int dub[100005];

void dfs1(int x, int p) {
	el[x] = dfst++;
	for (int y : e[x]) {
		if (y == p)
			continue;
		dub[y] = dub[x] + 1;
		dfs1(y, x);
	}
	er[x] = dfst;
}

struct stvar {
	int x, v, l, r;

	bool operator< (const stvar& b) const {
		return x < b.x;
	}
};

const int maxn = 131072;
struct frac {
	vector<vector<stvar>> a;

	frac() : a(2*maxn) {}

	void add(int x, int y, int v) {
		a[x + maxn].push_back({y, v, 0, 0});
	}

	void build() {
		for (int i=maxn; i<2*maxn; i++)
			sort(a[i].begin(), a[i].end());

		for (int i=maxn-1; i>=1; i--) {
			const auto& b = a[2*i];
			const auto& c = a[2*i+1];
			auto& d = a[i];

			d.resize(b.size() + c.size());

			size_t u = 0, v = 0;
			while (u != b.size() || v != c.size()) {
				bool first;
				if (u == b.size())
					first = false;
				else if (v == c.size())
					first = true;
				else
					first = b[u].x < c[v].x;

				d[u+v] = first ? b[u] : c[v];
				d[u+v].l = u;
				d[u+v].r = v;
				(first ? u : v)++;
			}
		}

		for (int i=1; i<2*maxn; i++) {
			int z = 1123123123;
			for (auto& u : a[i])
				u.v = z = min(z, u.v);
		}
	}

	int query(int l, int r, int h, int x, int xl, int xr) {
		if (r < xl || xr < l || h == 0)
			return 1123123123;
		if (l <= xl && xr <= r) {
			return a[x][h-1].v;
		}

		int hl = h == (int)a[x].size() ? a[2*x].size() : a[x][h].l;
		int hr = h == (int)a[x].size() ? a[2*x+1].size() : a[x][h].r;
		int xm = (xl+xr) >> 1;

		return min(
			query(l, r, hl, 2*x, xl, xm),
			query(l, r, hr, 2*x+1, xm+1, xr));
	}

	int query(int l, int r, int y) {
		int h = upper_bound(a[1].begin(), a[1].end(), stvar{y, 0, 0, 0})
			- a[1].begin();
		return query(l, r, h, 1, 0, maxn-1);
	}

} rmq;

int solve(int x, int k) {
	return rmq.query(el[x], er[x]-1, dub[x] + k);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> root;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	for (int i=1; i<n; i++) {
		int x, y;
		cin >> x >> y;
		e[x] += y;
		e[y] += x;
	}

	dfs1(root, root);

	// build
	for (int i=1; i<=n; i++)
		rmq.add(el[i], dub[i], a[i]);
	rmq.build();

	int q;
	cin >> q;
	
	int last = 0;
	while (q--) {
		int x, y;
		cin >> x >> y;
		x = (x + last) % n + 1;
		y = (y + last) % n;
		cout << (last = solve(x, y)) << '\n';
	}
}