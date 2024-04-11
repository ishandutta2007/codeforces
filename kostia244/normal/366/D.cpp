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
struct dsu {
	vi p, r;
	dsu(int n) {
		p.resize(n+1);
		r.assign(n+1, 1);
		for(int i = 0; i <= n; i++) p[i] = i;
	}
	int par(int i) {
		return p[i] == i ? i : p[i] = par(p[i]);
	}
	bool same(int i, int j) {
		return par(i) == par(j);
	}
	void unite(int i, int j) {
		i = par(i);
		j = par(j);
		if(i == j) return;
		if(r[i] < r[j]) swap(i, j);
		p[j] = i;
		r[i] += (r[i] == r[j]);
	}
};
struct edge {
	int from, to, l, r;
	void get() {
		cin >> from >> to >> l >> r;
	}
};
int n, m;
vector<edge> g;
vi coords;

bool can(int l, int r) {
	dsu d(n);
	for(auto i : g) {
		if(coords[l] >= i.l && coords[r] <= i.r ) {
			d.unite(i.from, i.to);
		}
	}
	return d.same(1, n);
}

int main() {
	doin();
	cin >> n >> m;
	g.resize(m);
	for(auto& i : g) {
		i.get();
		coords.pb(i.l);
		coords.pb(i.r);
	}
	set<int> tmp(all(coords));
	coords = vi(all(tmp));
	coords.pb(1000001);
	int ans = 0;
	for(int l = 0; l < coords.size(); l++) {
		int low = l-1, h = coords.size()-1, mid;
		while(low<h) {
			mid = low + (h-low+1)/2;
			if(can(l, mid))
				low = mid;
			else
				h = mid-1;
		}
		if(h < l)
			continue;
		ans = max(ans, coords[h]-coords[l]+1);
	}
	if(ans)
	cout << ans;
	else
		cout << "Nice work, Dima!";
}