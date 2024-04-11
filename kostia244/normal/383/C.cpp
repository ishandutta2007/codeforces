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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
struct fenwick {
	ll t[200100], sz;
	void init(int n) {
		sz = n;
		memset(t, 0, sizeof t);
	}
	void upd(int l, ll v) {
		while (l <= sz) {
			t[l] += v;
			l += l & -l;
		}
	}
	void upd(int l, int r, ll v) {
		upd(l, v);
		upd(r + 1, -v);
	}
	ll get(int i) {
		ll res = 0;
		while (i > 0) {
			res += t[i];
			i -= i & -i;
		}
		return res;
	}
};

fenwick f[2];
int n, q, timer = 1;
vvi g;
vi in, out, a, h;

void dfs(int v = 1, int p = -1) {
	in[v] = timer++;
	for (auto i : g[v])
		if (i != p)
			h[i] = h[v]+1, dfs(i, v);
	out[v] = timer - 1;
}

int main() {
	doin();
	cin >> n >> q;
	g.resize(n + 1);
	h.resize(n + 1);
	in.resize(n + 1);
	out.resize(n + 1);
	getv1(a, n);
	for (int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	dfs();
	int t, x, val;
	f[0].init(n);
	f[1].init(n);
	while(q--) {
		cin >> t >> x;
		if(t == 1) {
			cin >> val;
			f[h[x]&1].upd(in[x], out[x], val);
			f[1^(h[x]&1)].upd(in[x], out[x], -val);
		} else {
			cout << a[x]+f[h[x]&1].get(in[x]) << "\n";
		}
	}
}