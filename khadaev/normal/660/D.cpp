#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
	for (auto i : a) cerr << i << ' ';\
	cerr << '\n'
#define eb emplace_back

#ifndef M_PI
const ld M_PI = 3.1415926535897932384626433;
#endif

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

typedef pair<int, int> pt;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pt> a(n);
	forn(i, 0, n) cin >> a[i].fs >> a[i].sn;
	vector<pt> d;
	forn(i, 0, n) forn(j, 0, n) if (i != j) {
		d.eb(a[i].fs - a[j].fs, a[i].sn - a[j].sn);
	}
	sort(all(d));
	ll ans = 0, loc = 1;
	forn(i, 1, d.size()) {
		if (d[i] == d[i - 1]) ++loc;
		else {
			ans += loc * (loc - 1) / 2;
			loc = 1;
		}
	}
	ans += loc * (loc - 1) / 2;
	cout << ans / 4 << '\n';
	return 0;
}