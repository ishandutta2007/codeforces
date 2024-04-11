//#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC push_options
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>
#define pb push_back
#define __V vector
#define all(x) x.begin(), x.end()
#define rall(x) x.begin(), x.end()
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
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
int n, dp[52][52][52][52], sm[52][52];

int getsum(int lx, int ly, int rx, int ry) {
	lx--, ly--;
	return sm[rx][ry] - sm[rx][ly] - sm[lx][ry] + sm[lx][ly];
}

int f(int lx, int ly, int rx, int ry) {
	int& ans = dp[lx][ly][rx][ry];
	if(ans != -1) return ans;
	if(getsum(lx, ly, rx, ry) == 0) {
		ans = 0;
		return 0;
	}
	ans = max(rx-lx+1, ry-ly+1);
	for(int i = lx; i < rx; i++) {
		ans = min(ans, f(lx, ly, i, ry) + f(i+1, ly, rx, ry));
	}
	for(int i = ly; i < ry; i++) {
		ans = min(ans, f(lx, ly, rx, i) + f(lx, i+1, rx, ry));
	}
	return ans;
}

int main() {
	doin();
	memset(dp, -1, sizeof dp);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char t;
			cin >> t;
			sm[i][j] = (t == '#');
			sm[i][j] += sm[i-1][j] + sm[i][j-1] - sm[i-1][j-1];
		}
	}
	cout << f(1, 1, n, n);
	return 0;
}