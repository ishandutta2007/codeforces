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
const ll MOD = 1000000007;

ll powm(ll n, ll k) {
	ll x = 1, y = n;
	while (k) {
		if (k % 2) x = x * y % MOD;
		y = y * y % MOD;
		k /= 2;
	}
	return x;
}

ll inv(ll n) {
	return powm(n, MOD - 2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int k;
	cin >> k;
	ll n = 1;
	forn(i, 0, k) {
		ll a;
		cin >> a;
		a %= (MOD - 1);
		n = n * a % (MOD - 1);
	}
	--n;
	if (n < 0) n += MOD - 1;
	ll q = powm(2, n);
	ll p = q;
	if (n % 2) ++p;
	else --p;
	if (p < 0) p += MOD;
	if (p >= MOD) p -= MOD;
	p = p * inv(3) % MOD;
	cout << p << '/' << q << '\n'; 
	return 0;
}