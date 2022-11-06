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

ll sqr(ll x) {
	return x * x;
}

ll ax, ay, bx, by, tx, ty;
vector<ll>x, y;

ld profit(ll cx, ll cy, int i) {
	return sqrt(sqr(cx - x[i]) + sqr(cy - y[i])) - sqrt(sqr(tx - x[i]) + sqr(ty - y[i]));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> ax >> ay >> bx >> by >> tx >> ty;
	int n;
	cin >> n;
	x.resize(n);
	y.resize(n);
	forn(i, 0, n) cin >> x[i] >> y[i];
	pair<ld, int> a1 = {1e18, -1}, a2 = {1e18, -1};
	pair<ld, int> b1 = {1e18, -1}, b2 = {1e18, -1};
	forn(i, 0, n) {
		ld p = profit(ax, ay, i);
		if (p < a1.fs) {
			a2 = a1;
			a1 = {p, i};
		} else if (p < a2.fs) a2 = {p, i};
		p = profit(bx, by, i);
		if (p < b1.fs) {
			b2 = b1;
			b1 = {p, i};
		} else if (p < b2.fs) b2 = {p, i};
	}
	ld best = 1e18;
	best = min(best, a1.fs);
	best = min(best, b1.fs);
	if (a1.sn != b1.sn) {
		best = min(best, a1.fs + b1.fs);
	} else {
		best = min(best, a1.fs + b2.fs);
		best = min(best, a2.fs + b1.fs);
	}
	forn(i, 0, n) best += 2 * sqrt(sqr(tx - x[i]) + sqr(ty - y[i]));
	cout << fixed << setprecision(10) << best << '\n';
	return 0;
}