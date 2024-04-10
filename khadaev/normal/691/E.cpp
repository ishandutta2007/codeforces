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

int n;

int popcount(ull z) {
	int ans = 0;
	while (z) {
		ans += z % 2;
		z /= 2;
	}
	return ans;
}

vector<vector<ll>> mult(vector<vector<ll>> &a, vector<vector<ll>> &b) {
	vector<vector<ll> > ans(n, vector<ll>(n));
	forn(i, 0, n) forn(j, 0, n) forn(k, 0, n) ans[i][k] = (ans[i][k] + a[i][j] * b[j][k]) % MOD;
	return ans;
}

vector<vector<ll>> powm(vector<vector<ll>> a, ll m) {
	vector<vector<ll>> x(n, vector<ll>(n, 0)), y = a;
	forn(i, 0, n) x[i][i] = 1;
	while (m) {
		if (m % 2) x = mult(x, y);
		y = mult(y, y);
		m /= 2;
	}
	return x;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll k;
	cin >> n >> k;
	vector<ull> a(n);
	forn(i, 0, n) cin >> a[i];
	vector<vector<ll> > x(n, vector<ll>(n));
	forn(i, 0, n) forn(j, 0, n) if (popcount(a[i] ^ a[j]) % 3 == 0) x[i][j] = 1;
	vector<vector<ll>> t = powm(x, k - 1);
	ll ans = 0;
	forn(i, 0, n) forn(j, 0, n) ans = (ans + t[i][j]) % MOD;
	cout << ans << '\n';
	return 0;
}