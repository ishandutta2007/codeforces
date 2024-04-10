#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[300005];

const int M = 998244353;
const int B = 4444;

struct node {
	int hl, hr, p;
};

node zb(node a, node b) {
	node t;
	t.hl = (a.hl * 1ll * b.p + b.hl) % M;
	t.hr = (b.hr * 1ll * a.p + a.hr) % M;
	t.p = a.p * 1ll * b.p % M;
	return t;
}

const int MAXN = 524288;
node b[2*MAXN];

void update(int x, int v) {
	x += MAXN;
	b[x].hl = b[x].hr = v;
	b[x].p = B;

	while (x > 1) {
		x >>= 1;
		b[x] = zb(b[2*x], b[2*x+1]);
	}
}

node query(int l, int r, int x=1, int xl=0, int xr=MAXN-1) {
	if (r < xl || xr < l)
		return {0, 0, 1};
	if (l <= xl && xr <= r)
		return b[x];
	int xm = (xl+xr) >> 1;
	return zb(query(l, r, 2*x, xl, xm), query(l, r, 2*x+1, xm+1, xr));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		update(a[i], 2);
	}

	for (int i=1; i<=n; i++) {
		int w = min(a[i]-1, n-a[i]);
		auto q = query(a[i]-w, a[i]+w);
		if (q.hl != q.hr) {
			cout << "YES\n";
			return 0;
		}
		update(a[i], 1);
	}

	cout << "NO\n";
}