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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
set<pi> components;
struct dsu {
	vi sz, p, dp;
	dsu(ll n) {
		sz.resize(n + 1, 1);
		dp.resize(n + 1);
		p.resize(n + 1);
		for (ll i = 1; i <= n; i++)
			p[i] = i, components.insert( { 0, i });
	}
	ll par(ll i) {
		if (p[i] == i)
			return i;
		return p[i] = par(p[i]);
	}
	void unite(ll i, ll j, ll cst) {
		ll x = par(i), y = par(j);
		if (x == y) {
			components.erase( { dp[y], y });
			dp[x] += cst;
			dp[x] = min(dp[x], 1000000000ll);
			components.insert( { dp[y], y });
			return;
		}
		components.erase( { dp[x], x });
		components.erase( { dp[y], y });
		if (sz[x] > sz[y])
			swap(x, y);
		p[x] = y;
		sz[y] += sz[x];
		dp[y] += dp[x];
		dp[y] += cst;
		dp[y] = min(dp[y], 1000000000ll);
		components.insert( { dp[y], y });
	}
	void unite(ll i, ll j) {
		ll x = par(i), y = par(j);
		if (x == y) {
			components.erase( { dp[y], y });
			dp[x] += 1000;
			dp[x] = min(dp[y], 1000000000ll);
			components.insert( { dp[y], y });
			return;
		}
		components.erase( { dp[x], x });
		components.erase( { dp[y], y });
		if (sz[x] > sz[y])
			swap(x, y);
		p[x] = y;
		sz[y] += sz[x];
		dp[y] += dp[x];
		dp[y] += dp[y]+1;
		dp[y] = min(dp[y], 1000000000ll);
		components.insert( { dp[y], y });
	}
};
ll n, m, f, t, c, p, q;
vpi ans;
int main() {
	doin();
	cin >> n >> m >> p >> q;
	dsu d(n);
	while (m--) {
		cin >> f >> t >> c;
		d.unite(f, t, c);
	}
	if (components.size() < q)
		return cout << "NO", 0;
	while (components.size() > q && p) {
		auto it = components.begin();
		auto it2 = it;
		it2++;
		ans.eb(d.par(it->second), d.par(it2->second));
		d.unite(it->second, it2->second);
		p--;
	}
	ll i = -1;
	for (ll j = 1; j <= n; j++)
		if (d.par(j) != j)
			i = j;
	if (components.size() != q || (i == -1 && p))
		return cout << "NO", 0;

	while (p--) {
		ans.eb(i, d.par(i));
	}
	cout << "YES\n";
	for (auto i : ans)
		cout << i.first << " " << i.second << "\n";
}