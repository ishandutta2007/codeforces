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

ll powm(ll a, ll b) {
	ll x = 1, y = a;
	while (b) {
		if (b % 2) x = x * y % MOD;
		y = y * y % MOD;
		b /= 2;
	}
	return x;
}

ll inv(ll a) {
	return powm(a, MOD - 2);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll a, b, n, x;
	cin >> a >> b >> n >> x;
	if (a == 1) {
		cout << (n % MOD * b % MOD + x) % MOD << '\n';
	} else {
		ll t = b * inv(a - 1) % MOD;
		cout << ((x + t) % MOD * powm(a, n) % MOD - t + MOD) % MOD << '\n';
	}
	return 0;
}