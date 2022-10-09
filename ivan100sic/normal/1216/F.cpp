#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int maxn = 262144;
const ll inf = 4e18;

struct lazyseg {
	vector<ll> a;

	lazyseg() : a(2*maxn, inf) {}

	void update(int l, int r, ll v, int x=1, int xl=0, int xr=maxn-1) {
		if (r < xl || xr < l)
			return;
		if (l <= xl && xr <= r) {
			a[x] = min(a[x], v);
			return;
		}
		int xm = (xl+xr) >> 1;
		update(l, r, v, 2*x, xl, xm);
		update(l, r, v, 2*x+1, xm+1, xr);
	}

	ll query(int p) {
		ll z = inf;
		p += maxn;
		while (p > 0) {
			z = min(z, a[p]);
			p >>= 1;
		}
		return z;
	}
};

int n, k;
string s;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k >> s;
	s = string(" ") + s;
	lazyseg dp;
	dp.update(0, 0, 0);
	for (int i=1; i<=n; i++) {
		int l = i, r = i;
		if (s[i] == '1')
			l = max(1, i-k), r = min(n, i+k);
		ll v = dp.query(l-1);
		dp.update(l, r, v+i);
	}
	cout << dp.query(n) << '\n';
}