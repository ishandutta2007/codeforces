#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct node {
	int mn, lz, cnt;

	node() : mn(123123123), lz(0), cnt(0) {}
	node operator+ (const node& b) const {
		node t;
		t.lz = 0;
		t.mn = min(mn, b.mn);
		if (mn <= b.mn)
			t.cnt = cnt;
		else
			t.cnt = b.cnt;
		return t;
	}
};

const int maxn = 524288;

struct sgtl {
	vector<node> b;

	sgtl() : b(2*maxn) {
		for (int i=0; i<maxn; i++) {
			b[i+maxn].mn = 0;
			b[i+maxn].cnt = i;
			b[i+maxn].lz = 0;
		}

		for (int i=maxn-1; i; i--)
			pull(i);
	}

	void pull(int x) {
		b[x] = b[2*x] + b[2*x+1];
	}

	void push(int x) {
		if (x < maxn) {
			b[2*x].lz += b[x].lz;
			b[2*x+1].lz += b[x].lz;
		}
		b[x].mn += b[x].lz;
		b[x].lz = 0;
	}

	void update(int l, int r, int v, int x=1, int xl=0, int xr=maxn-1) {
		if (r < xl || xr < l) {
			push(x);
			return;
		}
		if (l <= xl && xr <= r) {
			b[x].lz += v;
			push(x);
			return;
		}
		push(x);
		int xm = (xl+xr) >> 1;
		update(l, r, v, 2*x, xl, xm);
		update(l, r, v, 2*x+1, xm+1, xr);
		pull(x);
	}

	node query(int l, int r, int x=1, int xl=0, int xr=maxn-1) {
		push(x);
		if (r < xl || xr < l)
			return node();
		if (l <= xl && xr <= r)
			return b[x];
		int xm = (xl+xr) >> 1;
		return query(l, r, 2*x, xl, xm) + query(l, r, 2*x+1, xm+1, xr);
	}
};

struct entry {
	int l, r, x;
};

int n;
int a[300005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	int w = -3;
	vector<int> sol;

	basic_string<entry> gs, ms;
	sgtl drvo;

	for (int i=1; i<=n; i++) {
		for (auto& [l, r, x] : gs) {
			int delta = gcd(x, a[i]) - x;
			if (delta)
				drvo.update(l, r, -delta);
			x += delta;
		}

		drvo.update(i, i, -a[i]);
		gs += {i, i, a[i]};

		{
			int k = 0;
			for (int j=1; j<(int)gs.size(); j++) {
				if (gs[j].x == gs[k].x) {
					gs[k].r = gs[j].r;
				} else {
					gs[++k] = gs[j];
				}
			}
			gs.resize(k+1);
		}

		{
			int l = i;
			while (ms.size() && a[i] <= ms.back().x) {
				auto [u, v, z] = ms.back();
				ms.pop_back();
				drvo.update(u, v, -z);
				l = u;
			}
			ms += {l, i, a[i]};
			drvo.update(l, i, a[i]);
		}

		{
			auto g = drvo.query(1, i);
			int l = g.cnt;
			if (i-l > w) {
				w = i-l;
				sol = {l};
			} else if (i-l == w) {
				sol.push_back(l);
			}
		}
	}

	cout << sol.size() << ' ' << w << '\n';
	for (int x : sol)
		cout << x << ' ';
	cout << '\n';
}