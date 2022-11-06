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

#ifndef M_PI
const ld M_PI = 3.1415926535897932384626433;
#endif
const ld eps = 1e-8;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	int p[6][6];
	forn(i, 0, 6) forn(j, 0, 6) p[i][j] = 0;
	forn(i, 0, q) {
		string a, b;
		cin >> a >> b;
		p[b[0] - 'a'][a[0] - 'a']++;
	}
	ll dp[6][6];
	forn(i, 0, 6) forn(j, 0, 6) dp[i][j] = 0;
	dp[0][0] = 1;
	forn(i, 1, n) {
		forn(j, 0, 6)
			forn(k, 0, 6)
				dp[i][j] += dp[i - 1][k] * p[k][j];
	}
	ll ans = 0;
	forn(i, 0, 6) ans += dp[n - 1][i];
	cout << ans << '\n';
	return 0;
}