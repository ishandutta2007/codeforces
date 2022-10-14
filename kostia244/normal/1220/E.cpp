#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
vi w;
struct dsu {
	vi r, p;
	void init(int n) {
		r.resize(n+1);
		p.resize(n+1);
		for(int i = 0; i <= n; i++) p[i] = i, r[i] = 1;
	}
	int par(int i) {
		if(i==p[i]) return i;
		return p[i] = par(p[i]);
	}
	void unite(int i, int j) {
		i=par(i), j = par(j);
		if(i==j) return;
		if(r[i] < r[j]) swap(i, j);
		p[j] = i;
		r[i] += r[j];
		w[i] += w[j];
	}
};
int n, m, s;
vector<vi> g, t;
vi dp, h;
vector<pi> e, te;
dsu d;
void bridges(int v, int p) {
	for(auto i : g[v]) {
		if(i==p) continue;
		if(!h[i]) h[i] = h[v]+1, bridges(i, v), dp[v] += dp[i];
		else (h[i] < h[v] ? ++dp[v] : --dp[v]);
	}
	if(dp[v]) {
		d.unite(v, p);
	}
}
void cmt(int v, int p) {
	dp[v] = d.r[v]>1;
	for(auto i : t[v]) {
		if(i==p) continue;
		cmt(i, v);
		if(dp[i]) {
			dp[v]=1;
			d.unite(v, i);
		}
	}
}
ll dfs(int v, int p) {
	ll cur = 0;
	for(auto i : t[v]) {
		if(i==p) continue;
		cur = max(cur, dfs(i, v));
	}
	return cur+w[v];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	w.resize(n+1);
	for(int i = 1; i <= n; i++) cin >> w[i];
	g.resize(n+1);
	for(int f, t, i = 1; i <= m; i++) {
		cin >> f >> t;
		e.pb({f, t});
		g[f].pb(t);
		g[t].pb(f);
	}
	cin >> s;
	d.init(n);
	dp.resize(n+1);
	h.resize(n+1);
	h[1] = 1;
	bridges(1, 1);
	for(auto i : e) {
		i.first = d.par(i.first), i.second = d.par(i.second);
		if(i.first!=i.second)
			te.pb(i);
	}
	sort(all(te));
	te.erase(unique(all(te)), te.end());
	t.resize(n+1);
	for(auto i : te){
		t[i.first].pb(i.second);
		t[i.second].pb(i.first);
	}
	dp.assign(n+1, 0);
	cmt(d.par(s), d.par(s));
	e.clear();
	t.clear();
	for(auto i : te){
		i.first = d.par(i.first), i.second = d.par(i.second);
		if(i.first!=i.second)
			e.pb(i);
	}
	sort(all(e));
	e.erase(unique(all(e)), e.end());
	t.resize(n+1);
	for(auto i : e){
		t[i.first].pb(i.second);
		t[i.second].pb(i.first);
	}
	cout << dfs(d.par(s), -1);
}