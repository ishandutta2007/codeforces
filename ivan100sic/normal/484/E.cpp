#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct ndata {
	int p, s, w, m;

	ndata() : p(0), s(0), w(0), m(0) {}

	ndata(int x) : p(x), s(x), w(1), m(x) {}

	ndata operator+ (const ndata& b) const {
		ndata tmp;
		tmp.p = p + (p == w ? b.p : 0);
		tmp.s = b.s + (b.s == b.w ? s : 0);
		tmp.w = w + b.w;
		tmp.m = max({s + b.p, m, b.m});
		return tmp;
	}
};

struct node {
	int l, r;
	ndata v;
};

node b[100005 * 21 * 2];
int bsz = 1;

int update(int x, int p, int v, int xl=0, int xr=100001) {
	b[bsz+1] = b[x];
	x = ++bsz;

	if (xl == xr) {
		b[x].v = ndata(v);
	} else {
		int xm = (xl+xr) >> 1;
		if (p <= xm) {
			b[x].l = update(b[x].l, p, v, xl, xm);
		} else {
			b[x].r = update(b[x].r, p, v, xm+1, xr);
		}
		b[x].v = b[b[x].l].v + b[b[x].r].v;
	}

	return x;
}

ndata query(int x, int l, int r, int xl=0, int xr=100001) {
	if (r < xl || xr < l || !x)
		return ndata();
	if (l <= xl && xr <= r)
		return b[x].v;
	int xm = (xl+xr) >> 1;
	return query(b[x].l, l, r, xl, xm) + query(b[x].r, l, r, xm+1, xr);
}

int root[100005];

int n, un;
int h[100005], uh[100005];
basic_string<int> he[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> h[i];
		uh[i-1] = h[i];
	}
	sort(uh, uh+n);
	un = unique(uh, uh+n) - uh;
	reverse(uh, uh+un);
	for (int i=1; i<=n; i++) {
		int x = lower_bound(uh, uh+un, h[i], greater<int>()) - uh;
		he[x] += i;
	}

	{
		int x = 0;
		for (int i=1; i<=n; i++)
			x = update(x, i, 0);
		root[0] = x;
	}

	for (int i=0; i<un; i++) {
		int x = root[i];
		for (int j : he[i])
			x = update(x, j, 1);
		root[i+1] = x;
	}

	// {
	// 	auto [p, s, w, m] = query(root[1], 2, 5);
	// 	cerr << p << ' ' << s << ' ' << w << ' ' << m << '\n';
	// }

	int q;
	cin >> q;
	while (q--) {
		int u, v, w;
		cin >> u >> v >> w;
		int l = 1, r = un, o = 0;
		while (l <= r) {
			int m = (l+r) >> 1;
			if (query(root[m], u, v).m >= w) {
				o = m;
				r = m - 1;
			} else {
				l = m + 1;
			}
		}
		cout << uh[o-1] << '\n';
	}
}