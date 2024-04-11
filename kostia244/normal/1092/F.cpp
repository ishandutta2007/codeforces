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
int n;
ll ans = 0;
vvi g;
vi a;

struct node {
	ll rsum, sum, lazyk;
	node() {
		rsum = sum = lazyk = 0;
	}
};
node tree[800100];
struct segtree {
	int n;
	void build(int v, int l, int r) {
		if(l == r) {
			tree[v].sum = tree[v].rsum = a[l];
			return;
		}
		int mid = (l + r) / 2;
		build(2*v, l, mid);
		build(2*v+1, mid+1, r);
		tree[v] = merge(tree[2*v], tree[2*v+1]);
	}
	void init(int N) {
		n = N;
		build(1, 1, n);
	}
	node merge(node a, node b) {
		a.sum += b.sum;
		a.rsum += b.rsum;
		a.lazyk = 0;
		return a;
	}
	void push(int v, int l, int r) {
		if (!tree[v].lazyk)
			return;
		tree[v].sum += tree[v].rsum * tree[v].lazyk;
		if (l != r) {
			tree[2 * v].lazyk += tree[v].lazyk;
			tree[2 * v + 1].lazyk += tree[v].lazyk;
		}
		tree[v].lazyk = 0;
	}
	void add(int v, int l, int r, int qL, int qR, ll k) {
		push(v, l, r);
		if (l > qR || r < qL)
			return;
		if (l >= qL && r <= qR) {
			tree[v].lazyk = k;
			push(v, l, r);
			return;
		}
		int mid = (l + r) / 2;
		add(2 * v, l, mid, qL, qR, k);
		add(2 * v + 1, mid + 1, r, qL, qR, k);
		tree[v] = merge(tree[2 * v], tree[2 * v + 1]);
	}
	void add(int l, int r, ll k) {
		add(1, 1, n, l, r, k);
	}
	ll get(int v, int l, int r, int qL, int qR) {
		push(v, l, r);
		if (l > qR || r < qL)
			return 0;
		if (l >= qL && r <= qR) {
			return tree[v].sum;
		}
		int mid = (l + r) / 2;
		return get(2 * v, l, mid, qL, qR) + get(2 * v + 1, mid + 1, r, qL, qR);
	}
	ll get(int l, int r) {
		return get(1, 1, n, l, r);
	}
};
segtree st;
vi ein, eout;
int etimer = 1;
void edfs(int v = 1, int p = 1) {
	ein[v] = etimer++;
	for(auto i : g[v])
		if(i != p)
			edfs(i, v);
	eout[v] = etimer-1;
}

void predfs(int v = 1, int p = 1, int h = 0) {
	st.add(ein[v], ein[v], h-1);
	for(auto i : g[v])
		if(i != p)
			predfs(i, v, h+1);
}
void dfs(int v = 1, int p = 1, int h = 0) {
	ans = max(ans, st.get(1, n));
	for(auto i : g[v])
		if(i != p) {
			st.add(1, n, 1);
			st.add(ein[i], eout[i], -2);
			dfs(i, v);
			st.add(1, n, -1);
			st.add(ein[i], eout[i], 2);
		}
}

int main() {
	doin();
	cin >> n;
	vi ta;
	getv1(ta, n);
	g.resize(n + 1);
	for (int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	ein.resize(n+1);
	eout.resize(n+1);
	edfs();
	a.resize(n+1);
	for(int i = 1; i <= n; i++) a[ein[i]] = ta[i];
	st.init(n);
	predfs();
	dfs();
	cout << ans;
}