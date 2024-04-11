//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")
//#pragma GCC target ("avx2,tune=native")
#include<bits/stdc++.h>
// #include<ext/pb_ds/tree_policy.hpp>
// #include<ext/pb_ds/assoc_container.hpp>
#define pb push_back
#define __V vector
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
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
//SQRT-heuristic divide items into groups: >sqrt and <=sqrt and do something according to group(eg. trie for one, z-func for other) - 1202E
uniform_real_distribution<double> double_dist(0, 1);
//WHEN DOING MODULAR SUBTRACTION ALWAYS **ALWAYS** ADD MOD
//don't use AVX at AtCoder
//Trie: MAXDEPTH!=MAXSIZE
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
	doin();
	int n, r;
	vpi pos, neg;
	cin >> n >> r;
	for (int a, b, i = 0; i < n; i++) {
		cin >> a >> b;
		if (b >= 0)
			pos.pb( { a, b });
		else
			neg.pb( { max(a, -b), b });
	}
	ll P = 0;
	sort(all(pos));
	for (auto i : pos) {
		if (i.first > r) {
			break;
		}
		P++;
		r += i.second;
	}
	mii dp[2];
	dp[0][r] = 0;
	ll M = 0;
	sort(all(neg), [](const pi& a, const pi& b) {
		return a.first+a.second > b.first+b.second;
	});
	for (int i = 0; i < neg.size(); i++) {
		int c = i & 1, n;
		n = c ^ 1;
		dp[n] = dp[c];
//		cout << neg[i].first << " " << neg[i].second <<"\n";
		for (auto k : dp[c])
			if (k.first >= neg[i].first && k.first + neg[i].second >= 0) {
//				cout << k.first << " -> " << k.first+neg[i].second << " ( " << k.second + 1 << " )\n";
				maxq(dp[n][k.first + neg[i].second], k.second + 1);
//				cout << k.first << " -> " << k.first+neg[i].second << " ( " << dp[n][k.first + neg[i].second] << " )/\n";
				maxq(M, dp[n][k.first + neg[i].second]);
			}
	}
	cout << M+P;
}