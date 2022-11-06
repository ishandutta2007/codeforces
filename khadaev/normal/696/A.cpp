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

string bin(ll n) {
	if (n == 0) return "";
	return bin(n / 2) + (n % 2 ? "1" : "0");
}

vector<string> path(ll x, ll y) {
	vector<string> ans;
	string xs = bin(x), ys = bin(y);
	int i = 0;
	while (i < xs.length() && i < ys.length() && xs[i] == ys[i]) ++i;
	ford(j, i + 1, xs.length() + 1) ans.eb(xs.substr(0, j));
	forn(j, i, ys.length() + 1) ans.eb(ys.substr(0, j));
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int q;
	map<pair<string, string>, ll> cost;
	cin >> q;
	forn(t, 0, q) {
		int tp;
		cin >> tp;
		if (tp == 1) {
			ll u, v, w;
			cin >> u >> v >> w;
			vector<string> p = path(u, v);
			forn(i, 0, (int)(p.size()) - 1) {
				string x = p[i], y = p[i + 1];
				if (x > y) swap(x, y);
				cost[{x, y}] += w;
			}
		} else {
			ll u, v, ans = 0;
			cin >> u >> v;
			vector<string> p = path(u, v);
			forn(i, 0, (int)(p.size() - 1)) {
				string x = p[i], y = p[i + 1];
				if (x > y) swap(x, y);
				ans += cost[{x, y}];
			}
			cout << ans << '\n';
		}
	}
	return 0;
}