#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define sz(a) (int)(a).size()

#define forn(i) for (int (i) = 0; (i) <= n; ++i)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int nmax = 1e6 + 10;

int mind[nmax];
vector<int> primes;

ll root3(ll n) {
	ll lf = 0, rg = nmax;
	while (rg - lf > 1) {
		ll md = (lf + rg) >> 1;
		if (md * md * md > n) {
			rg = md;
		} else {
			lf = md;
		}
	}
	return lf;
}

ll deg(ll a, ll p) {
	int ans = 0;
	while (a % p == 0) {
		++ans;
		a /= p;
	}
	return ans;
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");

	int tt;
	//tt = 350000;
	scanf("%d", &tt);
	
	for (int i = 2; i < nmax; ++i) {
		mind[i] = i;
	}

	for (int k = 2; k < nmax; ++k) {
		if (mind[k] == k) {
			primes.pb(k);
		}
		for (int p : primes) {
			if (k * p < nmax && p <= mind[k]) {
				mind[k * p] = p;
			} else {
				break;
			}
		}
	}

	while (tt--) {
		ll a, b;
		//a = 1000000000;
	    //b =	1000000;
		scanf("%lld%lld", &a, &b);
		ll c = a * b;
		ll f = root3(c);
		if (f * f * f != c) {
			printf("No\n");
			continue;
		}
		vector<ll> v;
		ll lst = -1;
		while (f != 1) {
			if (mind[f] == lst) {
				f /= lst;
			} else {
				v.pb(mind[f]);
				lst = mind[f];
				f /= lst;
			}
		}
		bool ok = true;
		for (ll p : v) {
			ll x = deg(a, p);
			ll y = deg(b, p);
			ll u = 2 * y - x;
			ll v = 2 * x - y;
			if (u < 0 || v < 0) {
				ok = false;
				break;
			}
			if (u % 3 || v % 3) {
				ok = false;
				break;
			}
			u /= 3, v /= 3;
			assert(u + 2 * v == x && 2 * u + v == y);
		}
		printf(ok ? "Yes\n" : "No\n");
	}

}