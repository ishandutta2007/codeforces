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
	cout << fixed << setprecision(10);
	ll n, w, v, u;
	cin >> n >> w >> v >> u;
	int sz = 2 * n + 1;
	vector<ll> x(sz), y(sz);
	forn(i, 0, n) cin >> x[i] >> y[i];
	forn(i, 0, sz) {
		x[i] = x[i % n];
		y[i] = y[i % n];
	}
	int left, right;
	ll lval = LINF, rval = -LINF;
	forn(i, 0, n) {
		ll val = u * x[i] - v * y[i];
		if (val < lval) {
			lval = val;
			left = i;
		}
		if (val > rval || val == rval && x[i] < x[right]) {
			rval = val;
			right = i;
		}
	}
	if (lval <= 0 && rval <= 0 || lval >= 0 && rval >= 0) {
		cout << (ld)w / u << '\n';
		return 0;
	}
	cout << (ld)x[right] / v + (ld)(w - y[right]) / u << '\n';
	return 0;
}