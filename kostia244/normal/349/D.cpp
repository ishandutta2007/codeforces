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
//#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
//#endif
}
template<typename T, typename l>
void getv(T& a, int n, l f) {
	a.resize(n);
	for (auto& i : a)
		cin >> i, f(i);
}
template<typename T>
void getv(T& a, int n) {
	a.resize(n);
	for (auto& i : a)
		cin >> i;
}
typedef unsigned long long ull;
typedef long long ll;
typedef double ld;
typedef ll _I;
typedef pair<_I, _I> pi;
typedef pair<ld, ld> pd;
typedef map<_I, _I> mii;
typedef __V <_I> vi;
typedef __V <char> vc;
typedef __V <ld> vd;
typedef __V <vd> vvd;
typedef __V <pi> vpi;
typedef __V <__V<_I>> vvi;
typedef __V <__V<char>> vvc;
typedef __V <__V<pi>> vvpi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n, f, t, lc = 1, ans = LLONG_MAX, res = 0, s = 0;
vi a, c;
vvi g;

void dfs(int v = 1, int p = 1, ll val = 1) {
	if(val > 10e8)
	{
		cout << fixed << s;
		exit(0);
	}
	c[v] = val;
	for (int i : g[v]) {
		if (i == p)
			continue;
		dfs(i, v, val * (g[v].size() - (v != 1)));
	}
	if(__gcd(lc, c[v]) == 0)
		cout << v << ", " << p << "(g[v].size() = " << g[v].size() << " )\n" << val << " " << lc << " " << c[v] << "\n", exit(254);
	lc = lc * (c[v] / __gcd(lc, c[v]));
}

int main() {
	doin();
	cin >> n;
	a.resize(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> a[i], s += a[i];
	g.resize(n + 1);
	c.resize(n + 1);
	for (int i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	dfs();
	for (int i = 2; i <= n; i++) {
		if (g[i].size() == 1)
			ans = min(ans, c[i] * a[i]);
	}
	ans = (ans / lc) * lc;
	for (int i = 2; i <= n; i++) {
		if (g[i].size() == 1) {
			res += a[i] - (ans / c[i]);
		}
	}
	cout << fixed << res;
}