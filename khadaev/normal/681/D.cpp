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

void fail() {
	cout << "-1\n";
	exit(0);
}

void dfs(vector<vector<int> > &ch, vector<char> &need, int i) {
	//if (was[i]) return;
	//was[i] = 1;
	for (int j : ch[i]) dfs(ch, need, j);
	if (need[i]) cout << i + 1 << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m, n;
	cin >> n >> m;
	vector<int> par(n, -1);
	vector<vector<int> > ch(n);
	forn(i, 0, m) {
		int p, q;
		cin >> p >> q;
		--p, --q;
		par[q] = p;
		ch[p].eb(q);
	}
	vector<int> a(n);
	vector<char> need(n, 0), was(n, 0);
	forn(i, 0, n) cin >> a[i];
	
	int cnt = 0;
	forn(i, 0, n) --a[i];
	forn(i, 0, n) {
		if (a[i] == i) {
			need[i] = 1;
			++cnt;
			continue;
		}
		if (par[i] == -1 || a[i] != a[par[i]]) {
			fail();
		}
	}
	cout << cnt << '\n';
	forn(i, 0, n) if (par[i] == -1) dfs(ch, need, i);
	return 0;
}