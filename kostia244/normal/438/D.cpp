#pragma GCC target ("avx2")
#pragma GCC target ("sse2")
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
template<typename T, typename V>
void setmin(T& a, V b) {
	a > b ? a = b : 0;
}
template<typename T, typename V>
void setmax(T& a, V b) {
	a < b ? a = b : 0;
}
vi a;
struct node {
	ll min_val, max_val, sum;
	vi mods;
	node(ll val = 0) {
		min_val = max_val = sum = val;
	}
};
node tree[501400];
struct segtree {
	node merge(node a, node b) {
		a.min_val = min(a.min_val, b.min_val);
		a.max_val = max(a.max_val, b.max_val);
		a.sum += b.sum;
		return a;
	}
	void push(int v, int l, int r) {
		for (auto k : tree[v].mods) {
			tree[v].sum = (r - l + 1) * 1ll * (tree[v].max_val % k);
			tree[v].min_val %= k;
			tree[v].max_val %= k;
		}
		if (l != r) {
			int mid = (l + r) / 2;
			tree[2 * v].mods.insert(tree[2 * v].mods.end(), all(tree[v].mods));
			if (tree[2 * v].mods.size() > 10)
				push(2 * v, l, mid);
			tree[2 * v + 1].mods.insert(tree[2 * v + 1].mods.end(),
					all(tree[v].mods));
			if (tree[2 * v + 1].mods.size() > 10)
				push(2 * v + 1, mid + 1, r);
		}
		tree[v].mods.clear();
	}
	void build(int v, int l, int r) {
		if (l == r) {
			tree[v] = node(a[l]);
			return;
		}
		int mid = (l + r) / 2;
		build(2 * v, l, mid);
		build(2 * v + 1, mid + 1, r);
		push(2*v, l, mid);
		push(2*v+1, mid+1, r);
		tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
	}
	ll getsum(int v, int l, int r, int qL, int qR) {
		push(v, l, r);
		if (l > qR || r < qL)
			return 0;
		if (l >= qL && r <= qR) {
			return tree[v].sum;
		}
		int mid = (l + r) / 2;
		return getsum(2 * v, l, mid, qL, qR)
				+ getsum(2 * v + 1, mid + 1, r, qL, qR);
	}
	void md(int v, int l, int r, int qL, int qR, int m) {
		push(v, l, r);
		if (l > qR || r < qL || tree[v].max_val < m)
			return;
//		cout << l << " " << r << " " << tree[v].min_val << " " << tree[v].max_val << " " << tree[v].sum << "\n";
		if (l >= qL && r <= qR && tree[v].min_val == tree[v].max_val) {
			tree[v].mods.pb(m);
			push(v, l, r);
			return;
		}
		int mid = (l + r) / 2;
		md(2 * v, l, mid, qL, qR, m);
		md(2 * v + 1, mid + 1, r, qL, qR, m);
		push(2*v, l, mid);
		push(2*v+1, mid+1, r);
		tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
	}
	void ass(int v, int l, int r, int i, int val) {
		push(v, l, r);
		if (l > i || r < i)
			return;
		if (l == r) {
			tree[v] = node(val);
			return;
		}
		int mid = (l + r) / 2;
		if (i <= mid)
			ass(2 * v, l, mid, i, val);
		else
			ass(2 * v + 1, mid + 1, r, i, val);
		push(2*v, l, mid);
		push(2*v+1, mid+1, r);
		tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
	}
};
int main() {
	doin();
	int n, q;
	cin >> n >> q;
	getv1(a, n);
	segtree s;
	for(int i = 0; i < 500000; i++) tree[i] = node(0);
	s.build(1, 1, n);
	int t, x, l, r;
//	for(int i = 1; i <= n; i++)
//		cout << s.getsum(1, 1, n, i, i) << " ";
//	cout << "\n";
	while (q--) {
		cin >> t;
		if (t == 1) {
			cin >> l >> r;
			cout << s.getsum(1, 1, n, l, r) << "\n";
		} else if (t == 2) {
			cin >> l >> r >> x;
			s.md(1, 1, n, l, r, x);
		} else {
			cin >> l >> x;
			s.ass(1, 1, n, l, x);
		}
//		for(int i = 1; i <= n; i++)
//			cout << s.getsum(1, 1, n, i, i) << " == " << i << "\n";
//		cout << "\n";
	}
}