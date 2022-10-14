#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC target ("avx2,tune=native")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#define pb push_back
#define __V vector
#define all(x) x.begin(), x.end()
#define oit ostream_iterator
#define mod 1000000007ll
using namespace std;
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
typedef float ld;
typedef ll _I;
typedef pair<_I, _I> pi;
typedef pair<ld, ld> pd;
typedef map<_I, _I> mii;
typedef __V <_I> vi;
typedef __V <char> vc;
typedef __V <ld> vd;
typedef __V <vd> vvd;
typedef __V <pi> vpi;
typedef __V <__V<_I>> vvi;
typedef __V <__V<char>> vvc;
typedef __V <__V<pi>> vvpi;
using AntonTsypko = void;
using arsijo = AntonTsypko;
using god = arsijo;
uniform_real_distribution<double> double_dist(0, 1);
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, k, ans = 0, val[2002][2002], rl[2002], cl[2002], rr[2002], cr[2002];
#define upd(x, y, x1, y1) ++val[x][y],--val[x][y1 + 1],--val[x1 + 1][y],++val[x1 + 1][y1 + 1];
#define max(x, y) (x > y ? x : y)

int main() {
	memset(rl, -1, sizeof rl);
	memset(cl, -1, sizeof cl);
	memset(rr, -1, sizeof rr);
	memset(cr, -1, sizeof cr);
	sc(n), sc(k);
	string s;
	for (int i = 1; i <= n; i++) {
		getline(cin, s);
		for (int j = 1; j <= n; j++) {
			if (s[j-1] == 'B') {
				if (rl[i] == -1)
					rl[i] = j;
				if (cl[j] == -1)
					cl[j] = i;
				rr[i] = j, cr[j] = i;
			}
		}
	}
	int lo, hi;
	for (int i = 1; i <= n; i++) {
		lo = rl[i], hi = rr[i];
		if (lo == -1) {
			upd(1, 1, n, n);
		} else {
			if (hi - lo + 1 > k)
				continue;
			upd(max(1, i - k + 1), max(1, hi - k + 1), i, lo);
		}
	}
	for (int i = 1; i <= n; i++) {
		lo = cl[i], hi = cr[i];
		if (lo == -1) {
			upd(1, 1, n, n);
		} else {
			if (hi - lo + 1 > k)
				continue;
			upd(max(1, hi - k + 1), max(1, i - k + 1), lo, i);
		}
	}
	for (int i = 1; i + k - 1 <= n; i++) {
		for (int j = 1; j + k - 1 <= n; j++) {
			val[i][j] += val[i - 1][j] + val[i][j - 1] - val[i - 1][j - 1];
			ans = max(ans, val[i][j]);
		}
	}
	cout << ans;
	return 0;
}