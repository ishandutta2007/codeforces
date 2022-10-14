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
struct num {
	int mask[8];
	ld val;
	num() {
		memset(mask, 0, sizeof mask);
		val = 1;
	}
	bool operator<(const num& o) const {
		return val < o.val;
	}
};

vector<num> p;
vector<num> q;
set<num> vis;

ll countLess(ll X) {
	ll i, j, ans = 0;
	i = 0;
	j = q.size() - 1;
	while (i < p.size() && p[i].val-X < 1e-2) {
		while (j > 0 && (p[i].val * q[j].val) - X > 1e-2)
			j--;
		i++;
		ans += j + 1;
	}
	return ans;
}

int main() {
	doin();
	ll n, k;
	vi a[2];
	cin >> n;
	for (int t, i = 0; i < n; i++) {
		cin >> t;
		a[i & 1].pb(t);
	}
	cin >> k;
	q.pb(num());
	for (int it = 0; it < q.size(); it++) {
		num i = q[it];
		for (int j = 0; j < a[0].size(); j++) {
			num t = i;
			t.mask[j]++;
			t.val *= a[0][j];
			if (t.val - 1e18 < 1e-2 && vis.insert(t).second)
				q.pb(t);
		}
	}

	vis.clear();
	p.pb(num());
	for (int it = 0; it < p.size(); it++) {
		num i = p[it];
		for (int j = 0; j < a[1].size(); j++) {
			num t = i;
			t.mask[j]++;
			t.val *= a[1][j];
			if (t.val - 1e18 < 1e-2 && vis.insert(t).second)
				p.pb(t);
		}
	}
	sort(all(p));
	sort(all(q));
//	cout << countLess(93);
	ll lo = 0, hi = (ll)1e18, mid;
	while(lo < hi) {
		mid = lo + (hi-lo+1)/2;
		if(countLess(mid) < k)
			lo = mid;
		else
			hi = mid-1;
	}
	cout << hi+1;
}