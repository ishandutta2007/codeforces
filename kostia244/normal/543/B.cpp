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
int n, m, ans = INT_MAX, dist[3030][3030];
vvi g;
bitset<3030> vis;
void bfs(int s) {
	vis = 0;
	for (int i = 1; i <= n; i++)
		dist[s][i] = INT_MAX;
	dist[s][s] = 0;
	queue<int> q;
	q.push(s);
	vis.set(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto i : g[u]) {
			if (vis.test(i))
				continue;
			dist[s][i] = dist[s][u] + 1;
			vis.set(i);
			q.push(i);
		}
	}
}
int main() {
	doin();
	cin >> n >> m;
	g.resize(n + 1);
	for (int f, t, i = 0; i < m; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	for (int i = 1; i <= n; i++)
		bfs(i);
	int s1, s2, t1, t2, l1, l2;
	cin >> s1 >> t1 >> l1 >> s2 >> t2 >> l2;
	if (dist[s1][t1] > l1)
		return cout << -1, 0;
	if (dist[s2][t2] > l2)
		return cout << -1, 0;
	ans = m - dist[s1][t1] - dist[s2][t2];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if(dist[i][s1]+dist[i][j]+dist[j][t1] > l1) {
				continue;
			}
			if(dist[i][s2]+dist[i][j]+dist[j][t2] <= l2) {
				maxq(ans, m - (dist[i][s1]+dist[i][s2]+dist[i][j]+dist[j][t1]+dist[j][t2]));
			}
			swap(s2, t2);
			if(dist[i][s2]+dist[i][j]+dist[j][t2] <= l2) {
				maxq(ans, m - (dist[i][s1]+dist[i][s2]+dist[i][j]+dist[j][t1]+dist[j][t2]));
			}
			swap(s2, t2);
		}
	maxq(ans, 0);
	cout << ans;
	return 0;
}