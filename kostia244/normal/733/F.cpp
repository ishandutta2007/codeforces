#pragma comment(linker, "/stack:200000000")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vector<ll>>;
const ll mod = 696969569;
using oset = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct edge {
	ll x, y, w, c, i;
	bool operator<(const edge &rhs) const {
		return pair<ll, ll>(w, c) < pair<ll, ll>(rhs.w, rhs.c);
	}
};
struct segtree {
	int n;
	vector<pair<int, edge>> tree;
	void init(int sz) {
		n = sz;
		tree.assign(2*n, {0, edge()});
	}
	void set(int p, pair<int, edge> x) {
		for(tree[p+=n]=x; p>>=1;)
			tree[p] = max(tree[p<<1], tree[p<<1|1]);
	}
	pair<int, edge> get(int l, int r) {
		pair<int, edge> a = {0, edge()};
		for(l+=n, r+=n+1; l<r; l>>=1, r>>=1) {
			if(l&1) a = max(a, tree[l++]);
			if(r&1) a = max(tree[--r], a);
		}
		return a;
	}
};
struct dsu {
	vi r, p;
	void init(int n) {
		r.assign(n+1, 0);
		p.resize(n+1, 0);
		for(int i = 1; i <= n; i++) p[i] = i;
	}
	int par(int x) {
		if(x == p[x]) return x;
		return p[x] = par(p[x]);
	}
	void unite(int x, int y) {
		x = par(x), y = par(y);
		if(x==y)return;
		if(r[x]<r[y]) swap(x, y);
		p[y] = x;
		r[x] += r[x] == r[y];
	}
	bool sameset(int x, int y) {
		return par(x) == par(y);
	}
};
ll n, m, s, timer = -1;
vector<edge> edges, treeedges;
vi ein, eout, sz, par, head;
segtree st;
vvi g;
bool anc(int x, int y) {
	return ein[x] <= ein[y] && ein[y] <= eout[x];
}
void rempar(int v, int p) {
	for(auto &i : g[v])
		if(i==p) swap(g[v].back(), i);
	g[v].pop_back();
}
void sizes(int v) {
	sz[v] = 1;
	for(auto &i : g[v]) {
		rempar(i, v);
		par[i] = v;
		sizes(i);
		sz[v] += sz[i];
		if(sz[i] > sz[g[v][0]])
			swap(g[v][0], i);
	}
}
void hld(int v) {
	ein[v] = ++timer;
	for(auto i : g[v]) {
		head[i] = (i==g[v][0]?head[v]:i);
		hld(i);
	}
	eout[v] = timer;
}
void up(int &x, int &y, pair<int, edge> &ans) {
	while(!anc(head[x], y)) {
		ans = max(ans, st.get(ein[head[x]], ein[x]));
		x = par[head[x]];
	}
}
pair<int, edge> get(int u, int v) {
	pair<int, edge> ans = {0, edge()};
	up(u, v, ans);
	up(v, u, ans);
	if(!anc(u, v)) swap(u, v);
	return max(ans, st.get(ein[u]+1, ein[v]));
}

ll ans = 0, sm = 0;
edge add, ban;
void init() {
	st.init(n);
	ein.resize(n+1, 0);
	eout.resize(n+1, 0);
	sz.resize(n+1, 0);
	par.resize(n+1, 0);
	head.resize(n+1, 0);
	g.resize(n+1);
	for(auto i : treeedges)
		g[i.x].pb(i.y), g[i.y].pb(i.x), sm += i.w;//, cout <<i.x << " -> " << i.y << " " << i.w << "\n";
	ans = sm;
	for(auto i : treeedges)
		ans = min(ans, sm - (s/i.c));
	par[1] = 1;
	sizes(1);
	head[1] = 1;
	hld(1);
	add.x=-1;
	for(auto i : treeedges) {
		if(anc(i.x, i.y)) swap(i.x, i.y);
		st.set(ein[i.x], {i.w, i});
	}
	for(auto i : edges) {
		auto t = get(i.x, i.y);
		ll v = sm - t.first + i.w - (s/i.c);
		ans = min(ans, v);
		if(ans == v&&minmax(i.x, i.y) != minmax(t.second.x, t.second.y))
			add=i, ban=t.second;
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	edges.resize(m);
	for(int i = 0; i < m; i++) edges[i].i=i+1;
	for(int i = 0; i < m; i++) cin >> edges[i].w;
	for(int i = 0; i < m; i++) cin >> edges[i].c;
	for(int i = 0; i < m; i++) cin >> edges[i].x >> edges[i].y;
	cin >> s;
	sort(all(edges));
	dsu d;
	d.init(n);
	for(auto i : edges) {
		if(!d.sameset(i.x, i.y)) {
			d.unite(i.x, i.y);
			treeedges.pb(i);
		}
	}
	init();
	if(add.x!=-1)
		treeedges.pb(add);
	cout << ans << "\n";
	ll m = 1e9;
	for(auto i : treeedges)
		if(i.x!=ban.x||i.y!=ban.y)
		m = min(i.c, m);
//	cout << ban.x << " " << ban.y << " " << treeedges.size() << "\n";
	for(auto i : treeedges)
		if(minmax(i.x, i.y) != minmax(ban.x, ban.y)) {
			if(m==i.c) {
				i.w -= s/i.c;
				m=-999999;
			}
			ans-=i.w;
			cout << i.i << " " << i.w << "\n";
		}
	if(ans) return -1;

}