// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		ll x;
		cin >> x;
		ll aa=1, bb=x-1, vv=x-1;
		for (ll d=1; d*d<=x; d++) {
			if (x % d == 0) {
				for (ll a : {d, x/d}) {
					ll b = x - a;
					if (!b) continue;
					ll v = lcm(a, b);
					if (v < vv) {
						vv = v;
						aa = a;
						bb = b;
					}
				}
			}
		}

		cout << aa << ' ' << bb << '\n';
	}
}