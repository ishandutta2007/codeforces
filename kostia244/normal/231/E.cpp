#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#define pb push_back
#define __V vector
#define all(x) x.begin(), x.end()
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
const int N = 3e5 + 10;
int n, m, cid[N], cnt[N], h[N], ti[N], to[N], nd[N], f, T = 0;
vvi olg, dp;
vector<set<int>> g;
vpi edges;

void predfs(int v, int p = -1, int hh = 0) {
	cid[v] = v;
	h[v] = hh;
	bool son = true;
	for (auto i : olg[v]) {
		if (h[i]) {
			if (i != p && h[i] < h[v]) {
				nd[i] = 1;
				cid[v] = f++;
				son = false;
			}
			continue;
		}
		predfs(i, v, hh + 1);
		if (son && !nd[i]) {
			cid[v] = cid[i];
		}
	}
	if(cid[v] == v) nd[v] = 1;
}

void dfs(int v, int p = 0, int c = 0) {
	c += (v > n);
	cnt[v] = c;
	ti[v] = T++;
	dp[v][0] = p;
	for (int i = 1; i < 17; i++) {
		dp[v][i] = dp[dp[v][i - 1]][i - 1];
	}
	for(auto i : g[v])
		if(i != p && i != v)
			dfs(i, v, c);
	to[v] = T++;
}
bool up(int u, int v) {
	return ti[u] <= ti[v] && to[u] >= to[v];
}
int lca(int a, int b) {
	if(up(a, b)) return a;
	if(up(b, a)) return b;
	for(int i = 16; i >= 0; --i) {
		if(dp[a][i] &&  !up(dp[a][i], b)) a = dp[a][i];
	}
	return dp[a][0];
}

int main() {
	doin();
	cin >> n >> m;
	int t;
	olg.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		cin >> f >> t;
		edges.pb( { f, t });
		olg[f].pb(t);
		olg[t].pb(f);
	}
	f = n + 1;
	predfs(1);
	g.resize(n + m + 10);
	dp.resize(n + m + 10, vi(17));
	for (auto i : edges) {
		f = i.first, t = i.second;
		f = cid[f], t = cid[t];
		g[f].insert(t);
		g[t].insert(f);
	}
	dfs(cid[1]);
	cin >> m;
	int p2[N];
	p2[0] = 1;
	for(int i = 1; i < N; i++)
		p2[i] = (p2[i-1]<<1)%mod;
	while(m--){
		cin >> f >> t;
		f = cid[f], t = cid[t];
		int a = lca(f, t);
		a = cnt[f]+cnt[t]-cnt[a]-cnt[dp[a][0]];
		cout << p2[a] << "\n";
	}
}