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

const int MAXH = 60;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	cin >> q;
	cout << fixed << setprecision(10);
	vector<int> par = {0, 0};
	vector<ld> p[MAXH];
	forn(i, 0, MAXH) p[i] = {1, 1};
	forn(i, 0, q) {
		int t, v;
		cin >> t >> v;
		if (t == 1) {
			par.eb(v);
			forn(i, 0, MAXH) p[i].eb(1);
			vector<int> path(MAXH);
			for (int j = 0; j < MAXH; ++j, v = par[v]) path[j] = v;
			ford(j, 1, MAXH) p[j][path[j]] /= (1 + p[j - 1][path[j - 1]]);
			p[0][path[0]] *= 0.5;
			forn(j, 1, MAXH) p[j][path[j]] *= (1 + p[j - 1][path[j - 1]]);
		} else {
			ld ans = 0;
			forn(i, 1, MAXH) ans += i * (p[i][v] - p[i - 1][v]);
			cout << ans << '\n';
		}
	}
	return 0;
}