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
//Sum Over Subsets + inclusion-exclusion is a thing! (Solved div1E (383E) using it!)
//SQRT-heuristic divide items into groups: >sqrt and <=sqrt and do something according to group(eg. trie for one, z-func for other) - 1202E
//f-e+v=2
uniform_real_distribution<double> double_dist(0, 1);
uniform_int_distribution<int> dist(31, 55);
//WHEN DOING MODULAR SUBTRACTION ALWAYS **ALWAYS** ADD MOD
//don't use AVX at AtCoder(=RE)
//Trie: MAXDEPTH!=MAXSIZE
//suspiciously big numbers? use python, seriosly you don't wanna waste your time if it overflows
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//SQRT IS PROBABLY THE ANSWER
//SET TO ZERO
void print(int a, int b) {
	cout << (a&1?'^':' ') << (a>>1) << " v ";
	cout << (b&1?'^':' ') << (b>>1) << "\n";
}
struct sat {
	int n;
	vvi g, gt;
	vi order, used, comp;
	void init(int sz) {
		n = 2 * sz;
		g.assign(n, { });
		gt.assign(n, { });
	}
	void topo(int v) {
		used[v] = 1;
		for (int i : g[v])
			if (!used[i])
				topo(i);
		order.pb(v);
	}
	void dfs(int v, int c) {
		comp[v] = c;
		for (auto i : gt[v])
			if (!comp[i])
				dfs(i, c);
	}
	bool solve(vi& sol) {
		used.assign(n, 0);
		for (int i = 0; i < n; i++)
			if (!used[i])
				topo(i);
		reverse(all(order));

		int c = 0;
		comp.assign(n, 0);
		for (int i = 0; i < n; i++)
			if (!comp[order[i]])
				dfs(order[i], ++c);

		sol.assign(n / 2, 0);
		for (int i = 0; i < n; i += 2) {
			if (comp[i] == comp[i + 1])
				return false;
			sol[i / 2] = comp[i] > comp[i + 1];
		}
		return true;
	}
	void add_conj(int x, int y) {
//		print(x, y);
		g[x ^ 1].pb(y);
		gt[y].pb(x ^ 1);

		g[y ^ 1].pb(x);
		gt[x].pb(y ^ 1);
	}
};
#define pos(x) 2*x
#define neg(x) 2*x+1

int n, m;
sat s;

void add(int a, int b) {
	if(a < b) {
		s.add_conj(neg(a), pos(b));
	} else {
		s.add_conj(pos(a), pos(b));
		s.add_conj(neg(a), neg(b));
		s.add_conj(neg(a), pos(b));
	}
}

int main() {
	doin();
	cin >> n >> m;
	vvi a;
	int l;
	a.resize(n);
	for (auto& i : a) {
		cin >> l;
		getv(i, l);
		for(auto& j : i) j--;
	}
	s.init(m);
	for (int i = 0; i + 1 < n; i++) {
		int j = 0;
		while(j < min(a[i].size(), a[i+1].size()) && a[i][j] == a[i+1][j]) j++;
		if(j == min(a[i].size(), a[i+1].size())) {
			if(a[i].size() > a[i+1].size())
				return cout << "No", 0;
		} else {
			add(a[i][j], a[i+1][j]);
		}
	}
	vi sol;
	if(!s.solve(sol))
		return cout << "No\n", 0;
	cout << "Yes\n";
	vi ans;
	for(int i = 0; i < m; i++)
		if(sol[i] == 0)
			ans.pb(i+1);
	cout << ans.size() << "\n";
	for(auto i : ans) cout << i << " ";

	return 0;
}