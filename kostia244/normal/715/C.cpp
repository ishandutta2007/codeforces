#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
//#pragma GCC target ("avx2,tune=native")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#define pb push_back
#define __V vector
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define oit ostream_iterator
#define mod 998244853ll
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
//WHEN DOING MODULAR SUBTRACTION ALWAYS **ALWAYS** ADD MOD
//don't use AVX at AtCoder(=RE)
//Trie: MAXDEPTH!=MAXSIZE
//suspiciously big numbers? use python, seriosly you don't wanna waste your time if it overflows
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n, m;
ll res = 0, inv10;
vvpi g;
vi comp, sz, maxch;
mii numpath;
bitset<100100> isCentroid = 0;

int dfs(int v, int p) {
	sz[v] = 1;
	maxch[v] = 0;
	comp.pb(v);
	for (auto t : g[v]) {
		int i = t.first;
		if (i != p && !isCentroid.test(i)) {
			sz[v] += dfs(i, v);
			maxq(maxch[v], sz[i]);
		}
	}
	return sz[v];
}

void search(int v, int p, ll cur, ll ip = inv10) {
	ll t = m - (cur % m);
	t = (t * ip) % m;
	assert(t >= 0);
	res += numpath[t];
//	cout << v << " ";
	for (auto i : g[v]) {
		if (i.first == p || isCentroid.test(i.first))
			continue;
		search(i.first, v, (10ll * cur + i.second) % m, (ip * inv10) % m);
	}
}

void add(int v, int p, ll cur, ll p10 = 10 % m) {
	numpath[cur]++;
	for (auto i : g[v]) {
		if (i.first == p || isCentroid.test(i.first))
			continue;
		add(i.first, v, (cur + p10 * i.second) % m, (p10 * 1ll * 10) % m);
	}
}

void decomposition(int V) {
	vi().swap(comp);
	dfs(V, V);
	int centroid = -1;
	for (auto i : comp) {
		maxq(maxch[i], (int)comp.size() - sz[i]);
		if (maxch[i] <= (comp.size() + 1) / 2) {
			centroid = i;
			break;
		}
	}
	assert(centroid!=-1);
//	cout << i << " " << centroid << ":\n";

	isCentroid.set(centroid);

	mii().swap(numpath);
	numpath[0] = 1;
	for (auto t : g[centroid]) {
		int i = t.first;
		if (isCentroid.test(i))
			continue;
		search(i, centroid, t.second % m);
		add(i, centroid, t.second % m);
	}
	res += numpath[0]-1;

//	cout << "\n==================\n";
	reverse(all(g[centroid]));
	mii().swap(numpath);
	for (auto t : g[centroid]) {
		int i = t.first;
		if (isCentroid.test(i))
			continue;
		search(i, centroid, t.second % m);
		add(i, centroid, t.second % m);
	}
//	res += numpath[0];
//	cout << "\n";
	for (auto t : g[centroid])
		if (!isCentroid.test(t.first))
			decomposition(t.first);
}

int main() {
	doin();
	cin >> n >> m;
	inv10 = 1;
	if (m == 1) {
		cout << n * 1ll * (n - 1);
		return 0;
	}
	int PHI = 1, cc = m;
	for(ll d = 2; d * d <= cc; d++) {
		if(cc%d) continue;
		ll p = 1;
		while(cc%d == 0) cc/=d, p*=d;
		PHI *= p - p/d;
	}
	if(cc > 1) PHI*=cc-1;
	ll t = PHI - 1, q = 10;
	while (t) {
		if (t & 1) {
			inv10 *= q;
			inv10 %= m;
		}
		t >>= 1;
		q *= q;
		q %= m;
	}
	g.resize(n);
	sz.resize(n);
	maxch.resize(n);
	for (int a, b, c, i = 1; i < n; i++) {
		cin >> a >> b >> c;
		g[a].pb( { b, c });
		g[b].pb( { a, c });
	}
	decomposition(0);
	cout << res;
}