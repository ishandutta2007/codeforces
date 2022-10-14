#pragma GCC optimize ("Ofast")
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
ll n, f1, f2, f3, c;
vvi a;
void mul(vvi& a, vvi& b, ll M) {
	vvi res(a.size(), vi(a[0].size()));
	for (ll i = 0; i < a.size(); i++)
		for (ll j = 0; j < a.size(); j++)
			for (ll k = 0; k < a.size(); k++) {
				res[i][j] += (a[i][k] * b[k][j]) % M;
				if (res[i][j] >= M)
					res[i][j] -= M;
			}
	a = res;
}
ll bp(ll a, ll p) {
	ll res = 1;
	while (p) {
		if (p & 1)
			res = (res*a)%mod;
		p >>= 1;
		a = (a*a)%mod;
	}
	return res;
}
void bp(vvi& a, ll p, ll M) {
	vvi res = a;
	p--;
	while (p) {
		if (p & 1)
			mul(res, a, M);
		p >>= 1;
		mul(a, a, M);
	}
	a = res;
}
vi fpow() {
	vvi mat = { { 0, 1, 0 }, { 0, 0, 1 }, { 1, 1, 1 } };
	bp(mat, n - 3, mod - 1);
	return mat[2];
}
ll cpow() {
	vvi mat = {
			{ 0, 1, 0, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 1, 1, 1, 2, -6 },
			{ 0, 0, 0, 1, 1 },
			{ 0, 0, 0, 0, 1 },
	};
	bp(mat, n - 3, mod - 1);
	return (4*mat[2][3]+mat[2][4])%(mod-1);
}

int main() {
	doin();
	cin >> n >> f1 >> f2 >> f3 >> c;
	vi a = fpow();
	ll cp = cpow();
	if(cp < 0)
		cp = ((mod-1)+cp)%(mod-1);
	ll ans = bp(f1, a[0]);
	ans = (ans*bp(f2, a[1]))%mod;
	ans = (ans*bp(f3, a[2]))%mod;
	ans = (ans*bp(c, cp))%mod;
	cout << ans;
	return 0;
}