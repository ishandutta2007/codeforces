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
#ifdef LOCAL
//	freopen("in", "r", stdin);
#endif
}
typedef long long ll;
typedef int _I;
typedef double ld;
typedef pair<_I, _I> pi;
typedef pair<ld, ld> pd;
typedef map<_I, _I> mii;
typedef __V <_I> vi;
typedef __V <char> vc;
typedef __V <ld> vd;
typedef __V <pi> vpi;
typedef __V <__V<_I>> vvi;
typedef __V <__V<char>> vvc;
typedef __V <__V<pi>> vvpi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int n, m, f, t, c;
vvpi g;
vvi times;
vi dist;
bitset<100001> vis;
priority_queue<pi> q;

int jam(vi::iterator it, vi::iterator end) {
	int lo = 0, hi = end - it - 1, mid, c =0;
	while (lo < hi) {
		mid = (lo + hi + 1) >> 1;
		if ((*(it + mid) - *it) == mid)
			lo = mid;
		else
			hi = mid - 1;
	}
	while ((it + hi + 1) != end && (*(it + hi + 1) - *it) != hi + 1)
		hi++;
	while ((*(it + hi) - *it) != hi)
		hi--;
	return hi+1;
}

int main() {
	doin();
	cin >> n >> m;
	g.resize(n + 1);
	times.resize(n + 1);
	dist.resize(n + 1, 1010100000);
	while (m--) {
		cin >> f >> t >> c;
		g[f].pb( { c, t });
		g[t].pb( { c, f });
	}
	for (int i = 1; i <= n; i++) {
		cin >> f;
		while (f--) {
			cin >> t;
			times[i].pb(t);
		}
	}
	q.push( { 0, 1 });
	dist[1] = 0;
	int u, d;
	while (!q.empty()) {
		tie(d, u) = q.top();
		d = -d;
		q.pop();
		vis.set(u);
		if (d > dist[u])
			continue;
		if(u == n)
			return cout << d, 0;
		auto i = lower_bound(all(times[u]), d);
		if (i != times[u].end() && *i == d) {
			d += jam(i, times[u].end());
		}
		for (auto v : g[u])
			if (int w = d + v.first; w < dist[v.second])
				dist[v.second] = w, q.push( { -w, v.second });
	}
	cout << (dist[n] == 1010100000 ? -1 : dist[n]);
	return 0;
}