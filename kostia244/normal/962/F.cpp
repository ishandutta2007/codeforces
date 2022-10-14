#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma comment(linker, "/STACK:16777216")
//#pragma GCC target ("avx2,tune=native")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#define pb push_back
#define __V vector
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define oit ostream_iterator
#define mod 998244353ll
using namespace std;
using namespace __gnu_pbds;
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
typedef long double ld;
typedef int _I;
typedef pair<_I, _I> pi;
typedef pair<ld, ld> pd;
typedef map<_I, _I> mii;
typedef __V <_I> vi;
typedef __V <char> vc;
typedef __V <string> vs;
typedef __V <ld> vd;
typedef __V <vd> vvd;
typedef __V <pi> vpi;
typedef __V <__V<_I>> vvi;
typedef __V <__V<char>> vvc;
typedef __V <__V<pi>> vvpi;
using AntonTsypko = void;
using arsijo = AntonTsypko;
using god = arsijo;
//store differences, not the elements for rsq in fenwick or array(for write-only)
//Sum Over Subsets + inclusion-exclusion is a thing! (Solved div1E (383E) using it!)
//SQRT-heuristic divide items into groups: >sqrt and <=sqrt and do something according to group(eg. trie for one, z-func for other) - 1202E
uniform_real_distribution<double> double_dist(0, 1);
uniform_int_distribution<int> dist(4, 55);
//WHEN DOING MODULAR SUBTRACTION ALWAYS **ALWAYS** ADD MOD
//don't use AVX at AtCoder(=RE)
//Trie: MAXDEPTH!=MAXSIZE
//suspiciously big numbers? use python, seriosly you don't wanna waste your time if it overflows
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//SQRT DECOMP. IS PROBABLY THE ANSWER
struct dsu {
	int sz;
	vi p, r;
	void init(int n) {
		sz = n;
		p.resize(n + 1);
		for (int i = 1; i <= n; i++)
			p[i] = i;
		r.assign(n, 1);
	}
	int par(int i) {
		return p[i] == i ? i : p[i] = par(p[i]);
	}
	void unite(int i, int j) {
		i = par(i), j = par(j);
		if (i == j)
			return;
		if (r[i] < r[j])
			swap(i, j);
		p[j] = i;
		r[i] += r[i] == r[j];
	}
};
vvpi g;
vi h, p, ans;
vpi inv;
void dfs(int v, int pr = -1) {
	p[v] = pr;
	for (auto t : g[v]) {
		int i = t.first;
		if (i == pr)
			continue;
		if (!h[i]) {
			h[i] = h[v] + 1;
			dfs(i, v);
		} else if (h[i] < h[v]) {
			inv.pb( { v, i });
		}
	}
}

int main() {
//	doin();
	int n, m;
	cin >> n >> m;
	g.resize(n + 1);
	h.resize(n + 1);
	p.resize(n + 1);
	mii idx[100100];
	for (int f, t, i = 0; i < m; i++) {
		cin >> f >> t;
		idx[f][t] = idx[t][f] = i+1;
		g[f].pb( { t, i });
		g[t].pb( { f, i });
	}
	for (int i = 1; i <= n; i++) {
		if (h[i] == 0) {
			h[i] = 1;
			dfs(i);
		}
	}
	dsu d;
	vi pp = p;
	d.init(inv.size());
	vi index(n + 1, -1), num(inv.size(), 0);
	for (int i = 0; i < inv.size(); i++) {
		int v = inv[i].first;
		vi path;
		while (h[v] > h[inv[i].second]) {
			if (index[v] == -1)
				index[v] = i;
			else
				d.unite(i, index[v]);
			path.pb(v);
			v = p[v];
		}
		for (auto k : path)
			p[k] = inv[i].second;
	}
	vi res;
	for (int i = 0; i < inv.size(); i++)
		num[d.par(i)]++;
	for (int i = 0; i < inv.size(); i++) {
		if (num[i] == 1) {
			int v = inv[i].first;
//			cout << inv[i].first << " " << inv[i].second << "\n";
			res.pb(idx[inv[i].first][inv[i].second]);
			while (h[v] > h[inv[i].second]) {
				if (index[v] == -1)
					index[v] = i;
				else
					d.unite(i, index[v]);
				res.pb(idx[v][pp[v]]);
				v = pp[v];
			}
		}
	}
	sort(all(res));
	cout << res.size() << "\n";
	for(auto i : res) cout << i << " ";

}