#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void sol(ll n) {
	ll nn = n;
	ll x = 0, y = 0;
	ll l = 0, r = 600000000;
	while (l < r - 1) {
		ll m = (l + r) / 2;
		ll val = 5 * m + 3 * m * (m - 1);
		if (val <= n) l = m;
		else r = m;
	}
	n -= 5 * l + 3 * l * (l - 1);
	y -= l;
	++l;
	if (n <= 2 * l - 1) {
		y += n;
	} else {
		n -= 2 * l - 1;
		y += 2 * l - 1;
		if (n > l) {
			n -= l;
			if (n <= 2 * l) {
				y -= n;
			} else {
				y -= 2 * l;
				n -= 2 * l;
			}
		}
	}
	n = nn;
	--l;
	n -= 5 * l + 3 * l * (l - 1);
	x += l;
	++l;
	if (n <= l) {
		x += n;
	} else {
		x += l;
		n -= l;
		if (n <= l - 1) {
			x -= n;
		} else {
			x -= l - 1;
			n -= l - 1;
			if (n <= l) {
				x -= 2 * n;
			} else {
				x -= 2 * l;
				n -= l;
				if (n <= l) {
					x -= n;
				} else {
					x -= l;
					n -= l;
					if (n <= l) {
						x += n;
					} else {
						x += l;
						n -= l;
						if (n <= l) {
							x += 2 * n;
						} else {
							cout << "ERROR\n";
							exit(1);
						}
					}
				}
			}
		}
	}

	cout << x << ' ' << 2 * y << '\n';
}

int main() {
	ll n;
	cin >> n;
	sol(n);
}