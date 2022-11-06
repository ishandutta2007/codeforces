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

const int N = 1002, K = 11;

int dp1[K][N][N], dp2[K][N][N];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	string s, t;
	cin >> s >> t;
	ford(i, 0, n) ford(j, 0, m) {
		if (i == n - 1 || j == m - 1) dp1[0][i][j] = 0;
		else dp1[0][i][j] = dp1[0][i + 1][j + 1];
		if (s[i] == t[j]) ++dp1[0][i][j];
		else dp1[0][i][j] = 0;
	}
	ford(i, 0, n) ford(j, 0, m) {
		dp2[0][i][j] = dp1[0][i][j];
		if (i < n - 1) dp2[0][i][j] = max(dp2[0][i][j], dp2[0][i + 1][j]);
		if (j < m - 1) dp2[0][i][j] = max(dp2[0][i][j], dp2[0][i][j + 1]);
	}
	forn(t, 1, k) {
		ford(i, 0, n) ford(j, 0, m) {
			int len = dp1[0][i][j];
			int _i = i + len, _j = j + len;
			if (_i == n || _j == m) dp1[t][i][j] = len;
			else dp1[t][i][j] = len + dp2[t - 1][_i][_j];
		}
		ford(i, 0, n) ford(j, 0, m) {
			dp2[t][i][j] = dp1[t][i][j];
			if (i < n - 1) dp2[t][i][j] = max(dp2[t][i][j], dp2[t][i + 1][j]);
			if (j < m - 1) dp2[t][i][j] = max(dp2[t][i][j], dp2[t][i][j + 1]);
		}
	}
	cout << dp2[k - 1][0][0] << '\n';

	return 0;
}