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
	int n, s, e;
	cin >> n >> s >> e;
	--s, --e;
	vector<ll> x(n), a(n), b(n), c(n), d(n);
	forn(i, 0, n) cin >> x[i];
	forn(i, 0, n) cin >> a[i];
	forn(i, 0, n) cin >> b[i];
	forn(i, 0, n) cin >> c[i];
	forn(i, 0, n) cin >> d[i];
	vector<ll> tol(n), tor(n), froml(n), fromr(n);
	forn(i, 0, n) {
		tol[i] = c[i] + x[i];
		tor[i] = d[i] - x[i];
		froml[i] = a[i] + x[i];
		fromr[i] = b[i] - x[i];
	}
	vector<ll> dp1(n), dp2(n);
	fill(all(dp1), LINF);
	dp1[0] = 0;
	forn(i, 0, n) {
		fill(all(dp2), LINF);
		forn(j, 0, n) {
			if (i != e || s < e) {
				if (i != s || s < e) {
					if (i > s && i < e && j == 1) {}
					else dp2[j] = min(dp2[j], dp1[j] + tol[i] + fromr[i]);
				}
				if (i != s || s > e) {
					if (j != 0) dp2[j - 1] = min(dp2[j - 1], dp1[j] + tol[i] + froml[i]);
				}
			}
			if (i != e || s > e) {
				if (i != s || s < e) {
					if (j != n - 1) dp2[j + 1] = min(dp2[j + 1], dp1[j] + tor[i] + fromr[i]);
				}
				if (i != s || s > e) {
					if (i > e && i < s && j == 1) {}
					else dp2[j] = min(dp2[j], dp1[j] + tor[i] + froml[i]);
				}
			}
		}
		dp1 = dp2;
		if (i != n - 1) dp1[0] = LINF;
		//trace(dp1);
	}
	ll ans = dp1[0];
	if (s < e) {
		ans -= tol[e];
		ans -= fromr[s];
	} else {
		ans -= tor[e];
		ans -= froml[s];
	}
	cout << ans << '\n';
	return 0;
}