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
//SQRT IS PROBABLY THE ANSWER
inline ll lastbit(ll x) {
	return x & (-x);
}
template<ll ... ArgsT> struct BIT {
	ull val = 0;
	void update(ll val) {
		this->val += val;
	}
	ll query() {
		return val;
	}
};
template<ll N, ll ... Ns>
struct BIT<N, Ns...> {
	map<int, BIT<Ns...>> bit;
	template<typename ... Args>
	void update(ll pos, Args ... args) {
		for (; pos <= N; bit[pos].update(args...), pos += lastbit(pos))
			;
	}
	template<typename ... Args>
	ll query(ll l, ll r, Args ... args) {
		ll ans = 0;
		for (; r >= 1; ans += bit[r].query(args...), r -= lastbit(r))
			;
		for (--l; l >= 1; ans -= bit[l].query(args...), l -= lastbit(l))
			;
		return ans;
	}
};
BIT<2600, 2600> b;

void update(ll x1, ll x2, ll y1, ll y2, ll val) {
	b.update(x1, y1, val);
	b.update(x2 + 1, y1, -val);
	b.update(x1, y2 + 1, -val);
	b.update(x2 + 1, y2 + 1, val);
}
ll get(ll x1, ll y1) {
	return b.query(1, x1, 1, y1);
}

int main() {
	doin();
	unsigned int n, m, q, he[2600][2600];
	cin >> n >> m >> q;
	for(ll i = 1; i <= n; i++)
		for(ll j = 1; j <= m; j++) {
			he[i][j] = (rng());
		}
	ll t, x1, x2, y1, y2;
	while(q--) {
		cin >> t >> x1 >> y1 >> x2 >> y2;
		if(t == 1) {
			update(x1, x2, y1, y2, he[x1][y1]);
//			cout << he[x1][y1] << "\n";
//			cout << get(x1, y1) << "\n";
		} else if(t == 2){
			update(x1, x2, y1, y2, ULLONG_MAX-he[x1][y1]+1);
		} else {
			ull a = get(x1, y1), b = get(x2, y2);
//			cout << x1 << " " << y1 << " " << a << "\n";
			cout << (a==b?"Yes":"No") << "\n";
		}
//		for(int i = 1; i <= n; i++){
//			for(int j = 1; j <= m; j++)
//				cout << get(i, j) << " ";
//			cout << "\n";
//		}
	}

}