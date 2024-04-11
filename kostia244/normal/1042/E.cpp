#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#define pb push_back
#define __V vector
#define all(x) x.begin(), x.end()
#define oit ostream_iterator
#define mod 998244353ll
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
		getv(v[i], ns...);
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
typedef unsigned long long ull;
typedef long long ll;
typedef float ld;
typedef ll _I;
typedef pair<ll, ll> pi;
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
struct pos {
	ll val;
	int x, y;
	bool operator<(const pos& r) {
		return val < r.val;
	}
};
#define M(x) ((x)%mod)

ll binpow(ll a, ll p) {
	if (p == 1)
		return a;
	if (p & 1)
		return (binpow(a, p - 1) * a) % mod;
	return binpow((a * a) % mod, p >> 1);
}

int n, m, t, r, c;
vector<pos> a;
vi dp, pdp, px, py, px2, py2;
int main() {
	doin();
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> t, a.pb( { t, i + 1, j + 1 });
	cin >> r >> c;
	sort(all(a));
	if (a[0].x == r && a[0].y == c) {
		cout << 0;
		return 0;
	}
	for (auto* i : { &dp, &pdp, &px, &py, &px2, &py2 })
		i->resize(a.size());
	px[0] = 2 * a[0].x;
	py[0] = 2 * a[0].y;
	px2[0] = a[0].x * a[0].x;
	py2[0] = a[0].y * a[0].y;
	int ptr = -1;
	ll xdist, ydist;
	for (int i = 1; i < a.size(); i++) {
		while (a[ptr + 1].val != a[i].val)
			ptr++;
		if (ptr == -1)
			xdist = 0;
		else
			xdist = M(M((ptr+1)*M(a[i].x*a[i].x)) - M(px[ptr] * a[i].x)
					+ px2[ptr]);
		if (ptr == -1)
			ydist = 0;
		else
			ydist = M(M((ptr+1)*M(a[i].y*a[i].y)) - M(py[ptr] * a[i].y)
					+ py2[ptr]);
		dp[i] = M(M((ptr != -1 ? pdp[ptr] : 0) + M(xdist + ydist)) * binpow(ptr+1, mod-2));
		px[i] = M(px[i-1] + 2 * a[i].x);
		py[i] = M(py[i-1] + 2 * a[i].y);
		px2[i] = M(px2[i-1] + a[i].x * a[i].x);
		py2[i] = M(py2[i-1] + a[i].y * a[i].y);
		pdp[i] = M(pdp[i-1] + dp[i]);
		if (a[i].x == r && a[i].y == c) {
			cout << dp[i];
			return 0;
		}
	}

}