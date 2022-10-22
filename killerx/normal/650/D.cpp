#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

struct dy_seg {
	static const int maxn = 11111111;
	static const int mod = 998244353;
	struct T {
		int ls, rs;
		pair <int, int> mx;
	} tr[maxn];
	int tot, rt;
	void clear() {
		tot = rt = 0;
	}
	int new_node() {
		int x = ++ tot;
		tr[x].mx = mp(0, 0); tr[x].ls = tr[x].rs = 0;
		return x;
	}
	pair <int, int> merge(pair <int, int> a, pair <int, int> b) {
		pair <int, int> c;
		c.first = max(a.first, b.first);
		c.second = 0;
		if (a.first == c.first) c.second += a.second;
		if (c.second >= mod) c.second -= mod;
		if (b.first == c.first) c.second += b.second;
		if (c.second >= mod) c.second -= mod;
		return c;
	}
	void upd(int &i, int a, int b, int x, pair <int, int> v) {
		if (!i) i = new_node();
		if (a == b) {
			tr[i].mx = merge(tr[i].mx, v);
			return ;
		}
		int m = (a + b) >> 1;
		if (x <= m) upd(tr[i].ls, a, m, x, v);
		else upd(tr[i].rs, m + 1, b, x, v);
		tr[i].mx = merge(tr[tr[i].ls].mx, tr[tr[i].rs].mx);
	}
	pair <int, int> qry(int i, int a, int b, int l, int r) {
		if (!i) return mp(0, 0);
		if (l <= a && b <= r) return tr[i].mx;
		int m = (a + b) >> 1;
		pair <int, int> ans = mp(0, 0);
		if (l <= m) ans = merge(ans, qry(tr[i].ls, a, m, l, r));
		if (r >= m + 1) ans = merge(ans, qry(tr[i].rs, m + 1, b, l, r));
		return ans;
	}
} seg;

const int maxn = 4e5 + 5;
int n, q, a[maxn];
int f[maxn], g[maxn];
int fc[maxn], gc[maxn];
pair <int, int> mx, over[maxn];
int ans1[maxn], ans2[maxn];
vector <pair <int, int> > qry[maxn];

int main() {
	scanf("%d %d", &n, &q);
	rep(i, n) scanf("%d", &a[i]);
	seg.clear();
	rep(i, n) {
		pair <int, int> p = seg.qry(seg.rt, 1, 1e9, 1, a[i] - 1);
		if (!p.first && !p.second) p.second = 1;
		f[i] = p.first + 1; fc[i] = p.second;
		seg.upd(seg.rt, 1, 1e9, a[i], mp(f[i], fc[i]));
	}
	seg.clear();
	for (int i = n - 1; ~i; -- i) {
		pair <int, int> p = seg.qry(seg.rt, 1, 1e9, a[i] + 1, 1e9);
		if (!p.first && !p.second) p.second = 1;
		g[i] = p.first + 1, gc[i] = p.second;
		seg.upd(seg.rt, 1, 1e9, a[i], mp(g[i], gc[i]));
	}
	rep(i, n) {
		over[i].first = f[i] + g[i] - 1;
		over[i].second = 1LL * fc[i] * gc[i] % dy_seg::mod;
		mx = seg.merge(mx, mp(f[i], fc[i]));
	}
	rep(i, q) {
		int x, v;
		scanf("%d %d", &x, &v);
		-- x;
		// not over
		ans1[i] = mx.first;
		if (over[x] == mx) -- ans1[i];
		qry[x].pb(mp(i, v));
	}
	// over
	rep(i, q) ans2[i] ++;
	// F
	seg.clear();
	rep(i, n) {
		rep(j, qry[i].size()) {
			int id = qry[i][j].first;
			int v = qry[i][j].second;
			pair <int, int> p = seg.qry(seg.rt, 1, 1e9, 1, v - 1);
			ans2[id] += p.first;
		}
		seg.upd(seg.rt, 1, 1e9, a[i], mp(f[i], fc[i]));
	}
	// G
	seg.clear();
	for (int i = n - 1; ~i; -- i) {
		rep(j, qry[i].size()) {
			int id = qry[i][j].first;
			int v = qry[i][j].second;
			pair <int, int> p = seg.qry(seg.rt, 1, 1e9, v + 1, 1e9);
			ans2[id] += p.first;
		}
		seg.upd(seg.rt, 1, 1e9, a[i], mp(g[i], gc[i]));
	}
	rep(i, q) printf("%d\n", max(ans1[i], ans2[i]));
	return 0;
}