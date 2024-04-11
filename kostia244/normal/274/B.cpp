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
//  freopen("input.txt", "r", stdin);
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
int n, f, t;
ll ans = 0;
vvi g;
vi a;

pi dfs(int v = 1, int p = -1) {
	ll md = 0, mi = 0;
	for (auto& i : g[v]) {
		if (i != p) {
			auto t = dfs(i, v);
			md = max(md, t.first);
			mi = max(mi, t.second);
		}
	}
	a[v]+=mi;
	a[v]-=md;
	return {md + max(0ll, a[v]), mi + max(0ll, -a[v])};
}

int main() {
	doin();
	cin >> n;
	g.resize(n + 1);
	a.resize(n + 1);
	for (int i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	auto t = dfs();
	cout << fixed << t.first + t.second;
}