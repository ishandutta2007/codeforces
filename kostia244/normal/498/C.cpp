#pragma GCC target ("avx2")
#pragma GCC target ("sse2")
#pragma GCC optimize ("Ofast")
#pragma GCC push_options
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define __V vector
#define all(x) x.begin(), x.end()
#define rall(x) x.begin(), x.end()
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
typedef long double ld;
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
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
int n, m, ltimer = 0, rtimer = 0;
vi a, match, vis;
map<int, int> can[110];
vpi e, part[2];
vvi g;

void factor(int num, int numidx) {
	for (int d = 2; d * 1ll * d <= num; d++) {
		if (num % d)
			continue;
		while (num % d == 0)
			num /= d, part[numidx&1].eb(d, numidx);
	}
	if(num != 1)
		part[numidx&1].eb(num, numidx);
}

bool aug(int v) {
	if(vis[v]) return 0;
	vis[v] = 1;
	for(auto i : g[v]) {
		if(match[i] == -1 || aug(match[i])) {
			match[i] = v;
			return 1;
		}
	}
	return 0;
}

int main() {
	doin();
	cin >> n >> m;
	getv1(a, n);
	for (int f, t, i = 0; i < m; i++) {
		cin >> f >> t;
		can[f][t] = can[t][f] = 1;
	}

	for (int i = 1; i <= n; i++) {
		factor(a[i], i);
	}
	g.resize(part[0].size());
	match.resize(part[1].size(), -1);
	for(int i = 0; i < part[0].size(); i++)
		for(int j = 0; j < part[1].size(); j++) {
			if(!can[part[0][i].second][part[1][j].second]) continue;
			if(part[0][i].first == part[1][j].first)
				g[i].pb(j);
		}
	int ans = 0;
	for(int i = 0; i < part[0].size(); i++) {
		vis.assign(part[0].size(), 0);
		ans += aug(i);
	}
	cout << ans;
}