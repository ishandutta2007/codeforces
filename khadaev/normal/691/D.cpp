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

struct DSU {
	int n;
	vector<int> p;

	DSU () {};

	DSU (int sz) {
		n = sz;
		p.resize(n);
		for (int i = 0; i < n; ++i) p[i] = i;
	}

	void add() {
		p.emplace_back(n);
		++n;
	}

	void unite(int i, int j) {
		i = get(i);
		j = get(j);
		if (rand() % 2) swap(i, j);
		if (i != j) p[i] = j;
	}

	int get(int i) {
		if (i == p[i]) {
			return i;
		}
		return p[i] = get(p[i]);
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> p(n);
	forn(i, 0, n) {
		cin >> p[i];
	}
	DSU dsu(n);
	forn(i, 0, m) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		dsu.unite(a, b);
	}
	vector<vector<int>> x(n), y(n);
	forn(i, 0, n) x[dsu.get(i)].eb(-p[i]);
	forn(i, 0, n) y[dsu.get(i)].eb(i);
	forn(i, 0, n) sort(all(x[i]));
	vector<int> ans(n);
	forn(i, 0, n) forn(j, 0, x[i].size()) ans[y[i][j]] = -x[i][j];
	forn(i, 0, n) cout << ans[i] << '\n';
	return 0;
}