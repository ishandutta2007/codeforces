#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll inf = 1e18;

struct node {
	ll lhs, rhs, sol;

	node(ll a=-inf, ll b=-inf, ll c=-inf) : lhs(a), rhs(b), sol(c) {}

	node operator+ (const node& b) const {
		return {max(lhs, b.lhs), max(rhs, b.rhs), max({
			sol, b.sol, b.rhs + lhs
		})};
	}
};

int n, m;
ll pos[200005], h[200005];

const int maxn = 262144;
node b[2*maxn], neut;

void update(int i, node t) {
	i += maxn;
	b[i] = t;
	while (i > 1) {
		i >>= 1;
		b[i] = b[2*i] + b[2*i+1];
	}
}

node query(int l, int r, int x=1, int xl=0, int xr=maxn-1) {
	if (r < xl || xr < l)
		return {};
	if (l <= xl && xr <= r)
		return b[x];
	int xm = (xl+xr) >> 1;
	return query(l, r, 2*x, xl, xm) + query(l, r, 2*x+1, xm+1, xr);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		ll x;
		cin >> x;
		pos[i+1] = pos[i] + x;
	}

	ll obim = pos[n+1];

	for (int i=1; i<=n; i++) {
		pos[i+n] = pos[i] + obim;
	}

	for (int i=1; i<=n; i++) {
		cin >> h[i];
		h[i+n] = h[i];
	}

	for (int i=1; i<=2*n; i++) {
		update(i, node{2*h[i]-pos[i], 2*h[i]+pos[i], -inf});
	}

	for (int i=0; i<m; i++) {
		int a, b;
		cin >> a >> b;
		node r;
		if (a <= b) {
			r = query(b+1, a+n-1);
		} else {
			r = query(b+1, a-1);
		}
		cout << r.sol << '\n';
	}
}