#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ull B = 7431874187341;

struct node {
	int l, r, sum;
	ull hsh, hb;
	node() : l(0), r(0), sum(0), hsh(0), hb(1) {}
} b[15000005]; int sz = 1;

void pull(int x) {
	b[x].sum = b[b[x].l].sum + b[b[x].r].sum;
	b[x].hsh = b[b[x].l].hsh * b[b[x].r].hb + b[b[x].r].hsh;
	b[x].hb = b[b[x].l].hb * b[b[x].r].hb;
}

int update1(int p, int x, int xl=0, int xr=111111) {
	b[sz] = b[x];
	x = sz++;
	if (xl == xr) {
		b[x].sum = 1;
		b[x].hsh = 1;
		b[x].hb = B;
	} else {
		int xm = (xl+xr) >> 1;
		if (p <= xm)
			b[x].l = update1(p, b[x].l, xl, xm);
		else
			b[x].r = update1(p, b[x].r, xm+1, xr);
		pull(x);
	}
	return x;
}

int update0(int l, int r, int x, int g0x, int xl=0, int xr=111111) {
	if (r < xl || xr < l)
		return x;

	if (l <= xl && xr <= r) {
		return g0x;
	} else {
		b[sz] = b[x];
		x = sz++;
		int xm = (xl+xr) >> 1;
		b[x].l = update0(l, r, b[x].l, b[g0x].l, xl, xm);
		b[x].r = update0(l, r, b[x].r, b[g0x].r, xm+1, xr);
		pull(x);
	}
	return x;
}

int rangesum(int l, int r, int x, int xl=0, int xr=111111) {
	if (r < xl || xr < l || !x)
		return 0;
	if (l <= xl && xr <= r)
		return b[x].sum;
	int xm = (xl+xr) >> 1;
	return rangesum(l, r, b[x].l, xl, xm) + rangesum(l, r, b[x].r, xm+1, xr);
}

int treecmp(int x, int y, int xl=0, int xr=111111) {
	if (b[x].hsh == b[y].hsh)
		return 0;

	if (xl == xr)
		return b[x].sum - b[y].sum;

	int xm = (xl+xr) >> 1;
	int t = treecmp(b[x].r, b[y].r, xm+1, xr);
	if (t)
		return t;
	return treecmp(b[x].l, b[y].l, xl, xm);
}

int increment(int x, int p, int g0x) {
	int l = p, r = 111111, o = p-1;
	while (l <= r) {
		int m = (l+r) >> 1;
		if (rangesum(p, m, x) == m-p+1) {
			o = m;
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	if (p <= o)
		x = update0(p, o, x, g0x);
	x = update1(o+1, x);
	return x;
}

int gen0(int xl=0, int xr=111111) {
	int x = sz++;
	if (xl == xr) {
		b[x].sum = 0;
		b[x].hsh = 0;
		b[x].hb = B;
	} else {
		int xm = (xl+xr) >> 1;
		b[x].l = gen0(xl, xm);
		b[x].r = gen0(xm+1, xr);
		pull(x);
	}
	return x;
}

int gen1(int xl=0, int xr=111111) {
	int x = sz++;
	if (xl == xr) {
		b[x].sum = 1;
		b[x].hsh = 1;
		b[x].hb = B;
	} else {
		int xm = (xl+xr) >> 1;
		b[x].l = gen1(xl, xm);
		b[x].r = gen1(xm+1, xr);
		pull(x);
	}
	return x;
}

const int mod = 1'000'000'007;

int gbuf[111115];

void gather(int x, int xl, int xr) {
	if (!x)
		return;
	if (xl == xr) {
		gbuf[xl] = b[x].sum;
	} else {
		int xm = (xl+xr) >> 1;
		gather(b[x].l, xl, xm);
		gather(b[x].r, xm+1, xr);
	}
}

int gather(int x) {
	memset(gbuf, 0, sizeof gbuf);
	gather(x, 0, 111111);
	int z = 0;
	for (int i=111111; i>=0; i--) {
		z = (z << 1) + gbuf[i];
		if (z >= mod)
			z -= mod;
	}
	return z;
}

struct handle {
	int x, y;
	handle(int x, int y) : x(x), y(y) {}

	bool operator< (const handle& b) const {
		int t = treecmp(x, b.x);
		if (t != 0)
			return t < 0;
		return y < b.y;
	}
};

int n, m;
vector<pair<int, int>> e[100005];
int dh[100005], pr[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[u].emplace_back(v, w);
		e[v].emplace_back(u, w);
	}

	int s, t;
	cin >> s >> t;
	int g0 = gen0(), g1 = gen1();
	dh[s] = g0;
	for (int i=1; i<=n; i++)
		if (i != s)
			dh[i] = g1;

	set<handle> pq;
	pq.insert(handle(dh[s], s));

	while (pq.size()) {
		auto [d, x] = *pq.begin();
		pq.erase(pq.begin());
		for (auto [y, w] : e[x]) {
			int t = increment(d, w, g0);
			if (treecmp(t, dh[y]) < 0) {
				pq.erase(handle(dh[y], y));
				dh[y] = t;
				pq.insert(handle(dh[y], y));
				pr[y] = x;
			}
		}
	}

	if (treecmp(dh[t], g1) == 0) {
		cout << "-1\n";
		return 0;
	}

	basic_string<int> path;
	for (int y = t; y != s; y = pr[y])
		path += y;
	path += s;
	reverse(path.begin(), path.end());

	cout << gather(dh[t]) << '\n';
	cout << path.size() << '\n';
	for (int x : path)
		cout << x << ' ';
	cout << '\n';
}