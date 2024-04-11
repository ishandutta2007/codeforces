#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first.first
#define yy first.second
#define __V vector
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define oit ostream_iterator
#define mod 1000000007ll
using namespace __gnu_pbds;
using namespace std;
void doin() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
#ifdef LOCAL
//	freopen("in", "r", stdin);
#endif
}
typedef long long ll;
typedef ll _I;
typedef double ld;
typedef pair<_I, _I> pi;
typedef pair<ld, ld> pd;
typedef map<_I, _I> mii;
typedef __V <_I> vi;
typedef __V <char> vc;
typedef __V <ld> vd;
typedef __V <pi> vpi;
typedef __V <__V<_I>> vvi;
typedef __V <__V<char>> vvc;
typedef __V <__V<pi>> vvpi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, t;
bitset<300005> m;
vvi g;
vi dp, sz;
void dfs(int v) {
	dp[v] = m.test(v) ? INT_MAX : 0;sz[v] = 0;
	for (auto& i : g[v]) {
		dfs(i);
		sz[v] += sz[i];
	}
	for (auto& i : g[v]) {
		if(m.test(v)) {
			dp[v] = min(dp[v], dp[i]);
		} else {
			dp[v] += dp[i];
		}
	}
	if (g[v].empty()) {
		dp[v] = sz[v] = 1;
	}
}
int main() {
	doin();
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> t;
		if (t)
			m.set(i);
	}
	g.resize(n + 1);
	dp.resize(n + 1);
	sz.resize(n + 1);
	for (int i = 2; i <= n; i++) {
		cin >> t;
		g[t].pb(i);
	}
	dfs(1);
	cout << sz[1]-dp[1]+1;
	return 0;
}