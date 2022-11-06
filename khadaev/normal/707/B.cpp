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
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> u(m), v(m), l(m);
	forn(i, 0, m) cin >> u[i] >> v[i] >> l[i];
	vector<int> is(n);
	forn(i, 0, k) {
		int x;
		cin >> x;
		is[--x] = 1;
	}
	int ans = INF;
	forn(i, 0, m) if (is[--u[i]] ^ is[--v[i]]) ans = min(ans, l[i]);
	if (ans == INF) ans = -1;
	cout << ans << '\n';
	return 0;
}