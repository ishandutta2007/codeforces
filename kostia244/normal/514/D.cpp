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
//f-e+v=2
uniform_real_distribution<double> double_dist(0, 1);
uniform_int_distribution<int> dist(31, 55);
//WHEN DOING MODULAR SUBTRACTION ALWAYS **ALWAYS** ADD MOD
//don't use AVX at AtCoder(=RE)
//Trie: MAXDEPTH!=MAXSIZE
//suspiciously big numbers? use python, seriosly you don't wanna waste your time if it overflows
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//SQRT IS PROBABLY THE ANSWER
const int MAXN = 200000;
const int MAXLOG = 18;

struct sparse_table {
	int dp[MAXN][MAXLOG];
	int prec_lg2[MAXN], n;

	sparse_table() {
		memset(dp, 0, sizeof(dp));
		memset(prec_lg2, 0, sizeof(prec_lg2));
		n = 0;
	}

	void init(vector<int> &a) {
		n = a.size();
		for (int i = 2; i < 2 * n; i++)
			prec_lg2[i] = prec_lg2[i >> 1] + 1;
		for (int i = 0; i < n; i++)
			dp[i][0] = a[i];
		for (int j = 1; (1 << j) <= n; j++)
			for (int i = 0; i < n; i++)
				dp[i][j] = max(dp[i][j - 1], dp[i + (1 << (j - 1))][j - 1]);
	}

	int query(int l, int r) {
		int k = prec_lg2[r - l + 1];
		return max(dp[l][k], dp[r - (1 << k) + 1][k]);
	}
};

int n, m, k;
vi a[5];
sparse_table st[5];

int check(int l) {
	if (l == 0)
		return 0;
	for (int i = l - 1; i < n; i++) {
		ll sm = 0;
		for (int j = 0; j < m; j++)
			sm += st[j].query(i - l + 1, i);
		if (sm <= k)
			return i;
	}
	return -1;
}

int main() {
	doin();
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int t, j = 0; j < m; j++) {
			cin >> t;
			a[j].pb(t);
		}
	}
	for (int i = 0; i < m; i++)
		st[i].init(a[i]);
	int lo = 0, hi = n, mid;
	while (lo < hi) {
		mid = lo + (hi - lo + 1) / 2;
		if (check(mid) != -1)
			lo = mid;
		else
			hi = mid - 1;
	}
	if (hi == 0) {
		for (int j = 0; j < m; j++) cout << 0 << " ";
	} else {
		int i = check(hi);
		for (int j = 0; j < m; j++)
			cout << st[j].query(i-hi+1, i) << " ";
	}
	return 0;
}