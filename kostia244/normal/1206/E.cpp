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
int n, mat[60][60];

int query(int x, int y, int x1, int y1) {
	cout << "? " << x << " " << y << " " << x1 << " " << y1 << "\n";
	cout.flush();
	int t;
	cin >> t;
	return t;
}

int can(int x, int y) {
	return x+y != 2*n && x > 0 && y > 0 && x <= n && y <= n && mat[x][y] == -1;
}

int canb(int x, int y) {
	return x > 0 && y > 0 && x <= n && y <= n;
}

void dfs(int x, int y, int v) {
	mat[x][y] = v;
	if (can(x, y - 2))
		dfs(x, y - 2, v ^ 1 ^ query(x, y - 2, x, y));
	if (can(x, y + 2))
		dfs(x, y + 2, v ^ 1 ^ query(x, y, x, y + 2));
	if (can(x + 1, y + 1))
		dfs(x + 1, y + 1, v ^ 1 ^ query(x, y, x + 1, y + 1));
	if (can(x + 1, y + 1))
		dfs(x + 1, y + 1, v ^ 1 ^ query(x, y, x + 1, y + 1));
}

int main() {
	doin();
	memset(mat, -1, sizeof mat);
	cin >> n;
	dfs(1, 1, 1);
	dfs(n, n, 0);
	dfs(1, 2, 1);
	int x, ti, tj;
	bool fnd = false;
	int msk = 0;
	for (int i = 1; !fnd && i <= n; i++)
		for (int j = 1; !fnd && j <= n; j++) {
			for(int p = 0; !fnd && p < 1<<3; p++) {
				x = mat[i][j], ti = i, tj = j;
				for(int k = 0; k < 3; k++) {
					if((p>>k)&1)
						ti++;
					else
						tj++;
					if(!canb(ti, tj))
						break;
					x^=mat[ti][tj];
				}
//				cout << i << " " << j << " " << ti << " " << tj << " " << (ti > 0 && tj > 0) << (ti <= n && tj <= n) << "\n";
				if(!canb(ti, tj))
					continue;
//				cout << i << " " << j << " " << ti << " " << tj << " " << x << "/\n";
				if(x == 0) {
					x = query(i, j, ti, tj);//1=>eq, 0=>!eq
					msk=mat[i][j]^mat[ti][tj]^x^1;
					fnd = true;
				}
			}
		}

	cout << "!\n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if((i+j)&1)
				mat[i][j]^=msk;
			cout << mat[i][j];
		}
		cout << "\n";
	}
	return 0;
}