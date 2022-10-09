#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int maxn = 1 << 20;

struct lazyseg {
	vector<int> a, b;

	lazyseg() : a(2*maxn, 0), b(2*maxn, 0) {}

	void push(int x) {
		if (b[x] == 0)
			return;
		if (x < maxn) {
			b[2*x] += b[x];
			b[2*x+1] += b[x];
		}
		a[x] += b[x];
		b[x] = 0;
	}

	void update(int l, int r, int v, int x=1, int xl=0, int xr=maxn-1) {
		if (r < xl || xr < l) {
			push(x);
			return;
		}
		if (l <= xl && xr <= r) {
			b[x] += v;
			push(x);
			return;
		}
		int xm = (xl+xr) >> 1;
		push(x);
		update(l, r, v, 2*x, xl, xm);
		update(l, r, v, 2*x+1, xm+1, xr);
		a[x] = min(a[2*x], a[2*x+1]);
	}

	int seek(int x=1) {
		push(x);
		if (x >= maxn)
			return x - maxn;
		push(2*x);
		push(2*x+1);
		if (a[2*x+1] < 0)
			return seek(2*x+1);
		else
			return seek(2*x);
	}
};

int n, m, q;
int a[300005], b[300005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	lazyseg drvo;

	for (int i=1; i<=n; i++) {
		cin >> a[i];
		drvo.update(1, a[i], -1);
	}

	for (int i=1; i<=m; i++) {
		cin >> b[i];
		drvo.update(1, b[i], +1);
	}

	cin >> q;
	while (q--) {
		int t, i, x;
		cin >> t >> i >> x;
		if (t == 1) {
			drvo.update(1, a[i], +1);
			a[i] = x;
			drvo.update(1, a[i], -1);
		} else {
			drvo.update(1, b[i], -1);
			b[i] = x;
			drvo.update(1, b[i], +1);
		}

		t = drvo.seek();
		cout << (t-!t) << '\n';
	}
}