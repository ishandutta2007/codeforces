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

const int N = 500;
ll a[N][N];

void fail() {
	cout << "-1\n";
	exit(0);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, ix, jx;
	cin >> n;
	forn(i, 0, n) forn(j, 0, n) {
		cin >> a[i][j];
		if (a[i][j] == 0) {
			ix = i, jx = j;
		}
	}
	if (n == 1) {
		cout << 1 << '\n';
		return 0;
	}
	ll s = 0;
	forn(i, 0, n) if (i != ix) {
		forn(j, 0, n) s += a[i][j];
		break;
	}
	ll add = s;
	forn(j, 0, n) if (j != jx) add -= a[ix][j];
	if (add <= 0) fail();
	a[ix][jx] = add;
	forn(i, 0, n) {
		ll s1 = 0;
		forn(j, 0, n) s1 += a[i][j];
		if (s != s1) fail();
	}
	forn(j, 0, n) {
		ll s1 = 0;
		forn(i, 0, n) s1 += a[i][j];
		if (s != s1) fail();
	}
	ll s1 = 0;
	forn(i, 0, n) s1 += a[i][i];
	if (s != s1) fail();
	s1 = 0;
	forn(i, 0, n) s1 += a[i][n - 1 - i];
	if (s != s1) fail();
	cout << add << '\n';
	return 0;
}