#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct zag {
	int p, q, l;
	zag operator+ (zag b) {
		zag tmp;
		tmp.l = l + b.l + 2 * min(p, b.q);
		tmp.p = p + b.p - min(p, b.q);
		tmp.q = q + b.q - min(p, b.q);
		return tmp;
	}
};

string s;

zag a[1 << 21];

void build(int x, int xl, int xr) {
	if (xl == xr) {
		if (xl >= (int)s.size())
			return;
		(s[xl] == '(' ? a[x].p : a[x].q)++;
		return;
	}
	int xm = (xl + xr) >> 1;
	build(2*x, xl, xm);
	build(2*x+1, xm+1, xr);
	a[x] = a[2*x] + a[2*x+1];
}

zag gett(int x, int l, int r, int xl, int xr) {
	if (r < xl || xr < l)
		return {0, 0, 0};
	if (l <= xl && xr <= r)
		return a[x];
	int xm = (xl + xr) >> 1;
	return gett(2*x, l, r, xl, xm) + gett(2*x+1, l, r, xm+1, xr);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> s;
	s = string(" ") + s;
	build(1, 1, 1 << 20);
	int q;
	cin >> q;
	while (q--) {
		int l, r;
		cin >> l >> r;
		cout << gett(1, l, r, 1, 1 << 20).l << '\n';
	}
}