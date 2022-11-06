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

vector<int> a, used, len;

int dfs(int v, int col, int l) {
	if (used[v] == col) {
		return l - len[v];
	}
	if (used[v] == 0) {
		used[v] = col;
		len[v] = l;
		return dfs(a[v], col, l + 1);
	}
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	a.resize(n), used.resize(n), len.resize(n);
	forn(i, 0, n) {
		cin >> a[i];
		--a[i];
	}
	ll ans = 1;
	int cycles = 0;
	forn(i, 0, n) {
		int s = dfs(i, i + 1, 0);
		if (s) {
			cycles += s;
			ll mul = 1;
			forn(j, 0, s) mul = 2 * mul % MOD;
			mul -= 2;
			if (mul < 0) mul += MOD;
			ans *= mul;
			ans %= MOD;
		}
	}
	forn(j, 0, n - cycles) ans = 2 * ans % MOD;
	cout << ans << '\n';
	return 0;
}