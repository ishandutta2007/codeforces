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


const int N = 100010;

ll x[N], y[N], z[N];
ll mind[8];
ll maxd[8];

ll divl(ll n) {
	if (n % 2 == 0) return n / 2;
	return (n - 1) / 2;
}

ll divr(ll n) {
	if (n % 2 == 0) return n / 2;
	return (n + 1) / 2;
}

bool good(ll xx) {
	ll mins = max(mind[7] - xx, - maxd[1] + xx), maxs = min(maxd[7] - xx, - mind[1] + xx);
	ll mindif = max(mind[5] - xx, - maxd[3] + xx), maxdif = min(maxd[5] - xx, -mind[3] + xx);
	if (mins > maxs) return false;
	if (mindif > maxdif) return false;
	ll s = mins, d = mindif;
	if (abs(s) % 2 != abs(d) % 2) {
		if (mins != maxs) ++s;
		else if (mindif != maxdif) ++d;
		else return false;
	}
	return true;
}

void out(ll xx) {
	ll mins = max(mind[7] - xx, - maxd[1] + xx), maxs = min(maxd[7] - xx, - mind[1] + xx);
	ll mindif = max(mind[3] - xx, - maxd[5] + xx), maxdif = min(maxd[3] - xx, -mind[5] + xx);
	ll s = mins, d = mindif;
	if (abs(s) % 2 != abs(d) % 2) {
		if (mins != maxs) ++s;
		else if (mindif != maxdif) ++d;
	}
	ll yy = (s + d) / 2, zz = (s - d) / 2;
	cout << xx << ' ' << yy << ' ' << zz << '\n';
	//cout << mins << ' ' << maxs << '\n';
	//cout << mindif << ' ' << maxdif << '\n';
}

void solve() {
	int n;
	cin >> n;
	forn(i, 0, n) cin >> x[i] >> y[i] >> z[i];
	ll l = -1, r = 3e18 + 100;
	while (l < r - 1) {
		ll mid = (l + r) / 2;
		forn(i, 0, 8) {
			mind[i] = -5e18;
			maxd[i] = 5e18;
		}
		forn(i, 0, n) forn(j, 0, 8) {
			ll val = 0;
			if (j & 1) val += x[i];
			else val -= x[i];
			if (j & 2) val += y[i];
			else val -= y[i];
			if (j & 4) val += z[i];
			else val -= z[i];
			mind[j] = max(mind[j], val - mid);
			maxd[j] = min(maxd[j], val + mid);
		}
		bool ok = true;
		forn(i, 0, 8) if (mind[i] > maxd[i]) ok = false;
		if (ok) {
			ll minx = divr(max(mind[7] + mind[1], mind[5] + mind[3]));
			ll maxx = divl(min(maxd[7] + maxd[1], maxd[5] + maxd[3]));
			ok = false;
			if (minx <= maxx) {
				ok |= good(minx);
				ok |= good(maxx);
				if (minx != maxx) {
					ok |= good(minx + 1);
					ok |= good(maxx - 1);
				}
			}
		}
		if (ok) r = mid;
		else l = mid;
	}
	//cout << r << '\n';
	forn(i, 0, 8) {
		mind[i] = -5e18;
		maxd[i] = 5e18;
	}
	forn(i, 0, n) forn(j, 0, 8) {
		ll val = 0;
		if (j & 1) val += x[i];
		else val -= x[i];
		if (j & 2) val += y[i];
		else val -= y[i];
		if (j & 4) val += z[i];
		else val -= z[i];
		mind[j] = max(mind[j], val - r);
		maxd[j] = min(maxd[j], val + r);
	}
	ll minx = divr(max(mind[7] + mind[1], mind[5] + mind[3]));
	ll maxx = divl(min(maxd[7] + maxd[1], maxd[5] + maxd[3]));
	if (good(minx)) out(minx);
	else if (good(maxx)) out(maxx);
	else if (good(minx + 1)) out(minx + 1);
	else out(maxx - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t-- > 0) solve();
	return 0;
}