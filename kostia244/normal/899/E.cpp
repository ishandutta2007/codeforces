#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize ("trapv")
#include<bits/stdc++.h>
//#include<ext/pb_ds/tree_policy.hpp>
//#include<ext/pb_ds/assoc_container.hpp>
#define pb push_back
#define __V vector
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define oit ostream_iterator
#define mod 998244353ll
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
struct seg {
	int len, l, r, val;
	seg(int len = 0, int l = 0, int r=0, int val=0) {
		this->len = len;
		this->val = val;
		this->l = l;
		this->r = r;
	}
	bool operator<(const seg& rhs) const {
		return pi(len, -l) > pi(rhs.len, -rhs.l);
	}
};
int main() {
	doin();
	ll n;
	set<seg> s;
	set<int> starts;
	map<int, seg> startval;
	cin >> n;
	vi a;
	getv(a, n);
	int i = 0, j = 0;
	while (i < a.size()) {
		j = i;
		while (j < a.size() && a[i] == a[j])
			j++;
		s.insert(seg(j - i, i, j - 1, a[i]));
		starts.insert(i);
		startval[i] = seg(j - i, i, j - 1, a[i]);
		i = j;
	}
	int ans = 0;
	while (!s.empty()) {
		ans++;
		auto i = s.begin();
		seg t = *i;
		s.erase(i);
		starts.erase(t.l);
		startval.erase(t.l);
		auto r = starts.upper_bound(t.l);
		if (r == starts.end() || r == starts.begin())
			continue;
		auto l = r;
		--l;
		if (startval[*l].val != startval[*r].val)
			continue;
		seg tl(0, 0, 0,0), tr(0,0,0,0);

		i = s.find(startval[*l]);
		tl = t = *i;
		s.erase(i);
		starts.erase(t.l);
		startval.erase(t.l);

		i = s.find(startval[*r]);
		tr = t = *i;
		s.erase(i);
		starts.erase(t.l);
		startval.erase(t.l);

		s.insert(seg(tl.len+tr.len, tl.l, tr.r, tl.val));
		starts.insert(tl.l);
		startval[tl.l] = seg(tl.len+tr.len, tl.l, tr.r, tl.val);
	}
	cout << ans;
	return 0;
}