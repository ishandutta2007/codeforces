#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)

#ifndef M_PI
const ld M_PI = 3.1415926535897932384626433;
#endif
const ld eps = 1e-8;
const int INF = 1e9;

ll MOD = 1e9 + 7;

ll fact[5000];

ll Pow (ll n, ll k) {
	ll x = n, y = 1;
	while(k) {
		if (k % 2) y = y * x % MOD;
		x = x * x % MOD;
		k /= 2;
	}
	return y;
}

ll inv(ll n) {
	//cout << "Inv:" << n << ' ' << Pow(n, MOD - 2) << '\n'; 
	return Pow(n, MOD - 2);
}

ll c(ll n, ll k) {
	if (k > n) return 0;
	if (k < 0) return 0;
	//cout << "!" << n << ' ' << k << '\n';
	//cout << fact[n] * inv(fact[k]) % MOD * inv(fact[n - k]) % MOD <<
	//'\n';;

	return fact[n] * inv(fact[k]) % MOD * inv(fact[n - k]) % MOD;
}

ll solve(ll n, ll m) {
	if (n < m) swap(n, m);
	return (c(n + m, n) + MOD - c(n + m, n + 1)) % MOD;
} 

ll mod(ll n, ll p) {
	return (n % p + p) % p;
}

void fail() {
	cout << "0\n";
	exit(0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	fact[0] = 1;
	forn(i, 1, 5000)
		fact[i] = fact[i - 1] * i % MOD;
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	int sum = 0, minsum = 0, sum2 = 0, minsum2 = 0;
	forn(i, 0, m) {
		if (s[i] == '(') ++sum;
		else --sum;
		minsum = min(minsum, sum);
	}
	forn(i, 0, m) {
		if (s[m - i - 1] == ')') ++sum2;
		else --sum2;
		minsum2 = min(minsum2, sum2);
	}
	if ((n - m) % 2 != mod(sum, 2)) fail();
	int pr = (n - m - sum) / 2;
	int qs = (n - m + sum) / 2;
	if (pr < 0 || qs < 0) fail();
	ll ans = 0;
	fore(p, 0, n - m)
		fore(q, 0, n - m) {
			if (p - q < -minsum) continue;
			int r = pr - p, s = qs - q;
			if (s < 0 || r < 0) continue;
			if (s - r < -minsum2) continue;
			ans = (ans + solve(p, q) * solve(s, r)) % MOD;
		}
	cout << ans << '\n';
	return 0;
}