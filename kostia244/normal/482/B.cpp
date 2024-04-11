//#pragma GCC target ("avx2")
#pragma GCC optimize ("Ofast")
#pragma GCC push_options
#pragma GCC optimize ("unroll-loops")
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
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
struct event {
	bool E;
	int v;
	event(int _v, bool _E) {
		this->v = _v;
		this->E = _E;
	}
};

vector<pair<pi, int>> a;
vector<event> e[100100];
int main() {
	doin();
	int n, m;
	cin >> n >> m;
	a.resize(m);
	for (auto& i : a) {
		cin >> i.first.first >> i.first.second >> i.second;
		e[i.first.first].eb(i.second, 0);
		e[i.first.second].eb(i.second, 1);
	}
	sort(all(a));
	int bitcnt[32], res[100100], sp[17][100100], lp[100100], val = 0;
	memset(bitcnt, 0, sizeof bitcnt);
	int i = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < e[i].size(); j++) {
			for (int l = 0; l < 30; l++)
				if (!e[i][j].E && ((e[i][j].v >> l) & 1)) {
					if (++bitcnt[l] == 1)
						val ^= 1 << l;
				}
		}
		res[i] = val;
		for (int j = 0; j < e[i].size(); j++) {
			for (int l = 0; l < 30; l++)
				if (e[i][j].E && ((e[i][j].v >> l) & 1)) {
					if (--bitcnt[l] == 0)
						val ^= 1 << l;
				}
		}
	}
	for (int i = 0; i < 17; i++)
		for (int j = 1; j <= n; j++) {
			if (i == 0) {
				sp[i][j] = res[j];
			} else {
				sp[i][j] = sp[i - 1][j]
						& (j + (1 << (i - 1)) <= n ?
								sp[i - 1][j + (1 << (i - 1))] : (1 << 30) - 1);
			}
		}
	lp[0] = -1;
	for (int i = 1; i <= n; i++) {
		lp[i] = lp[i - 1] + ((i & (i - 1)) == 0);
	}
	for (auto& i : a) {
		int l = i.first.second - i.first.first + 1;
		l = lp[l];
		int a = sp[l][i.first.first] & sp[l][i.first.second - (1 << l) + 1];
		if(a != i.second) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES\n";
	for (int i = 1; i <= n; i++)
		cout << res[i] << " ";
}