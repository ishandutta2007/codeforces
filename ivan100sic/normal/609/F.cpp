// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

template<class T, class U, class F, class G, class H, class W>
struct implicit_segtreelazy {
	struct node { T v; U u; int l; int r; };

	static inline W midpoint(W l, W r) { return l + (W)(((typename make_unsigned<W>::type)(r)-l) >> 1); }
	node dn() { return {e, eu, ~0, ~0}; }
	int nn() { a.push_back(dn()); return a.size() - 1; }
	bool is_leaf(W l, W r) { return r-l == 1; }

	T e; U eu;
	F f; G g; H h;
	W rl, rr;
	vector<node> a;

	// Add two elements
	// Add two updaters
	// Add an element and an update
	// index range
	// Neutral element
	// Neutral update
	implicit_segtreelazy(F f, G g, H h, W rl, W rr, T e = T(), U eu = U()) :
		e(e), eu(eu), f(f), g(g), h(h), rl(rl), rr(rr), a(1, dn()) {}

	void push(int x, bool leaf) {
		a[x].v = h(a[x].v, a[x].u);
		if (!leaf) {
			if (!~a[x].l) a[x].l = nn();
			if (!~a[x].r) a[x].r = nn();
			a[a[x].l].u = g(a[a[x].l].u, a[x].u);
			a[a[x].r].u = g(a[a[x].r].u, a[x].u);
		}
		a[x].u = eu;
	}

	int update(W l, W r, const U& u, int x, W xl, W xr) {
		if (r <= xl || xr <= l)
			return push(x, is_leaf(xl, xr)), x;
		if (l <= xl && xr <= r)
			return a[x].u = g(a[x].u, u), push(x, is_leaf(xl, xr)), x;
		push(x, is_leaf(xl, xr));
		W xm = midpoint(xl, xr);
		a[x].l = update(l, r, u, a[x].l, xl, xm);
		a[x].r = update(l, r, u, a[x].r, xm, xr);
		a[x].v = f(a[a[x].l].v, a[a[x].r].v);
		return x;
	}

	T get(W l, W r, int x, W xl, W xr) {
		if (r <= xl || xr <= l)
			return e;
		push(x, is_leaf(xl, xr));
		if (l <= xl && xr <= r)
			return a[x].v;
		W xm = midpoint(xl, xr);
		return f(get(l, r, a[x].l, xl, xm), get(l, r, a[x].r, xm, xr));
	}

	void update(W l, W r, const U& u) { update(l, r, u, 0, rl, rr); }
	T operator() (W l, W r) { return get(l, r, 0, rl, rr); }
};

const int inf = int(2e9);
int n, m;
ll t[200005];
int x[200005], br[200005];
map<int, int> xtoi;
int qb[200005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	auto mn = [](int x, int y) { return min(x, y); };

	implicit_segtreelazy must(mn, mn, mn, 0ll, ll(1e15), inf, inf);

	must.a.reserve(31250000);

	auto upd = [&](int i) {
		must.update(x[i], x[i] + t[i] + 1, x[i]);
	};

	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> x[i] >> t[i];
		upd(i);
		xtoi[x[i]] = i;
	}

	set<pair<int, int>> mq;

	for (int q=0; q<m; q++) {
		int p, b;
		cin >> p >> b;
		qb[q] = b;
		int xx = must(p, p+1);
		if (xx != inf) {
			int i = xtoi[xx];
			t[i] += b;
			br[i]++;
			upd(i);
			while (1) {
				auto it = mq.lower_bound({x[i], -1});
				if (it == mq.end() || it->first > x[i] + t[i]) {
					break;
				}

				b = qb[it->second];
				t[i] += b;
				br[i]++;
				upd(i);
				mq.erase(it);
			}
		} else {
			mq.insert({p, q});
		}
	}

	for (int i=0; i<n; i++) {
		cout << br[i] << ' ' << t[i] << '\n';
	}
}