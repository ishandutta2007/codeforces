#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#define pb push_back
#define __V vector
#define all(x) x.begin(), x.end()
#define oit ostream_iterator
#define mod M
using namespace std;
void doin() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif
}
template<typename X, typename Y>
istream& operator>>(istream& in, pair<X, Y> &a) {
	in >> a.first >> a.second;
	return in;
}
template<typename T>
void getv(T& i) {
	cin >> i;
}
template<typename T, typename ... Ns>
void getv(vector<T>& v, int n, Ns ... ns) {
	v.resize(n);
	for (auto& i : v)
		getv(i, ns...);
}
template<typename T>
void getv1(T& i) {
	cin >> i;
}
template<typename T, typename ... Ns>
void getv1(vector<T>& v, int n, Ns ... ns) {
	v.resize(n + 1);
	for (int i = 1; i <= n; i++)
		getv(v[i], ns...);
}
#ifdef _WIN32
#define getchar_unlocked() _getchar_nolock()
#define _CRT_DISABLE_PERFCRIT_LOCKS
#endif
inline void getch(char &x) {
	while (x = getchar_unlocked(), x < 33) {
		;
	}
}
inline void getstr(string &str) {
	str.clear();
	char cur;
	while (cur = getchar_unlocked(), cur < 33) {
		;
	}
	while (cur > 32) {
		str += cur;
		cur = getchar_unlocked();
	}
}
template<typename T> inline bool sc(T &num) {
	bool neg = 0;
	int c;
	num = 0;
	while (c = getchar_unlocked(), c < 33) {
		if (c == EOF)
			return false;
	}
	if (c == '-') {
		neg = 1;
		c = getchar_unlocked();
	}
	for (; c > 47; c = getchar_unlocked())
		num = num * 10 + c - 48;
	if (neg)
		num *= -1;
	return true;
}
typedef unsigned long long ull;
typedef long long ll;
typedef float ld;
typedef int _I;
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
using AntonTsypko = void;
using arsijo = AntonTsypko;
using god = arsijo;
uniform_real_distribution<double> double_dist(0, 1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 2e4 + 5;
int n, m, f, t, ans = 0, waid = -1;
vvi g;
int col[N], h[N], dp[N][2], par[N];
map<pi, int> id;
bool bip(int v, int c = 1) {
	col[v] = c;
	bool ok = true;
	for (auto i : g[v]) {
		if (!col[i]) {
			ok&=bip(i, 3 ^ c);
		} else {
			ok &= (col[v] != col[i]);
		}
	}
	return ok;
}

void dfs(int v, int c = 1, int hi = 1, int p = 0) {
	col[v] = c;
	h[v] = hi;
	par[v] = p;
	for (auto i : g[v]) {
		if (!col[i]) {
			dfs(i, 3 ^ c, hi + 1, v);
			dp[v][0] += dp[i][0];
			dp[v][1] += dp[i][1];
		} else if (i != p) {
			bool idx = (col[v] != col[i]);
			if (!idx && f++ == 0)
				waid = id[ { i, v }];
			h[i] < h[v] ? ++dp[v][idx] : --dp[v][idx];
		}
	}
}

int main() {
	doin();
	cin >> n >> m;
	g.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> f >> t;
		id[ { f, t }] = id[ { t, f }] = i + 1;
		g[f].pb(t);
		g[t].pb(f);
	}
	t = -1;
	for (int v = 1; v <= n; v++) {
		if (col[v])
			continue;
		bool f = !bip(v);
		if (f) {
			if (t != -1)
				return cout << 0, 0;
			else
				t = v;
		}
	}
	for (int v = 1; v <= n; v++)
		col[v] = 0;
	if (t == -1) {
		cout << m << "\n";
		for (int i = 1; i <= m; i++)
			cout << i << " ";
		return 0;
	}
	f = 0;
	dfs(t);
	f /= 2;
	set<int> a;
	if (f == 1)
		ans++, a.insert(waid);
	for (int v = 2; v <= n; v++)
		if (dp[v][0] == f && dp[v][1] == 0)
			ans++, a.insert(id[ { v, par[v] }]);
	cout << ans << "\n";
	for (auto i : a)
		cout << i << " ";
}