#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct line {
	int k, b;
	double start;

	double operator* (ld x) const {
		return k*x + b;
	}

	ll operator* (int x) const {
		return (ll)k*x + b;
	}

	double operator* (line u) const {
		return (double)(b - u.b) / (u.k - k);
	}

	bool operator< (const line& o) const {
		return k < o.k;
	}
};

int n;
line a[300005];
int al[300005], ar[300005];

const int MAXN = 524288;
basic_string<line> c[2 * MAXN];
basic_string<pair<int, int>> q;
int active_idx[2 * MAXN];
ll ans[300005];

void dodaj(int l, int r, line v, int x, int xl, int xr) {
	if (r < xl || xr < l)
		return;
	if (l <= xl && xr <= r) {
		c[x] += v;
		return;
	}
	int xm = (xl + xr) >> 1;
	dodaj(l, r, v, 2*x, xl, xm);
	dodaj(l, r, v, 2*x+1, xm+1, xr);
}

basic_string<line> napravi_hull(basic_string<line> a) {
	sort(a.begin(), a.end());
	basic_string<line> b;
	for (auto v : a) {
		while (b.size()) {
			ld x = b.back().start;
			if (v*x >= b.back()*x)
				b.pop_back();
			else
				break;
		}
		if (b.size() == 0) {
			v.start = -1e30;
			b += v;
		} else if (v.k == b.back().k && v.b <= b.back().b) {
			// nista
		} else {
			v.start = v * b.back();
			b += v;
		}
	}

	return b;
}

ll resi(int x, int i) {
	ll ans = -6123123123123123123;
	for (int j=i+MAXN; j; j>>=1) {
		if (c[j].size() == 0)
			continue;
		int& k = active_idx[j];
		while (k+1 < (int)c[j].size() && c[j][k+1].start <= x)
			k++;
		ans = max(ans, c[j][k] * x);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		int t;
		cin >> t;
		if (t == 1) {
			cin >> a[i].k >> a[i].b;
			al[i] = i;
		} else if (t == 2) {
			int x;
			cin >> x;
			ar[x] = i;
		} else {
			int x;
			cin >> x;
			q += {x, i};
		}
	}

	for (int i=1; i<=n; i++)
		if (al[i] != 0) {
			if (ar[i] == 0)
				ar[i] = n;
			dodaj(al[i], ar[i], a[i], 1, 0, MAXN-1);
		}

	for (int i=1; i<2*MAXN; i++)
		c[i] = napravi_hull(c[i]);

	// resi u rastucem redosledu
	sort(q.begin(), q.end());
	fill(ans, ans+300005, 3123123123123123123ll);
	for (auto u : q)
		ans[u.second] = resi(u.first, u.second);
	for (int i=1; i<=n; i++) {
		if (ans[i] != 3123123123123123123ll) {
			if (ans[i] == -6123123123123123123ll)
				cout << "EMPTY SET\n";
			else
				cout << ans[i] << '\n';
		}
	}
}