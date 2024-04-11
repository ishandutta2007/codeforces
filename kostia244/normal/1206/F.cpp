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
typedef ll _I;
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
int n, root, A;
vi sz, maxch;
vvi g;

struct dsu {
	vi r,p;
	void init(int n) {
		r.assign(n+1, 1);
		p.resize(n+1);
		for(int i = 0; i<=n; i++) p[i] = i;
	}
	int par(int i) {
		return p[i] == i ? i : p[i] = par(p[i]);
	}
	void unite(int i, int j) {
		i = par(i), j = par(j);
		if(i == j) return;
		if(r[i] < r[j]) swap(i, j);
		p[j] = i, r[i] += j;
	}
};

void dfs(int v, int p) {
	sz[v] = 1;
	maxch[v] = 0;
	for (auto i : g[v])
		if (i != p) {
			dfs(i, v);
			sz[v] += sz[i];
			maxq(maxch[v], sz[i]);
		}
}

int get_centroid() {
	dfs(1, 1);
	for(int i = 1; i <= n; i++) {
		maxq(maxch[i], n-sz[i]);
		if(maxch[i] < (n+1)/2)
			return i;
	}
	return -1;//never happens
}

set<int> need[2];
dsu bi;

void efs(int v, int p = -1, int cur = 0, int comp = -1) {
	for(auto i : g[v]) {
		if(i == p) continue;
		if(v == root)
			comp = bi.par(i) != A;
		int X = (*need[comp].upper_bound(cur)) - cur;
		cout << v << " " << i << " " << X << "\n";
		need[comp].erase(need[comp].upper_bound(cur));
		efs(i, v, cur+X, comp);
	}
}

int main() {
	doin();
	cin >> n;
	if(n == 1)
		return 0;
	if(n == 2)
		return cout << "1 2 1", 0;
	g.resize(n + 1);
	sz.resize(n + 1);
	maxch.resize(n + 1);
	for (int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	root = get_centroid();
	dfs(root, root);
	set<pi> ch;
	for(auto i : g[root])
		ch.insert({sz[i], i});
	bi.init(n+1);
	while(ch.size() > 2) {
		set<pi>::iterator ait, bit;
		ait = bit = ch.begin();
		bit++;
		pi a = *ait;
		pi b = *bit;
		ch.erase(b);
		ch.erase(a);
		bi.unite(a.second, b.second);
		ch.insert({a.first+b.first, a.second});
	}
	set<pi>::iterator ait, bit;
	ait = bit = ch.begin();
	bit++;
	pi a = *ait;
	pi b = *bit;
	A = bi.par(ch.begin()->second);
	int asz = a.first;
	int bsz = b.first;
	for(int i = 1; i <= asz; i++)
		need[0].insert(i);
	for(int i = 1; i <= bsz; i++)
		need[1].insert(i*(asz+1));
	efs(root);
}