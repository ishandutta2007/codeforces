#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first.first
#define yy first.second
#define __V vector
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define oit ostream_iterator
#define mod 1000000007ll
using namespace __gnu_pbds;
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
typedef unsigned long long ull;
typedef long long ll;
typedef double ld;
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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct dsu {
	vi sz, p;
	dsu(int n) {
		sz.resize(n + 1, 1);
		p.resize(n + 1);
		for (int i = 1; i <= n; i++)
			p[i] = i;
	}
	int par(int i) {
		if (p[i] == i)
			return i;
		return p[i] = par(p[i]);
	}
	bool unite(int i, int j) {
		int x = par(i), y = par(j);
		if (x == y)
			return false;
		if (sz[x] > sz[y])
			swap(x, y);
		p[x] = y;
		sz[y] += sz[x];
		return true;
	}
};
int n, m, f, t, c;
__V<pair<int, pi>> edges;
set<pi> FUCKTHISPROBLEM;
vpi edges2, gp;
__V<__V<pair<int, pi>>> g;
vi num, low;
set<pi> nall, all;

void efs(int v, pair<int, pi> p) {
	num[v] = low[v] = ++t;
	for (auto u : g[v]) {
		if (u == p)
			continue;
		int i = u.first;
		if (!num[i])
			efs(i, {v, u.second});
		low[v] = min(low[v], low[i]);
		if (num[v] < low[i]) {
			all.insert(u.second);
		}
	}
}

int main() {
	doin();
	cin >> n >> m;
	g.resize(n + 1);
	num.resize(n + 1);
	low.resize(n + 1);
	while (m--) {
		cin >> f >> t >> c;
		if (f > t)
			swap(f, t);
		edges.pb( { c, { f, t } });
		edges2.pb( { f, t });
	}
	dsu a(n);
	sort(all(edges));
	for (int i = 0; i < edges.size(); i++) {
//		FUCKTHISPROBLEM.clear();
		int j = i;
		int x, y;
		while (j < edges.size() && edges[i].first == edges[j].first) {
			x = a.par(edges[j].second.first);
			y = a.par(edges[j].second.second);
			if (x > y)
				swap(x, y);
			if (x != y) {
				nall.insert(
						{ edges[j].second.first, edges[j].second.second });\
			}
			j++;
		}
		for (int k = i; k < j; k++) {
			x = a.par(edges[k].second.first);
			y = a.par(edges[k].second.second);
			num[x] = num[y] = 0;
			g[x].clear();
			g[y].clear();
		}
		for (int k = i; k < j; k++) {
			x = a.par(edges[k].second.first);
			y = a.par(edges[k].second.second);
//			if (FUCKTHISPROBLEM.find( { x, y }) == FUCKTHISPROBLEM.end()){
				g[x].pb(
						{ y, { edges[k].second.first, edges[k].second.second } });
			g[y].pb( { x, { edges[k].second.first, edges[k].second.second } });
		}
		t = 0;
		for (int k = i; k < j; k++) {
			if (!num[a.par(edges[k].second.first)])
				efs(a.par(edges[k].second.first), {-1, {-1, -1}});
			if (!num[a.par(edges[k].second.second)])
				efs(a.par(edges[k].second.second),
						{-1, {-1, -1}});
		}
		while (i < j) {
			a.unite(edges[i].second.first, edges[i].second.second);
			i++;
		}
		i = j - 1;
	}
	for (auto i : edges2) {
		if (all.find(i) != all.end())
			cout << "any\n";
		else if (nall.find(i) != nall.end())
			cout << "at least one\n";
		else
			cout << "none\n";
	}
}