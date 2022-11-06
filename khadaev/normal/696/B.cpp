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
	cout << fixed << setprecision(10);
	int n;
	cin >> n;
	vector<int> p(n);
	forn(i, 1, n) {
		cin >> p[i];
		--p[i];
	}
	vector<int> sz(n);
	ford(i, 1, n) {
		++sz[i];
		sz[p[i]] += sz[i];
	}
	++sz[0];
	vector<ld> ans(n);
	ans[0] = 1.0;
	forn(i, 1, n) {
		ans[i] = ans[p[i]];
		ans[i] += 1.0;
		ans[i] += (sz[p[i]] - 1 - sz[i]) * 0.5;
	}
	forn(i, 0, n) cout << ans[i] << ' ';
	return 0;
}