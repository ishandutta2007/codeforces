#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, w;
int p[500006], z[500006];

int d[1048576];

int gett(int l, int r, int x, int xl, int xr) {
	if (r < xl || xr < l)
		return 123123123;
	if (l <= xl && xr <= r)
		return d[x];
	int xm = (xl+xr) >> 1;
	return min(gett(l, r, 2*x, xl, xm), gett(l, r, 2*x+1, xm+1, xr));
}

void sett(int x, int v) {
	x += 524288;
	d[x] = v;
	while (x > 1) {
		x >>= 1;
		d[x] = min(d[2*x], d[2*x+1]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> w;

	p[0] = 1;
	while (n--) {
		int x;
		cin >> x;
		for (int j=500004; j>=x; j--)
			p[j] |= p[j - x];
	}
	fill(d, d + 1048576, 123123123);
	sett(0, 0);
	int s=0, v=0;
	for (int i=1; i<=500005; i++) {
		if (p[i]) {
			int x = 1 + gett(i-w, i-1, 1, 0, 524287);
			if (x < 123123123) {
				s = i;
				v = x;
				sett(i, x);
			}
		}
	}
	cout << s << ' ' << v << '\n';
}