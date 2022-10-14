#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/assoc_container.hpp>
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
struct dsu {
	vi r, p, id;
	void init(int n) {
		r.assign(n + 1, 1);
		p.resize(n + 1);
		id.resize(n + 1);
		for (int i = 1; i <= n; i++)
			p[i] = id[i] = i;
	}
	int par(int i) {
		return i == p[i] ? i : p[i] = par(p[i]);
	}
	void unite(int i, int j) {
		i = par(i), j = par(j);
		if (i == j)
			return;
		if (r[i] < r[j])
			swap(i, j);
		p[j] = i;
		r[i] += r[i] == r[j];
	}
	bool sameset(int i, int j) {
		return par(i) == par(j);
	}
	void setid(int i, int x) {
		i = par(i);
		id[i] = x;
	}
	int getid(int i) {
		i = par(i);
		return id[i];
	}
};
struct dsumod {
	vi p;
	vpi bst;
	int push(pi fs) {
		bst.pb( fs );
		p.pb(p.size());
		return p.size() - 1;
	}
	int par(int i) {
		return p[i] == i ? i : p[i] = par(p[i]);
	}
	void unite(int i, int j) {
		i = par(i), j = par(j);
		if (i == j)
			return;
		if (bst[i] < bst[j])
			swap(i, j);
		if (bst[i].first == bst[j].first) {
			bst[i].second = bst[i].first;
			bst[i].first++;
		} else
			maxq(bst[i].second, 1 + bst[j].first);
		p[j] = i;
	}
	int get(int i) {
		i = par(i);
		return bst[i].first + bst[i].second;
	}
};
int n, q, m, di;
dsu d;
dsumod ans;
vpi dp;
vvi g;
bitset<300300> vis;
void dfs(int v = 1, int p = 1) {
	d.unite(v, p);
	vis.set(v);
	dp[v] = {0, 0};
	for (auto i : g[v])
		if (i != p) {
			dfs(i, v);
			if (dp[v].first < dp[i].first + 1) {
				dp[v].second = dp[v].first;
				dp[v].first = dp[i].first + 1;
			} else if (dp[v].second < dp[i].first + 1) {
				dp[v].second = dp[i].first + 1;
			}
		}
	maxq(di, dp[v].first+dp[v].second);
}
int main() {
	doin();
	cin >> n >> m >> q;
	dp.resize(n + 1);
	g.resize(n + 1);
	d.init(n);
	for (int f, t, i = 0; i < m; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	for (int i = 1; i <= n; i++)
		if (!vis.test(i)) {
			di = 0;
			dfs(i, i);
			d.setid(i, ans.push({di - (di>>1), di>>1}));
		}
	int t, x, y;
	while(q--) {
		cin >> t >> x;
		if(t == 1)
			cout << ans.get(d.getid(x)) << "\n";
		else {
			cin >> y;
			ans.unite(d.getid(x), d.getid(y));
		}
	}
	return 0;
}