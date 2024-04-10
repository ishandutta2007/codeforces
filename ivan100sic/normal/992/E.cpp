#include <bits/stdc++.h>
using namespace std;

// ja sam

const int MAXN = 262144;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, q;
ll z[200005], a[200005];

const ll INF = 2123123123123123123ll;

struct stb {
	struct node {
		ll b, lo, hi;
		int z;

		node& operator+= (const node& o) {
			lo = min(lo, o.lo);
			hi = max(hi, o.hi);
			z = max(z, o.z);
			return *this;
		}

		node operator+ (const node& o) const {
			node tmp = *this;
			tmp += o;
			return tmp;
		}
	};

	node d[2*MAXN];

	void push(int i) {
		if (d[i].b == 0)
			return;

		if (i >= MAXN) {
			d[i].lo += d[i].b;
			d[i].hi += d[i].b;
			d[i].z = d[i].lo == 0 ? i - MAXN + 1 : -1;
			d[i].b = 0;
			return;
		}

		if (!(d[i].lo + d[i].b <= 0 && 0 <= d[i].hi + d[i].b)) {
			d[i].lo += d[i].b;
			d[i].hi += d[i].b;
			d[2*i].b += d[i].b;
			d[2*i+1].b += d[i].b;
			d[i].b = 0;
			d[i].z = -1;
			return;
		}

		d[2*i].b += d[i].b;
		d[2*i+1].b += d[i].b;
		push(2*i);
		push(2*i+1);
		d[i] = d[2*i] + d[2*i+1];
	}

	void init() {
		for (int i=1; i<=n; i++)
			d[i + MAXN - 1] = {0, z[i], z[i], z[i] == 0 ? i : -1};
		for (int i=n+1; i<=MAXN; i++)
			d[i + MAXN - 1] = {0, INF, INF, -1};

		for (int i=MAXN-1; i>=1; i--)
			d[i] = d[2*i] + d[2*i+1];
	}

	void add(int l, int r, ll val, int x = 1, int xl = 1, int xr = MAXN) {
		push(x);
		if (r < xl || xr < l)
			return;
		if (l <= xl && xr <= r) {
			d[x].b += val;
			push(x);
			return;
		}

		int xm = (xl + xr) >> 1;
		add(l, r, val, 2*x, xl, xm);
		add(l, r, val, 2*x+1, xm+1, xr);

		d[x] = d[2*x] + d[2*x+1];
	}

	int nula() {
		push(1);
		return d[1].z;
	}

} drvo;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q;

	ll ps = 0;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		a[i] = x;
		z[i] = x - ps;
		ps += x;
	}

	drvo.init();

	for (int i=1; i<=q; i++) {
		int p;
		ll v;
		cin >> p >> v;
		v -= a[p];
		a[p] += v;

		drvo.add(p, p, v);
		if (p != n)
			drvo.add(p+1, n, -v);
		cout << drvo.nula() << '\n';
	}
}