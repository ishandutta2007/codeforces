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
typedef long double ld;
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

struct item {
	int v, i;
	bool operator<(const item &rhs) const {
		return v < rhs.v;
	}
};

struct segtree {
	pair<item, item> tree[400100];
	pair<item, item> broken = {{0, 0}, {0, 0}};
	int n;
	void init(int N) {
		n = N;
	}
	pair<item, item> merge(pair<item, item> a, pair<item, item> b) {
		if (a < b)
			swap(a, b);
		a.second = max(a.second, b.first);
		return a;
	}
	void set(int v, int i, int val, int l, int r) {
		if (l == r) {
			tree[v] = {{val, i}, {0, 0}};
			return;
		}
		int mid = (l + r) / 2;
		if(i <= mid)
		set(2*v, i, val, l, mid);
		else
		set(2*v+1, i, val, mid+1, r);
		tree[v] = merge(tree[2*v], tree[2*v+1]);
	}
	void set(int i, int val) {
		set(1, i, val, 1, n);
	}
	pair<item, item> get(int v, int l, int r, int qL, int qR) {
		if(l > qR || r < qL) {
			return broken;
		}
		if(l >= qL && r <= qR) {
			return tree[v];
		}
		int mid = (l + r) / 2;
		return merge(get(2*v, l, mid, qL, qR), get(2*v+1, mid+1, r, qL, qR));
	}
	pair<item, item> get(int l, int r) {
		return get(1, 1, n, l, r);
	}
};
int n, ans = 0;
segtree st;
set<pi> a;
void rec(int l, int r) {
	if(r-l+1 < 2 || !a.insert({l, r}).second)
		return;
	auto it = st.get(l, r);
	if(it.first.v+it.second.v < ans)
		return;
	ans = max(ans, it.first.v^it.second.v);
	rec(l, max(it.first.i, it.second.i)-1);
	rec(min(it.first.i, it.second.i)+1, r);
}

int main() {
	doin();
	cin >> n;
	st.init(n);
	for(int t, i = 1; i<= n; i++)
		cin >> t, st.set(i, t);
	rec(1, n);
	cout << ans;
}