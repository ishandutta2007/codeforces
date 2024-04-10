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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	vector<ll> c(n + 2), id(n + 2);
	forn(i, 0, n) cin >> c[i + 1];
	c[0] = c[n];
	c[n + 1] = c[1];
	ll ans = 0;
	fore(i, 1, n) ans += c[i] * c[i + 1];
	ll s = 0;
	fore(i, 1, n) s += c[i];
	forn(i, 0, k) {
		int x;
		cin >> x;
		ans += c[x] * (s - c[x] - c[x + 1] - c[x - 1]);
		id[x] = 1;
	}
	id[0] = id[n];
	id[n + 1] = id[1];
	ll s1 = 0;
	fore(i, 1, n) if (id[i]) s1 += c[i];
	ll add = - s1 * s1;
	forn(i, 0, n) {
		if (id[i]) add += c[i] * c[i];
		if (id[i] && id[i + 1]) ans += c[i] * c[i + 1];
	}
	ans += add / 2;
	cout << ans << '\n';
	return 0;
}