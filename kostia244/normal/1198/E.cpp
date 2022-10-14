#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC target ("avx2,tune=native")
#include<bits/stdc++.h>
// #include<ext/pb_ds/tree_policy.hpp>
// #include<ext/pb_ds/assoc_container.hpp>
#define pb push_back
#define __V vector
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define oit ostream_iterator
#define mod 1000000007ll
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
		getv1(v[i], ns...);
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
template<typename a, typename b>
void minq(a& x, b y) {
	if (x > y)
		x = y;
}
template<typename a, typename b>
void maxq(a& x, b y) {
	if (x < y)
		x = y;
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
//WHEN DOING MODULAR SUBTRACTION ALWAYS **ALWAYS** ADD MOD
//don't use AVX at AtCoder
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n, s, t, f[550][550], d[550], li[550];
vvi g;

void bfs() {
	memset(d, 0, sizeof d);
	queue<int> a;
	a.push(s);
	while (!a.empty()) {
		int u = a.front();
		a.pop();
		for (auto i : g[u]) {
			if (i == s || d[i] || f[u][i] == 0)
				continue;
			d[i] = d[u] + 1;
			a.push(i);
		}
	}
}

int dfs(int v, ll m = LLONG_MAX) {
	if (m == 0 || v == t)
		return m;
	for (; li[v] < g[v].size(); li[v]++) {
		int i = g[v][li[v]];
		if (d[v] + 1 != d[i] || f[v][i] == 0)
			continue;
		int t = dfs(i, min(m, f[v][i]));
		if (t > 0) {
			f[v][i] -= t;
			f[i][v] += t;
			return t;
		}
	}
	return 0;
}

ll dinic() {
	ll flow = 0;
	while (true) {
		bfs();
		ll f = 1, o = 0;
		memset(li, 0, sizeof li);
		while (f) {
			f = dfs(s);
			flow += f;
			if (f)
				o = 1;
		}
		if (!o)
			break;
	}
	return flow;
}
vi x, y;

void add_edge(int a, int b, int c) {
	f[a][b] += c;
//	f[b][a] += c;
	g[a].pb(b);
	g[b].pb(a);

}
struct rect {
	int l, r, u, d;
	void get() {
		cin >> l >> u >> r >> d;
		x.pb(l), x.pb(r + 1), y.pb(u), y.pb(d + 1);
	}
};

int main() {
	doin();
	memset(f, 0, sizeof f);
	int m;
	cin >> m >> m;
	vector<rect> v(m);
	for (auto& i : v)
		i.get();
	sort(all(x));
	x.erase(unique(all(x)), x.end());
	sort(all(y));
	y.erase(unique(all(y)), y.end());
	n = x.size() + y.size() + 2;
	g.resize(n);
	s = 0, t = n - 1;
	for (int i = 0; i+1 < x.size(); i++)
		add_edge(0, i + 1, x[i+1] - x[i]);
	for (int i = 0; i+1 < y.size(); i++)
		add_edge(x.size() + i + 1, n - 1, y[i+1] - y[i]);
	for (int i = 0; i < x.size(); i++) {
		int px = x[i];
		for (int j = 0; j < y.size(); j++) {
			int py = y[j];
			for (auto k : v) {
				if (px >= k.l && px <= k.r && py >= k.u && py <= k.d) {
					add_edge(1 + i, x.size() + j + 1, 2000000000);
					break;
				}
			}
		}
	}
	cout << dinic();
}