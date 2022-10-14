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
int n, k, k_idx[2020][2020];
vvc mat;
vpi p[2];
int main() {
//	doin();
	cin >> n >> k;
	minq(k, 2 * n - 1);
	getv1(mat, n, n);
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++) {
			k_idx[i][j] = 1e9;
		}
	int MX;
	MX = k_idx[1][1] = mat[1][1] != 'a';
	for (int i = 1; i <= n; i++)
		for (int j = 1 + (i == 1); j <= n; j++) {
			k_idx[i][j] = min(k_idx[i - 1][j], k_idx[i][j - 1])
					+ (mat[i][j] != 'a');
			maxq(MX, k_idx[i][j]);
			if (k_idx[i][j] == k) {
				if (p[0].empty()
						|| p[0].back().first + p[0].back().second == i + j)
					p[0].pb( { i, j });
				else if (!p[0].empty()
						&& p[0].back().first + p[0].back().second < i + j)
					p[0].clear(), p[0].pb( { i, j });
			}
		}
	bool f = false;
	if(k_idx[n][n] <= k) {
		for(int i = 1; i <2*n;i++) cout <<'a';
		return 0;
	}
	minq(MX, k);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (k_idx[i][j] == MX) {
				if (p[0].empty()
						|| p[0].back().first + p[0].back().second == i + j)
					p[0].pb( { i, j });
				else if (!p[0].empty()
						&& p[0].back().first + p[0].back().second < i + j)
					p[0].clear(), p[0].pb( { i, j });
			}
		}
//	if(k == 702)
//		cout << p[0][0].first+p[0][0].second << "\n";

	if(p[0].empty()) {
		p[0].pb({1, 1}), f = 1;
	}
	string ans;
	if(!f) {
	for (int i = 1; i < p[0][0].first + p[0][0].second; i++)
		ans += 'a';
	} else {
		ans += mat[1][1];
	}
//	if(n == 2000 && k == 0)
//		cout << f << p[0][0].first  << " " << p[0][0].second << "\n";
	int a[2020][2020];
	memset(a, 0, sizeof a);
//	return 0;
	for (int i = 0;; i++) {
		if(p[i&1][0] == pi(n, n)) break;
		if(i > 2*n)
			exit(55);
		char minch = 'z' + 1;
//		cout << p[0].size();
		for (auto j : p[i & 1]) {
			if (j.first < n)
				minq(minch, mat[j.first + 1][j.second]);
			if (j.second < n)
				minq(minch, mat[j.first][j.second + 1]);
		}
		for (auto j : p[i & 1]) {
			if (j.first < n && minch == mat[j.first + 1][j.second] && a[j.first + 1][j.second]++ == 0)
				p[(i & 1) ^ 1].pb( { j.first + 1, j.second });
			if (j.second < n && minch == mat[j.first][j.second + 1] && a[j.first][j.second+1]++ == 0)
				p[(i & 1) ^ 1].pb( { j.first, j.second + 1 });
		}
		p[i & 1].clear();
		ans += minch;
	}
//	assert(ans.size() == 2*n-1);
	cout << ans;
	return 0;
}