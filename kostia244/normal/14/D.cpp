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

template<typename T>
void getv(T& a, int n) {
	a.resize(n);
	for (auto& i : a)
		cin >> i;
}

typedef long long ll;
typedef int _I;
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
int n, f, t, ans = 0;
vvi g;
pi dfs(int u, int p) {
	int mx = 0, mx2 = 0;
	int res = 0;
	pi t;
	for (int v : g[u]) {
		if (v == p)
			continue;
		t = dfs(v, u);
		res = max(res, t.first);
		t.second++;
		if (t.second > mx) {
			mx2 = mx;
			mx = t.second;
		} else if (t.second > mx2) {
			mx2 = t.second;
		}
	}

	return {max(res, mx+mx2), mx};
}
vpi tst;
int main() {
	doin();
	cin >> n;
	g.resize(n + 1);
	for (int i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
		tst.pb( { f, t });
	}
	for (auto& i : tst) {
		t = dfs(i.first, i.second).first * dfs(i.second, i.first).first;
		if(t > ans)
			ans = t;
	}
	cout << ans;
}