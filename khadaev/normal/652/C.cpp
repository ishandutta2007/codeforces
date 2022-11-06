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
#define eb emplace_back

#ifndef M_PI
const ld M_PI = 3.1415926535897932384626433;
#endif

const ld eps = 1e-9;
const int INF = 2000000000;
const ll LINF = 1ll * INF * INF;
const ll MOD = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> p(n), invp(n);
	forn(i, 0, n) {
		int c;
		cin >> c;
		--c;
		p[i] = c;
		invp[c] = i;
	}
	vector<pair<int, int> > bnd(m);
	forn(i, 0, m) {
		int a, b;
		cin >> a >> b;
		--a, --b;
		a = invp[a], b = invp[b];
		if (a > b) swap(a, b);
		bnd[i] = {a, b};
	}
	sort(all(bnd));
	vector<pair<int, int> > suff;
	forn(i, 0, m) {
		//if (!suff.empty() && bnd[i].fs == suff.back().fs) continue;//suff.pop_back();
		while (!suff.empty() && bnd[i].sn < suff.back().sn) suff.pop_back();
		suff.eb(bnd[i]);
	}
	//for (auto p : suff) cout << p.fs << ' ' << p.sn << '\n';
	int s = suff.size();
	ll ans = 1ll * (suff[0].fs + 1) * (n - suff[0].sn);
	forn(i, 1, s) {
		ans += 1ll * (suff[i].fs - suff[i - 1].fs) * (n - suff[i].sn);
	}
	cout << 1ll * n * (n + 1) / 2 - ans << '\n';
	return 0;
}