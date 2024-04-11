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
//f-e+v=2
uniform_real_distribution<double> double_dist(0, 1);
uniform_int_distribution<int> dist(31, 55);
//WHEN DOING MODULAR SUBTRACTION ALWAYS **ALWAYS** ADD MOD
//don't use AVX at AtCoder(=RE)
//Trie: MAXDEPTH!=MAXSIZE
//suspiciously big numbers? use python, seriosly you don't wanna waste your time if it overflows
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//SQRT IS PROBABLY THE ANSWER
//SET TO ZERO
const int maxn = 2e5 + 55, maxlg = 18;
struct sparseor {
	int dp[maxn][maxlg], lg_[maxn];
	void init(vi& a) {
		memset(dp, 0, sizeof dp);
		lg_[0] = -1;
		for (int i = 1; i <= a.size(); i++) {
			lg_[i] = lg_[i - 1] + ((i & (i - 1)) == 0);
		}
		for(int i = 0 ; i < a.size(); i++) dp[i][0] = a[i];
		for(int i = 1; (1<<i) <= a.size(); i++)
			for(int j = 0; j < a.size(); j++) {
				dp[j][i] = dp[j][i-1]|(j+(1<<(i-1)) < a.size() ? dp[j+(1<<(i-1))][i-1]:0);
			}
	}
	int query(int i, int j) {
		int k = lg_[j-i+1];
//		cerr << "(" << i << " " << j << " " << (j-i+1) << " " << lg_[j-i+1] << " _ " << (dp[i][k]|dp[j-(1<<k)+1][k]) << ")\n";
		return dp[i][k]|dp[j-(1<<k)+1][k];
	}
};
struct sparsemx {
	pair<int, int> dp[maxn][maxlg];
	int lg_[maxn];
	void init(vi& a) {
		memset(dp, 0, sizeof dp);
		lg_[0] = -1;
		for (int i = 1; i <= a.size(); i++) {
			lg_[i] = lg_[i - 1] + ((i & (i - 1)) == 0);
		}
		for(int i = 0 ; i < a.size(); i++) dp[i][0] = {a[i], i};
		for(int i = 1; (1<<i) <= a.size(); i++)
			for(int j = 0; j < a.size(); j++) {
				dp[j][i] = max(dp[j][i-1], (j+(1<<(i-1)) < a.size() ? dp[j+(1<<(i-1))][i-1]:pair<int, int>(0, 0)));
			}
	}
	pi query(int i, int j) {
		int k = lg_[j-i+1];
		return max(dp[i][k],dp[j-(1<<k)+1][k]);
	}
};

int n;
ll ans = 0;
vi a;
sparseor v;
sparsemx m;

void rec(int s = 0, int e = n-1) {
	if(s >= e)
		return;
	int p = m.query(s, e).second;
//	cout << s << " " << e << "=========\n";
	int t;
	t = p;
	if((v.query(p, e)|a[p]) != a[p]) {
		for(int i = 1<<17; i; i>>=1) {
			if(t+i < e && (v.query(p, t+i)|a[p]) == a[p])
				t += i;
		}
		t++;
		ans += (p+1-s)*1ll*(e+1-t);
	} else
		t = -1;
	int T = p;
	if ((v.query(s, p) | a[p]) != a[p]) {
		for (int i = 1 << 17; i; i >>= 1) {
			if (T - i >= s && (v.query(T - i, p) | a[p]) == a[p])
				T -= i;//, cout << T << " " << p << " " << v.query(T, p) << "\n";
		}
		ans += (e+1 - p) * 1ll * (T-s);
	} else
		T = -1;
//	T--;
	if(T != -1 && t != -1) {
		ans -= (e+1 - t) * 1ll * (T-s);
	}
//	cout << T << " " << p << " " << t << " " << ans << "\n";
	rec(s, p-1);
	rec(p+1, e);
}

int main() {
	doin();
	cin >> n;
	getv(a, n);
	v.init(a);
	m.init(a);
	rec();
	cout << ans;
	return 0;
}