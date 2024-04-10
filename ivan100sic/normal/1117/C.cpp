#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int br[200005][4];
int n;
string s;

int tip(char x) {
	if (x == 'L') return 0;
	if (x == 'R') return 1;
	if (x == 'D') return 2;
	if (x == 'U') return 3;
	return -1;
}

ll citaj(ll x, int tip) {
	return br[x%n][tip] + br[n][tip]*(x/n);
}

ll range_x(ll x) {
	return citaj(x, 1) - citaj(x, 0);
}

ll range_y(ll x) {
	return citaj(x, 3) - citaj(x, 2);
}

ll ok(ll range, ll x) {
	if (x > range)
		return x - range;
	if (x < range)
		return range - x;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int a, b, c, d;
	cin >> a >> b >> c >> d;
	a = c-a;
	b = d-b;

	cin >> n;
	cin >> s;


	for (int i=0; i<n; i++) {
		copy(br[i], br[i]+4, br[i+1]);
		br[i+1][tip(s[i])]++;
	}

	ll l=0, r=1e17, o=-1;
	while (l <= r) {
		ll m = (l+r) >> 1;
		ll erra = ok(range_x(m), a);
		ll errb = ok(range_y(m), b);

		if (erra + errb <= m) {
			o = m;
			r = m - 1;
		} else {
			l = m + 1;
		}
	}
	cout << o << '\n';
}