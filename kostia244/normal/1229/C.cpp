#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize ("trapv")
#include<bits/stdc++.h>
//#include<ext/pb_ds/tree_policy.hpp>
//#include<ext/pb_ds/assoc_container.hpp>
#define pb push_back
#define eb emplace_back
#define __V vector
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define oit ostream_iterator
#define mod 1000000007ll
#define print(x) for(auto i : (x)) cout << i << " ";cout << "\n";
#define printd(x) for(auto i : (x)) cout << i << " ";cout << #x << "\n";
using namespace std;
//using namespace __gnu_pbds;
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
inline void getch(char &X) {
	while (X = getchar_unlocked(), X < 33) {
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
void minq(a& X, b Y) {
	if (X > Y)
		X = Y;
}
template<typename a, typename b>
void maxq(a& X, b Y) {
	if (X < Y)
		X = Y;
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
//f-e+v=2
uniform_real_distribution<double> double_dist(0, 1);
uniform_int_distribution<int> dist(31, 55);
//WHEN DOING MODULAR SUBTRACTION ALWAYS **ALWAYS** ADD MOD
//don't use AVX at AtCoder(=RE)
//Trie: MAXDEPTH!=MAXSIZE
//suspiciously big numbers? use python, seriosly you don't wanna waste your time if it overflows
//MULTISET NOT SET
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//SQRT IS PROBABLY THE ANSWER
//SET TO ZERO
//typedef tree<int, null_type, greater<int>, rb_tree_tag,
//		tree_order_statistics_node_update> ordered_set; // order_of_key, find_by_order
int n, m = 0;
ll ans = 0;
vvi g;
vi ls, ge, deg;

void add(ll v) {
	ans += ls[v] * 1ll * ge[v];
}
void sub(ll v) {
	ans -= ls[v] * 1ll * ge[v];
}

int main() {
	doin();
	cin >> n >> m;
	g.resize(n + 1);
	ls.resize(n + 1);
	ge.resize(n + 1);
	deg.resize(n + 1);
	for (int f, t, i = 0; i < m; i++) {
		cin >> f >> t;
		if(t > f)
			swap(t, f);
		g[t].pb(f);
		ls[f]++;
		ge[t]++;
		deg[f]++;
		deg[t]++;
	}for(int i = 1; i <= n; i++) add(i);
	int q, v;
	cin >> q;
	cout << ans << "\n";
	for(int vl = n+1; vl <= n+q; vl++) {
		cin >> v;
		for(auto i : g[v]) {
			g[i].pb(v);
			sub(i);
			ge[i]++;
			ls[i]--;
			add(i);
		}
		sub(v);
		ls[v] = deg[v];
		ge[v] = 0;
		g[v].clear();
		cout << ans << "\n";
	}
	return 0;
}