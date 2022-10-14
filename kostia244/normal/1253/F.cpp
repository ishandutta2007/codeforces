//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const ll mod = 1e9 + 7;
ll n, m, k, q, curw = 0;
vector<pair<pi, ll>> edges;
vector<vector<pi>> g;
vector<pair<int, int>> qs[300300];
vi d, ans;

struct dsu {
	vi r, p;
	void init(int n) {
		p.assign(n+1, 0);
		r.assign(n+1, 0);
		for(int i = 0; i <= n; i++) p[i] = i;
	}
	int par(int i) {
		if(i==p[i]) return i;
		return p[i] = par(p[i]);
	}
	void unite(int i, int j) {
		i = par(i), j = par(j);
		if(i==j) return;
		if(r[i] < r[j]) swap(i, j);
		check(j, i);
		p[j] = i;
		r[i] += r[i]==r[j];
	}
	void check(int a, int b) {
		for(int i = 0; i < qs[a].size(); i++) {
			if(par(b)==par(qs[a][i].first)) {
				ans[qs[a][i].second] = curw;
			} else
				qs[b].pb(qs[a][i]);
		}
	}
};

void dijkstra() {
	d.resize(n+1, 1e18);
	priority_queue<pair<ll, ll>> q;
	for(int i = 1; i <= k; i++) d[i]=0, q.push({0, i});
	while(!q.empty()) {
		ll c, u;
		tie(c, u) = q.top();
		q.pop();
		c*=-1;
		if(d[u]<c) continue;
		for(auto i : g[u]) {
			ll v = i.first, w = i.second;
			if(d[v] > d[u]+w) {
				d[v] = d[u]+w;
				q.push({-d[v], v});
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> k >> q;
	edges.resize(m);
	g.resize(n+1);
	for(auto &i : edges) {
		cin >> i.first.first >> i.first.second >> i.second;
		g[i.first.first].pb({i.first.second, i.second});
		g[i.first.second].pb({i.first.first, i.second});
	}
	dijkstra();
	for(int a, b, i = 0; i < q; i++) {
		cin >> a >> b;
		qs[a].pb({b, i});
		qs[b].pb({a, i});
	}
	ans.resize(q);
	vector<pair<ll, pair<ll, ll>>> ne;
	for(auto i : edges) {
		ll c = d[i.first.first]+d[i.first.second]+i.second;
		ne.pb({c, i.first});
	}
	sort(all(ne));
	dsu dd;
	dd.init(n+1);
	for(auto i : ne) {
		if(dd.par(i.second.first)==dd.par(i.second.second)) continue;
		curw = i.first;
//		cout << i.second.first << " " << i.second.second << " " << d[i.second.first]+d[i.second.second] << "\n";
		dd.unite(i.second.first, i.second.second);
	}
	for(auto i : ans)
		cout << i << "\n";
}