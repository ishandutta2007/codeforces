// Retired?
#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct sieve {
	const int maxn;
	vector<int> f, primes;

	sieve(int maxn) : maxn(maxn), f(maxn) {
		for (int i=2; i<maxn; i++) {
			if (f[i] == 0) {
				f[i] = i;
				primes.push_back(i);
			}

			for (int p : primes) {
				if (p > f[i] || i * p >= maxn) {
					break;
				}

				f[i*p] = p;
			}
		}
	}
};

const ll hi = 22000000;
const int nlim = 5;
sieve s(hi);

unordered_map<ll, ll> fic[666];

ll fi_ie(ll m, int n) {
	ll z = 0;
	for (int mask=0; mask<(1<<n); mask++) {
		ll p=1, s=1;
		for (int i=0; i<n; i++) {
			if (mask & (1 << i)) {
				p *= ::s.primes[i];
				s = -s;
			}
		}
		z += m/p * s;
	}
	return z;
}

ll fi(ll m, ll n) {
	if (n <= nlim)
		return fi_ie(m, n);
	if (n % 3 == 0) {
		// kesiraj
		ll& v = fic[n][m];
		if (!v)
			v = fi(m, n-1) - fi(m/s.primes[n-1], n-1) + 123;
		return v - 123;
	} else {
		// nemoj
		return fi(m, n-1) - fi(m/s.primes[n-1], n-1);
	}

}

ll squareroot(ll x) {
	ll y = pow(x+1, 0.5) + 2;
	while (y*y > x)
		y--;
	return y;
}

ll cuberoot(ll x) {
	ll y = pow(x+1, 0.33333333333333) + 2;
	while (y*y*y > x)
		y--;
	return y;
}

ll pi(ll m) {
	if (m <= hi) {
		return upper_bound(begin(s.primes), end(s.primes), m) - begin(s.primes);
	}

	ll n = pi(cuberoot(m));
	ll mu = pi(squareroot(m)) - n;
	ll t = fi(m, n) + n*(mu+1) + mu*(mu-1)/2 - 1;
	for (ll k=1; k<=mu; k++) {
		t -= pi(m / s.primes[n+k-1]);
	}
	return t;
}

ll semiprimes(ll n) {
	ll m = pi(squareroot(n));
	ll z = 0;
	for (ll i=0; i<m; i++) {
		z += pi(n / s.primes[i]) - i - 1;
	}
	return z;
}

ll primecubes(ll x) {
	return pi(cuberoot(x));
}

ll solve(ll x) {
	return semiprimes(x) + primecubes(x);
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	ll n;
	cin >> n;
	cout << solve(n) << '\n';
}