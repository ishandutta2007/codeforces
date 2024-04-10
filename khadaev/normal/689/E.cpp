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

const int N = 200010;

ll fact[N], invfact[N];

ll Pow (ll n, ll k) {
	ll x = 1, y = n;
	while (k) {
		if (k % 2) x = x * y % MOD;
		y = y * y % MOD;
		k /= 2;
	}
	return x;
}

ll Inv(ll n) {
	return Pow(n, MOD - 2);
}

ll binom (ll n, ll k) {
	if (k < 0 || k > n) return 0;
	return fact[n] * invfact[k] % MOD * invfact[n - k] % MOD;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	fact[0] = 1;
	forn(i, 1, N) fact[i] = fact[i - 1] * i % MOD;
	forn(i, 0, N) invfact[i] = Inv(fact[i]);
	int n, k;
	cin >> n >> k;
	vector<pair<int, int> > e; 
	forn(i, 0, n) {
		int l, r;
		cin >> l >> r;
		e.eb(l, -1);
		e.eb(r + 1, 1);
	}
	sort(all(e));
	vector<pair<int, int> > e1;
	int j = 0;
	while (j < e.size()) {
		int k = j, sum = 0;
		while (k < e.size() && e[k].fs == e[j].fs) {
			sum += e[k].sn;
			++k;
		}
		e1.eb(e[j].fs, sum);
		j = k;
	}
	ll ans = 0;
	int cnt = -e1[0].sn;
	forn(i, 1, e1.size()) {
		ans += binom(cnt, k) * (e1[i].fs - e1[i - 1].fs);
		ans %= MOD;
		cnt -= e1[i].sn;
	}
	cout << ans << '\n';
	return 0;
}