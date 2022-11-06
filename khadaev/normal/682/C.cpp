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

int n;
vector<ll> a;
vector<vector<pair<int, ll> > > e;
vector<ll> dists, da, mind;
vector<char> was;
vector<char> ok;

void dfs1(int i, ll d) {
	if (dists[i] != LINF) return;
	dists[i] = d;
	for (auto x : e[i]) dfs1(x.fs, d + x.sn);
}

void dfs2(int i, ll val) {
	if (was[i]) return;
	was[i] = 1;
	mind[i] = min(val, dists[i]);
	for (auto x : e[i]) dfs2(x.fs, mind[i]);
}

int ans;

void dfs3(int i) {
	if (was[i]) return;
	if (!ok[i]) return;
	was[i] = 1;
	++ans;
	for (auto x : e[i]) dfs3(x.fs);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	a.resize(n);
	e.resize(n);
	forn(i, 0, n) cin >> a[i];
	forn(i, 0, n - 1) {
		int p;
		cin >> p;
		--p;
		ll c;
		cin >> c;
		e[i + 1].eb(p, c);
		e[p].eb(i + 1, c);
	}
	dists.resize(n);
	fill(all(dists), LINF);
	dfs1(0, 0);
	da.resize(n);
	forn(i, 0, n) da[i] = dists[i] - a[i];
	mind.resize(n);
	was.resize(n);
	dfs2(0, LINF);
	ok.resize(n);
	forn(i, 0, n) ok[i] = mind[i] >= da[i];
	//forn(i, 0, n) cerr << mind[i] << ' ' << da[i] << '\n';
	ans = 0;
	fill(all(was), 0);
	dfs3(0);
	cout << n - ans << '\n';
	return 0;
}