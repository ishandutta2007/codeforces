#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll M = 548444109583871771ll;

struct node {
	int l, r;
	ll z;
} b[100005 * 60]; int sz;

void ad(ll& x, ll y) {
	x += y;
	if (x >= M)
		x -= M;
}

void add(int p, ll v, int& x, int xl=1, int xr=100000) {
	if (!x) x = ++sz;
	ad(b[x].z, v);
	if (xl < xr) {
		int xm = (xl+xr) >> 1;
		if (p <= xm)
			add(p, v, b[x].l, xl, xm);
		else
			add(p, v, b[x].r, xm+1, xr);
	}
}

ll query(int l, int r, int& x, int xl=1, int xr=100000) {
	if (!x || xr < l || r < xl)
		return 0;
	if (l <= xl && xr <= r)
		return b[x].z;
	int xm = (xl+xr) >> 1;
	ll ret = query(l, r, b[x].l, xl, xm);
	ad(ret, query(l, r, b[x].r, xm+1, xr));
	return ret;
}

ll fc[100005], bc[100005];
int fs[100005], bs[100005];
int a[100005], n;

int root[100005];

ll bigmod(ll x, ll y, ll m) {
	ll z = 0;
	for (int i=62; i>=0; i--) {
		z += z;
		if (z >= m)
			z -= m;
		if (x & (1ll << i)) {
			z += y;
			if (z >= m)
				z -= m;
		}
	}
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];

	basic_string<int> dp;
	for (int i=1; i<=n; i++) {
		int s = lower_bound(dp.begin(), dp.end(), a[i]) - dp.begin();
		if (s == (int)dp.size())
			dp.push_back(a[i]);
		else
			dp[s] = a[i];
		
		if (s == 0)
			fc[i] = 1;
		else
			fc[i] = query(1, a[i]-1, root[s]);
		fs[i] = s+1;
		add(a[i], fc[i], root[s+1]);
	}

	dp = {};
	fill(root+1, root+n+1, 0);

	for (int i=n; i>=1; i--) {
		int s = lower_bound(dp.begin(), dp.end(), 100001 - a[i]) - dp.begin();
		if (s == (int)dp.size())
			dp.push_back(100001 - a[i]);
		else
			dp[s] = 100001 - a[i];
		
		if (s == 0)
			bc[i] = 1;
		else
			bc[i] = query(1, (100001 - a[i])-1, root[s]);
		bs[i] = s+1;
		add((100001 - a[i]), bc[i], root[s+1]);
	}

	int ss = dp.size();
	ll cc = query(1, 100000, root[ss]);

	cerr << M << ' ' << ss << ' ' << cc << '\n';

	for (int i=1; i<=n; i++) {
		// cerr << i << " : " << fs[i] << ' ' << fc[i] << ' ' << bs[i] << ' ' << bc[i] << '\n';

		if (fs[i] + bs[i] - 1 != ss) {
			cout << '1';
			continue;
		}

		ll c = bigmod(fc[i], bc[i], M);
		if (c == cc)
			cout << '3';
		else
			cout << '2';
	}
	cout << '\n';
}