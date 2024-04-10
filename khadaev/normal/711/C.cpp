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

const int N = 102;

ll p[N][N];
ll dp[N][N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> c(n);
	forn(i, 0, n) cin >> c[i];
	forn(i, 0, n) forn(j, 0, m) cin >> p[i][j];
	forn(i, 0, n) if (c[i] != 0) p[i][c[i] - 1] = 0;
	forn(i, 0, n) {
		fore(j, 1, m) fore(x, 1, k) {
		dp[i][j][x] = LINF;
		if (c[i] != 0 && c[i] != j) continue;
		if (i) {
			dp[i][j][x] = min(dp[i][j][x], dp[i - 1][j][x] + p[i][j - 1]);
			if (x >= 2) fore(q, 1, m) {
				if (q != j) dp[i][j][x] = min(dp[i][j][x], dp[i - 1][q][x - 1] + p[i][j - 1]);
			}
		} else {
			if (x == 1) dp[i][j][x] = p[i][j - 1];
		}
		//cerr << i << ' ' << j << ' ' << x << ' ' << dp[i][j][x] << '\n';
		}
	}
	ll ans = LINF;
	fore(i, 1, m) {
		ans = min(ans, dp[n - 1][i][k]);
	}
	if (ans == LINF) ans = -1;
	cout << ans << '\n';
	return 0;
}