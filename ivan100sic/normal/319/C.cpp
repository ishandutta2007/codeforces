#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct line {
	ll k, b;
	ld start;
	ld operator* (ld x) {
		return x * k + b;
	}
};

ll n, a[100005], b[100005], d[100005];
line c[100005]; int cc, mo;

ld presek(line u, line v) {
	return (ld)(u.b - v.b) / (v.k - u.k);
}

void add_line(line t) {
	while (cc >= 1 && t*c[cc-1].start < c[cc-1]*c[cc-1].start)
		cc--;
	if (cc > 0)
		t.start = presek(c[cc-1], t);
	else
		t.start = 0;
	c[cc++] = t;
}

ll get_val(ll x) {
	if (mo >= cc)
		mo = cc - 1;
	while (mo + 1 < cc && x > c[mo+1].start)
		mo++;
	return c[mo].k * x + c[mo].b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	for (int i=1; i<=n; i++)
		cin >> b[i];

	d[1] = 0;
	add_line({b[1], d[1], 0});
	for (int i=2; i<=n; i++) {
		d[i] = get_val(a[i]);
		add_line({b[i], d[i], 0});
	}
	cout << d[n] << '\n';
}