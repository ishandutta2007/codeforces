#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#define pb push_back
#define __V vector
#define all(x) x.begin(), x.end()
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
template<int N>
struct segtree {
	struct node {
		int sum, lazy;
		node(int s = 0) {
			sum = s;
			lazy = 0;
		}
	};
	node tree[4 * N];

	void push(int v, int l, int r) {
		if (!tree[v].lazy)
			return;
		tree[v].sum += (r - l + 1) * tree[v].lazy;
		if (l != r) {
			tree[2 * v].lazy += tree[v].lazy;
			tree[2 * v + 1].lazy += tree[v].lazy;
		}
		tree[v].lazy = 0;
	}
	void add(int v, int qL, int qR, int l, int r) {
		push(v, l, r);
		if (qR < l || qL > r)
			return;

		if (l >= qL && r <= qR) {
			tree[v].lazy++;
			push(v, l, r);
			return;
		}

		int mid = (l + r) >> 1;
		add(2 * v, qL, qR, l, mid);
		add(2 * v + 1, qL, qR, mid + 1, r);

		tree[v].lazy = 0;
		tree[v].sum = tree[2 * v].sum + tree[2 * v + 1].sum;
	}

	void add(int l, int r) {
		add(1, l, r, 1, N);
	}

	int query(int i, int v, int l, int r) {
		push(v, l, r);
		if (l == r) {
			return tree[v].sum;
		}
		int mid = (l + r) >> 1;
		if (i <= mid)
			return query(i, 2 * v, l, mid);
		return query(i, 2 * v + 1, mid + 1, r);
	}

	int get(int i) {
		return query(i, 1, 1, N);
	}
};

struct frac {
	int p, q;
	frac(int pp, int qq) {
		p = pp;
		q = qq;
		pp = abs(__gcd(p, q));
		p /= pp;
		q /= pp;
	}
	bool operator<(const frac& rhs) const {
		return p < rhs.p || (p == rhs.p && q < rhs.q);
	}
};
int n, q, ans[300100];
map<frac, int> a;
segtree<300100> tree;
vector<vector<frac>> poly;
vvpi qs;
void get(int i) {
	int k;
	vpi vert;
	cin >> k;
	getv(vert, k);
	vert.pb(vert.front());
	for(int j = 1; j < vert.size(); j++) {
		poly[i].pb(frac(vert[j].first-vert[j-1].first, vert[j].second-vert[j-1].second));
	}
}
void add(int i) {
	for(auto p : poly[i]) {
		tree.add(a[p], i);
		a[p] = i+1;
	}
}

int main() {
	doin();
	cin >> n;
	poly.resize(n+1);
	for(int i = 1; i <= n;i++) {
		get(i);
	}
	cin >> q;
	qs.resize(n+1);
	int l, r;
	for(int i = 0; i < q; i++){
		cin >> l >> r;
		qs[r].pb({l, i});
	}
	for(int i = 1; i <= n; i++) {
		add(i);
		for(auto q : qs[i]) {
			ans[q.second] = tree.get(q.first);
		}
	}
	for(int i = 0; i < q; i++)
		cout << ans[i] << "\n";
	return 0;
}