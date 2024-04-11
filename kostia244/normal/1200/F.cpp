#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC target ("avx2,tune=native")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#define pb push_back
#define __V vector
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define oit ostream_iterator
#define mod 1000000007ll
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
//SQRT-heuristic divide items into groups: >sqrt and <=sqrt and do something according to group(eg. trie for one, z-func for other) - 1202E
uniform_real_distribution<double> double_dist(0, 1);
//WHEN DOING MODULAR SUBTRACTION ALWAYS **ALWAYS** ADD MOD
//don't use AVX at AtCoder(=RE)
//Trie: MAXDEPTH!=MAXSIZE
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, ans[1010][2520], in[1010][2520], k[1010], T = 0, timev[1010];
vvi g;
typedef tree<int, null_type, greater<int>, rb_tree_tag,
		tree_order_statistics_node_update> ordered_set;
ordered_set a;
int dfs(int v, int c) {
	c = (2520 + c + k[v]) % 2520, T++;
	if (ans[v][c])
		return ans[v][c];
	if (in[v][c]) {
		return ans[v][c] = a.order_of_key(in[v][c]-1);
	}
	if (timev[v])
		a.erase(timev[v]);
	a.insert(timev[v] = in[v][c] = T);
	int to = g[v][c % g[v].size()];
	return ans[v][c] = dfs(to, c);
}

int main() {
	doin();
	memset(ans, 0, sizeof ans);
	memset(in, 0, sizeof in);
	memset(timev, 0, sizeof timev);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> k[i], k[i] %= 2520;
	g.resize(n + 1);
	for (int m, i = 1; i <= n; i++) {
		cin >> m;
		getv(g[i], m);
	}
	int q, v, c;
	cin >> q;
	while (q--) {
		cin >> v >> c;
		c %= 2520;
		if (c < 0)
			c += 2520;
		cout << dfs(v, c) << "\n";
	}
}