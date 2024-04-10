#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll n, k, M, D;

// opadajuca po x
ll reward(ll x) {
	if (k*0.5*x >= n) {
		return n >= x;
	}

	ll t = n/(k*x);
	ll rem = n%(k*x);
	return t + (rem >= x);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	
	cin >> n >> k >> M >> D;

	ll lx;

	if (k*0.5*D >= n) {
		lx = 1;
	} else {
		lx = (n+k*D-1)/(k*D);
	}
	ll rx = M;
	ll sol = 0;

	// broj punih krugova
	for (ll d=0; d<=D; d++) {
		
		ll l = lx, r = rx, o = lx;
		while (l <= r) {
			ll m = (l+r) / 2;
			if (reward(m) >= d) {
				o = m;
				l = m+1;
			} else {
				r = m-1;
			}
		}
		sol = max(sol, reward(o) * o);
		sol = max(sol, reward(lx) * lx);
		sol = max(sol, reward(rx) * rx);
	}

	cout << sol << '\n';
}