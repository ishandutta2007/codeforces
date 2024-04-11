#pragma GCC optimize ("Ofast")
#pragma GCC push_options
#pragma GCC optimize ("unroll-loops")
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
typedef int _I;
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
int n;
map<string, int> used;

int id(char c) {
	if (c >= 'a' && c <= 'z')
		return c - 'a';
	if (c >= 'A' && c <= 'Z')
		return 26 + c - 'A';
	return 52 + c - '0';
}

inline int sym(int res[4]) {
	int a = 24;
	if (res[0] == res[1] && res[2] == res[1] && res[3] == res[2])
		a /= 24;
	else if (res[0] == res[1] && res[2] == res[1])
		a /= 6;
	else if (res[0] == res[1])
		a /= 2;
	if (res[0] != res[1]) {
		if (res[1] == res[2] && res[2] == res[3])
			a /= 6;
		else if (res[1] == res[2])
			a /= 2;
	}
	if (res[2] != res[1]) {
		if (res[2] == res[3])
			a /= 2;
	}
	return a;
}

int main() {
//	ll dp3[8][32][32][32];
	vector<vector<vector<vector<ll>>>> dp3(8,
			vector<vector<vector<ll>>>(62,
					vector<vector<ll>>(62, vector<ll>(62))));
	ll cnt[8][70][70], ans = 0;
	memset(cnt, 0, sizeof cnt);
	doin();
	cin >> n;
	string s;
	while (n--) {
		cin >> s;
		if (!used[s]) {
			used[s] = 1;
			cnt[s.size() - 3][id(s[0])][id(s.back())]++;
		}
		reverse(all(s));
		if (!used[s]) {
			used[s] = 1;
			cnt[s.size() - 3][id(s[0])][id(s.back())]++;
		}
	}
	int res[4];
	memset(res, 0, sizeof res);
	while (true) {
		bool inc = true;
		for (int i = 0; inc && i < 3; i++) {
			if (++res[i] == 62)
				res[i] = 0;
			else
				inc = 0;
		}
		for (int i = 1; i >= 0; i--)
			res[i] = max(res[i], res[i + 1]);
		for (res[3] = 0; res[3] < 62; res[3]++)
			for (int l = 0; l < 8; l++) {
				ll t = cnt[l][res[3]][res[1]];
				t *= cnt[l][res[3]][res[2]];
				if (t >= mod)
					t %= mod;
				t *= cnt[l][res[0]][res[3]];
				if (t >= mod)
					t %= mod;
				dp3[l][res[0]][res[1]][res[2]] += t;
				if (dp3[l][res[0]][res[1]][res[2]])
					dp3[l][res[0]][res[1]][res[2]] %= mod;
			}
		if (inc)
			break;
	}
	memset(res, 0, sizeof res);
	int F = 0;
	while (true) {
		bool inc = true;
		for (int i = 0; inc && i < 4; i++) {
			if (++res[i] == 62)
				res[i] = 0;
			else
				inc = 0;
		}
		for (int i = 2; i >= 0; i--)
			res[i] = max(res[i], res[i + 1]);
		for (int l = 0; l < 8; l++) {
			ll t = dp3[l][res[0]][res[1]][res[2]];
			t *= dp3[l][res[1]][res[2]][res[3]];
			if (t >= mod)
				t %= mod;

//			cout << res[0] << " " << res[1] << " " << res[3] << " " << dp3[l][res[0]][res[1]][res[3]] << "\n";
			ll t2 = dp3[l][res[0]][res[1]][res[3]];
			t2 *= dp3[l][res[0]][res[2]][res[3]];
			if (t2 >= mod)
				t2 %= mod;
			t *= t2;
			if (t >= mod)
				t %= mod;
			if (t)
				t *= sym(res);
			if (t >= mod)
				t %= mod;
			ans += t;
			if (ans >= mod)
				ans %= mod;
		}
		if (inc)
			break;
	}
	cout << ans;
	return 0;
}