#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define ford(i, a, n) for (int i = n - 1; i >= a; --i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
	for (auto i : a) cerr << i << ' ';\
	cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = acos(-1.0);
#endif

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000003;
const ll inv2 = (MOD + 1) / 2;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n, k;
	cin >> n >> k;
	if (n <= 60 && k > (1ll << n)) {
		cout << "1 1\n";
		return 0;
	}
	ll a = 1, b = 1;
	ll bpow = n % (MOD - 1) * ((k - 1) % (MOD - 1)) % (MOD - 1);
	ll div = k - 1;
	ll a2 = 0;
	while (div) {
		div /= 2;
		bpow -= div % (MOD - 1);
		a2 += div % (MOD - 1);
		a2 %= (MOD - 1);
		if (bpow < 0) bpow += MOD - 1;
	}
	//cerr << bpow << '\n';
	forn(i, 0, bpow) b = 2 * b % MOD;
	if (k > MOD) a = 0;
	else {
		ll apow = 1;
		forn(i, 0, n % (MOD - 1)) apow = 2 * apow % MOD;
		--apow;
		if (apow < 0) apow += MOD;
		forn(i, 1, k) {
			a = a * apow % MOD;
			--apow;
			if (apow < 0) apow += MOD;
		}
		forn(i, 0, a2) {
			a = a * inv2 % MOD;
		}
	}
	a = (b - a + MOD) % MOD;
	cout << a << ' ' << b << '\n';
	return 0;
}