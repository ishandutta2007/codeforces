#pragma GCC target("avx2")
#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;

#define G(x) ll x; cin>>x;
#define F(i, l, r) for (ll i=l; i<(r); ++i)
#define all(a) begin(a), end(a)
#define K first
#define V second
#define N 100010

set<pl> avail;
map<pl, vl> lst;
vl tree[N];
set<ll> graph[N];
pl ans[N];

ll sz[N], lvl[N];

ll getSize(ll i, ll p) {
	sz[i] = 1;
	for(ll j : tree[i])
		if(j - p && !lvl[j])
			sz[i] += getSize(j, i);
	return sz[i];
}

ll centroid(ll i, ll p, ll n) {
	for(ll j : tree[i])
		if(j - p && !lvl[j] && sz[j] > n / 2)
			return centroid(j, i, n);
	return i;
}

ll decomp(ll i, ll l) {
	ll cent = centroid(i, -1, getSize(i, -1));
	lvl[cent] = l;
	for(ll j : tree[cent]) if(!lvl[j])
		decomp(j, l + 1);
	return cent;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	G(n) G(m)
	F(i, 1, n + 1) {
		graph[i].insert(i % n + 1);
		avail.insert({i, i % n + 1});
	}
	F(i, 0, m) {
		G(a) G(b)
		avail.insert({a, b}); avail.insert({b, a});
		graph[a].insert(b); graph[b].insert(a);
	}
	F(i, 1, m + 2) {
		pl p = *avail.begin(); ll v = p.K;
		vector<ll> cyc;
		do {
			cyc.push_back(p.V);
			p = { p.V, p.K <= *graph[p.V].begin() ? *graph[p.V].rbegin() : *--graph[p.V].lower_bound(p.K) };
		} while(p.K != v);
		ll prv = cyc.back();
		for(ll x : cyc) {
			if((x - prv + n) % n > 1) lst[{min(prv, x), max(prv, x)}].push_back(i);
			avail.erase({prv, x});
			graph[prv].erase(x);
			prv = x;
		}
		sort(all(cyc)); reverse(all(cyc));
		ans[i].K = cyc[0] * N * N + cyc[1] * N + cyc[2];
	}
	for(auto a : lst) tree[a.V[0]].push_back(a.V[1]), tree[a.V[1]].push_back(a.V[0]);
	decomp(1, 1);
	F(i, 1, m + 2) ans[i].V = lvl[i];
	sort(ans + 1, ans + m + 2);
	F(i, 1, m + 2) cout << ans[i].V << ' ';
	cout << '\n';
}