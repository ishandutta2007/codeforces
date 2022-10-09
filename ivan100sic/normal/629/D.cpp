#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int maxn = 131072;

int n, k;
ll a[100005], u[100005];

struct segtree {
	vector<ll> a;

	segtree() : a(2*maxn) {}

	ll query(int l, int r, int x=1, int xl=0, int xr=maxn-1) {
		if (r < xl || xr < l)
			return 0;
		if (l <= xl && xr <= r)
			return a[x];
		int xm = (xl+xr) >> 1;
		return max(query(l, r, 2*x, xl, xm), query(l, r, 2*x+1, xm+1, xr));
	}

	void update(int x, ll v) {
		x += maxn;
		a[x] = v;
		while (x > 1) {
			x >>= 1;
			a[x] = max(a[2*x], a[2*x+1]);
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		ll r, h;
		cin >> r >> h;
		a[i] = r * r * h;
		u[i] = a[i];
	}
	sort(u, u+n);
	k = unique(u, u+n) - u;
	segtree seg;
	ll sol = 0;
	for (int i=0; i<n; i++) {
		int pos = lower_bound(u, u+k, a[i]) - u;
		ll v = seg.query(0, pos-1) + a[i];
		seg.update(pos, v);
		sol = max(sol, v);
	}

	cout << setprecision(20) << fixed << (sol * acos(ld(-1))) << '\n';
}