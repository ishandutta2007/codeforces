#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
//#pragma GCC target ("avx2,tune=native")
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
using AntonTsypko = void;
using arsijo = AntonTsypko;
using god = arsijo;
uniform_real_distribution<double> double_dist(0, 1);
//WHEN DOING MODULAR SUBTRACTION ALWAYS **ALWAYS** ADD MOD
//don't use AVX at AtCoder
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll n, s, t, f[4020][4020], d[4020], li[4020], deg[4020];
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
ll flow = 0;

ll dinic() {
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

int main() {
	doin();
	memset(f, 0, sizeof f);
	memset(deg, 0, sizeof deg);
	ll l, r, k = 5000, m;
	cin >> l >> r >> m;
	n = l + r + 2;
	s = 0, t = n - 1;
	g.resize(n);
	vi el2[2019][2019];
	vpi el;
	for (ll a, b, c, i = 0; i < m; i++) {
		cin >> a >> b, b += l;
		deg[a]++, deg[b]++;
		f[a][b]++;
		g[a].pb(b);
		g[b].pb(a);
		el2[a][b-l].pb(i + 1);
		el.pb( { a, b });
	}
	sort(el.begin(), el.end());
	el.erase(unique(el.begin(), el.end()), el.end());
	for (int i = 1; i <= l + r; i++)
		k = min(k, deg[i]);
	for (int i = 1; i <= l; i++) {
		f[0][i] = deg[i] - k;
		g[0].pb(i);
		g[i].pb(0);
	}
	for (int i = l + 1; i <= l + r; i++) {
		f[i][l + r + 1] = deg[i] - k;
		g[l + r + 1].pb(i);
		g[i].pb(l + r + 1);
	}
	vvi ans;
	ans.resize(k+1);
	for(int A = k; A>=0; A--) {
		dinic();
		for (auto i : el) {
			for(int j = f[i.second][i.first]; j < el2[i.first][i.second-l].size(); j++) {
				ans[A].pb(el2[i.first][i.second-l][j]);
			}
		}
		for (int i = 1; i <= l; i++) {
			f[0][i]++;
		}
		for (int i = l + 1; i <= l + r; i++) {
			f[i][l + r + 1]++;
		}
	}
	for(auto i : ans) {
		cout << i.size() << " ";
		for(auto j : i) {
			cout << j << " ";
		}
		cout << "\n";
	}
	return 0;
}