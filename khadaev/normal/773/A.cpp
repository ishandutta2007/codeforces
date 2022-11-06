#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cmath>
#include <algorithm>
#include <assert.h>
#include <memory.h>
#include <string.h>
#include <complex>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define sz(x) (int)(x).size()

ll gcd(ll a, ll b) {
	if (!a) return b;
	return gcd(b % a, a);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
}

ll oo = 2e18;

int cmp(ll a, ll b, ll c, ll d) {
	ll wtf = b / d;
	c *= wtf;
	if (a < c) return -1;
	if (a == c) return 0;
	return 1;
}

int main() {
	//freopen("input.txt", "rt", stdin);
	//freopen("output.txt", "wt", stdout);

	int t;
	cin >> t;
	while(t--) {
		ll x, y, p, q;
		cin >> x >> y >> p >> q;
		if (p == 0 && x != 0) {
			cout << -1 << endl;
			continue;
		}
		else if (p == 0) {
			cout << 0 << endl;
			continue;
		}
		if (p == 1 && q == 1) {
			if (x == y) {
				cout << 0 << endl;
				continue;
			}
			else {
				cout << -1 << endl;
				continue;
			}
		}

		ll add = 0;
		if (y % q != 0) {
			add = q - (y % q);
		}

		ll minchisl = x;
		ll maxchisl = y;
		ll znam = y + add;

		ll l = znam / q - 1, r = oo / q;
		while(l + 1 < r) {
			ll mid = (l + r) / 2LL;
			ll cnt = q * mid - y;
			ll x1 = x;
			ll y1 = cnt + y;
			ll x2 = x + cnt;
			ll y2 = cnt + y;
			if (cmp(x1, y1, p, q) <= 0 && cmp(x2, y2, p, q) >= 0) r = mid;
			else l = mid;
		}
		ll res = q * r - y;
		cout << res << endl;
	}

	
	return 0;
}