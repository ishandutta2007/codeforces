//#pragma GCC optimize ("O1")
//#pragma GCC target ("sse4")
//#pragma comment(linker, "/STACK:16777216")
//#pragma GCC target ("avx2,tune=native")
#pragma GCC optimize ("trapv")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
#define pb push_back
#define __V vector
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define oit ostream_iterator
#define mod 998244353ll
#define print(x) for(auto i : (x)) cout << i << " ";cout << "\n";
#define printd(x) for(auto i : (x)) cout << i << " ";cout << #x << "\n";
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
//SET TO ZERO
typedef tree<int, null_type, greater<int>, rb_tree_tag,
		tree_order_statistics_node_update> ordered_set; // order_of_key, find_by_order
using node = pair<pi, int>;
node def = {{0, -1}, 0};
struct seg {
	int n;
	vector<node> t;
	void init(int N) {
		n = N;
		t.assign(2*n+55, def);
	}
	void set(int i, node p) {
		for(t[i+=n] = p; i>>=1;)
			t[i] = min(t[i<<1], t[i<<1|1]);
	}
	node get(int l, int r) {
		node rl, rr;
		rl = rr = def;

		for(l+=n, r+=n+1; l < r; l>>=1, r>>=1) {
			if(l&1) rl = min(rl, t[l++]);
			if(r&1) rr = min(t[--r], rr);
		}

		return min(rl, rr);
	}
};

struct Q {
	int l, r, i;
	void get(int _) {
		cin >> l >> r, l--, r--;
		i = _;
	}
};

int n, q;
vi a, ans, pr;
vpi qs[500500];


int main() {
	doin();
	cin >> n;
	getv(a, n);
	cin >> q;
	for(int l, r, i = 0; i < q; i++) {
		cin >> l >> r, l--, r--;
		qs[r].pb({l, i});
	}
	ans.resize(q);
	pr.resize(1<<19, -1);
	seg st;
	st.init(n);
	for(int i = 0; i < n; i++) {
		if(pr[a[i]] != -1)
			st.set(pr[a[i]], def);
		st.set(i, {{-1, pr[a[i]]}, i});
		pr[a[i]] = i;
		for(auto j : qs[i]) {
			int idx = j.second;
			int l = j.first;
			auto t = st.get(l, i);
			if(t == def || t.first.second >= l)
				ans[idx] = 0;
			else
				ans[idx] = a[t.second];
		}
	}
	print(ans);
}