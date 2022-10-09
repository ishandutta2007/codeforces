#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll a;
ll pw10[20];

ll solve(ll x) {
	x++;
	ll b[20];
	// cifre su 0..19
	for (int i=0; i<20; i++) {
		b[i] = x % 10;
		x /= 10;
	}

	ll sol = 0;
	ll zbircif = 0;
	for (int i=19; i>=0; i--) {
		// brojevi oblika
		// ..poznato___X...[0..9]^i
		// 0 <= X < b[i]
		sol += zbircif * b[i] * pw10[i];
		sol += (b[i]*(b[i]-1)/2) * pw10[i];
		sol += i * b[i] * pw10[i] / 2 * 9;
		zbircif += b[i];
	}
	return sol;
}

ll sd(ll x) {
	ll z = 0;
	while (x > 0) {
		z += x % 10;
		x /= 10;
	}
	return z;
}

ll solve_brute(ll x) {
	ll z = 0;
	while (x > 0) {
		z += sd(x);
		x--;
	}
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	pw10[0] = 1;
	for (int i=1; i<20; i++)
		pw10[i] = pw10[i-1] * 10;

	ll l = 0, r = 23213213213213212ll, o = -1;
	cin >> a;

	while (l <= r) {
		ll mid = (l+r) >> 1;
		if (solve(mid) >= a) {
			o = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}

	ll p = 1;
	while (1) {
		ll oo = solve(o);
		ll pp = solve(p - 1);
		// cerr << o << ' ' << p << ' ' << oo - pp << '\n';
		if (oo - pp > a) {
			p++;
		} else if (oo - pp < a) {
			o++;
		} else {
			cout << p << ' ' << o << '\n';
			return 0;
		}
	}
}