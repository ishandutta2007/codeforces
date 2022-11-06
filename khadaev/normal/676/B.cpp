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

const int N = 2048;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, t;
	cin >> n >> t;
	vector<vector<int> > a(n);
	forn(i, 0, n) a[i].resize(i + 1);
	forn(i, 0, t) {
		a[0][0] += N;
		forn(i, 0, n) forn(j, 0, i + 1) if (a[i][j] > N) {
			int rest = a[i][j] - N;
			a[i][j] = N;
			if (i != n - 1) {
				a[i + 1][j] += rest / 2;
				a[i + 1][j + 1] += rest / 2;
			}
		}
	}
	int ans = 0;
	for (auto x : a) for (auto y : x) if (y >= N) ans++;
	cout << ans << '\n';
	return 0;
}