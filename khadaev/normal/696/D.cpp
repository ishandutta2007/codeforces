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

const int MAXSZ = 210;
int sz;
ll x[MAXSZ][MAXSZ], y[MAXSZ][MAXSZ], t[MAXSZ][MAXSZ];

void mulx () {
	forn(i, 0, sz) forn(j, 0, sz) t[i][j] = -LINF;
	forn(i, 0, sz) forn(j, 0, sz) forn(k, 0, sz) t[i][k] = max(t[i][k], x[i][j] + y[j][k]);
}

void muly () {
	forn(i, 0, sz) forn(j, 0, sz) t[i][j] = -LINF;
	forn(i, 0, sz) forn(j, 0, sz) forn(k, 0, sz) t[i][k] = max(t[i][k], y[i][j] + y[j][k]);
}

void powm (ll n) {
	while (n) {
		if (n % 2) {
			mulx();
			forn(i, 0, sz) forn(j, 0, sz) x[i][j] = t[i][j];
		}
		muly();
		forn(i, 0, sz) forn(j, 0, sz) y[i][j] = t[i][j];
		n /= 2;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	ll l;
	cin >> n >> l;
	vector<ll> a(n);
	forn(i, 0, n) cin >> a[i];
	vector<string> s(n);
	forn(i, 0, n) cin >> s[i];
	vector<string> pref;
	forn(i, 0, n) {
		fore(j, 1, s[i].length())
			pref.eb(s[i].substr(0, j));
	}
	pref.eb("?");
	sz = pref.size();
	forn(i, 0, sz) forn(j, 0, sz) {
		int len = pref[j].length() - 1;
		if (pref[i].length() < len) y[i][j] = -LINF;
		else {
			if (pref[j].substr(0, len) != pref[i].substr(pref[i].length() - len, len)) y[i][j] = -LINF;
		}
	}
	forn(i, 0, sz) forn(j, 0, sz) x[i][j] = (i == j ? 0 : -LINF);
	forn(i, 0, sz) forn(j, 0, n) {
		int len = s[j].length();
		if (pref[i].length() < len) continue;
		if (s[j] == pref[i].substr(pref[i].length() - len, len)) x[i][i] += a[j];
	}
	forn(i, 0, sz) forn(j, 0, sz) if (y[i][j] != -LINF) {
		forn(k, 0, n) {
			int len = s[k].length();
			if (pref[j].length() < len) continue;
			if (s[k] == pref[j].substr(pref[j].length() - len, len)) y[i][j] += a[k];
		}
	}
	//forn(i, 0, sz) forn(j, 0, sz) cout << pref[i] << ' ' << pref[j] << ' ' << y[i][j] << '\n';
	powm(l - 1);
	ll ans = 0;
	forn(i, 0, sz) if (pref[i].length() == 1) forn(j, 0, sz) ans = max(ans, x[i][j]);
	cout << ans << '\n';
	return 0;
}