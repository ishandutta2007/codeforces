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
int P = dist(rng);
struct dsu {
	vi r, p;
	void init(int n) {
		r.assign(n, 0);
		p.resize(n);
		for(int i = 1; i < n; i++) p[i] = i;
	}
	int par(int i) {
		return i == p[i] ? i : p[i] = par(p[i]);
	}
	void unite(int i, int j) {
		i = par(i), j = par(j);
		if(i == j) return;
		if(r[i] < r[j]) swap(i, j);
		p[j] = i, r[i] += r[i] == r[j];
	}
	bool sameset(int i, int j) {
		return par(i) == par(j);
	}
};

ll mhash(string& s) {
	ll p = 1, h = 0;
	for(int i = 0; i < s.size(); i++) {
		h += (s[i]-'A')*p;
		p*=P;
	}
//	cout << s << " " << h << "\n";
	return h;
}

int n, m, q, sz = 0;
map<ll, int> _id, _iid;
void setid(string& s) {
//	cout << s << "\n";
	ll c = mhash(s);
//	cout << c << " " << sz << "\n";
	_id[c] = sz++;
//	cout << c << " - " << sz << "\n";
	_iid[c] = sz++;
}
pi getid(string& s) {
	ll c = mhash(s);
//	cout << c << " " << _id[c] << "\n";
	return {_id[c], _iid[c]};
}

int main() {
	doin();
	cin >> n >> m >> q;
	string a, b;
	for(int i = 0; i < n; i++) {
		cin >> a;
		setid(a);
	}
	dsu d;
	d.init(sz);
	for(int t, i = 0; i < m; i++) {
		cin >> t >> a >> b;
		pi aid = getid(a);
		pi bid = getid(b);
		if(t == 1) {
//			cout << aid.first << " " << bid.second << "\n";
			if(d.sameset(aid.first, bid.second))
				cout << "NO";
			else {
				cout << "YES";
				d.unite(aid.first, bid.first);
				d.unite(aid.second, bid.second);
			}
		} else {
			if(d.sameset(aid.first, bid.first))
				cout << "NO";
			else {
				cout << "YES";
				d.unite(aid.first, bid.second);
				d.unite(aid.second, bid.first);
			}
		}
		cout << "\n";
	}
	while(q--) {
		cin >> a >> b;
		pi aid = getid(a);
		pi bid = getid(b);
		cout << (d.sameset(aid.first, bid.first) ? 1 : (d.sameset(aid.first, bid.second) ? 2 : 3)) << "\n";
	}
}