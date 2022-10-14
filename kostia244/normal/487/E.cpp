#pragma GCC optimize("O2")
#pragma GCC target("avx,avx2,sse,fma")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using pi = pair<ll, ll>;
const int maxn = 4e5 + 55, mlg = 19, mod = (119 << 23) + 1;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int __n;
int cur_val[maxn];
///Seg Tree
const int inf = 1e9;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi, mset = inf, madd = 0, val = -inf;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			val = max(l->val, r->val);
		}
		else val = v[lo];
	}
	int query(int L, int R) {
		if (R <= lo || hi <= L) return -inf;
		if (L <= lo && hi <= R) return val;
		push();
		return max(l->query(L, R), r->query(L, R));
	}
	void set(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = val = x, madd = 0;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void add(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if (mset != inf) mset += x;
			else madd += x;
			val += x;
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (mset != inf)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
		else if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}
};
/// HLD
template <bool VALS_EDGES = 0> struct HLD {
	int N, tim = 0;
	vector<vi> adj;
	vi par, siz, depth, rt, pos;
	Node *tree;
	HLD(vector<vi> adj_)
		: N(sz(adj_)), adj(adj_), par(N, -1), siz(N, 1), depth(N),
		  rt(N),pos(N),tree(new Node(0, N)){ dfsSz(0); dfsHld(0); }
	void dfsSz(int v) {
		if (par[v] != -1) adj[v].erase(find(all(adj[v]), par[v]));
		for (int& u : adj[v]) {
			par[u] = v, depth[u] = depth[v] + 1;
			dfsSz(u);
			siz[v] += siz[u];
			if (siz[u] > siz[adj[v][0]]) swap(u, adj[v][0]);
		}
	}
	void dfsHld(int v) {
		pos[v] = tim++;
		for (int u : adj[v]) {
			rt[u] = (u == adj[v][0] ? rt[v] : u);
			dfsHld(u);
		}
	}
	int aux = 0;
	template <class B> void process(int u, int v, B op) {
		for (; rt[u] != rt[v]; v = par[rt[v]]) {
			if (depth[rt[u]] > depth[rt[v]]) swap(u, v);
			op(pos[rt[v]], pos[v] + 1);
		}
		if (depth[u] > depth[v]) swap(u, v);
		op(pos[u] + VALS_EDGES, pos[v] + 1);
		//cout << u << "wu\n";
		if(u >= __n) aux = cur_val[par[u]];
	}
	void modifyPath(int u, int v, int val) {
		process(u, v, [&](int l, int r) { tree->add(l, r, val); });
	}
	int queryPath(int u, int v) { // Modify depending on problem
		//cout << u << " -> " << v << endl;
		aux = -1e9;
		int res = -1e9;
		process(u, v, [&](int l, int r) {
				res = max(res, tree->query(l, r));
		});
		//cout << aux << "<3" << endl;
		return max(res,aux);
	}
	int querySubtree(int v) { // modifySubtree is similar
		return tree->query(pos[v] + VALS_EDGES, pos[v] + siz[v]);
	}
};

///BCT


int n, m, q;
vector<vi> g, tree;
vi h, dp;
void dfs(int v, int p) {
	dp[v] = h[v];
	for(auto i : g[v]) {
		if(!h[i]) {
			h[i] = h[v]+1;
			dfs(i, v);
			dp[v] = min(dp[v], dp[i]);
		} else
			dp[v] = min(dp[v], h[i]);
	}
}
int sz;
vector<pair<pi, int>> t;
void bct(int v, int p, int id = sz) {
	for (auto i : g[v]) {
		if (!h[i]) {
			h[i] = h[v] + 1;
			int nid = dp[i]>=h[v]?++sz:id;
			t.pb({{v, i}, nid});
			bct(i, v, nid);
		}
	}
}
void buildbct(vector<vi> &tree) {
	sz = n;
	dp.assign(n+1, 0);
	h.assign(n+1, 0);
	h[1] = 1;
	dfs(1, 1);
	h.assign(n+1, 0);
	h[1] = 1;
	bct(1, 1);
	tree.resize(sz+1);
	for(auto i : t) {
		tree[i.first.first].pb(i.second);
		tree[i.second].pb(i.first.first);
		tree[i.first.second].pb(i.second);
		tree[i.second].pb(i.first.second);
	}
	for(auto &i : tree) {
		sort(all(i));
		i.erase(unique(all(i)), i.end());

	}
}
HLD hl({{1}, {0}});
multiset<int> cur_vals[maxn];
void set_(int v, int x, int old_val) {
	hl.modifyPath(v, v, -old_val);
	hl.modifyPath(v, v, x);
	if(!v) return;
	v = hl.par[v];
	if(cur_vals[v].size())
		hl.modifyPath(v, v, -*cur_vals[v].rbegin());
	else
		hl.modifyPath(v, v, inf);
	if(old_val != -inf)
		cur_vals[v].erase(cur_vals[v].find(old_val));
	cur_vals[v].insert(x);
	hl.modifyPath(v, v, *cur_vals[v].rbegin());
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> q;
	__n = n;
	vector<int> _a(n);
	for(auto &i : _a) cin >> i;
	g.resize(n + 1);
	for (int f, t, i = 0; i < m; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	buildbct(tree);
	for(int i = 0; i < sz; i++) {
		tree[i] = tree[i+1];
		for(auto &j : tree[i]) j--;
		//for(auto j : tree[i]) cout << i << " " << j << endl;
	}
	tree.pop_back();
	hl = HLD(tree);
	for(int i = 0; i < sz; i++) cur_val[i] = -inf;
	for(int i = 0; i < n; i++) {
		set_(i, -_a[i], cur_val[i]);
		cur_val[i] = -_a[i];
	}
	char c;
	int x, y;
	while(q--) {
		//cout << "BEGIN" << endl;
		//for(int i = n; i < sz; i++) {
		//	cout << cur_vals[i].size() << " : ";
		//	for(auto j : cur_vals[i]) cout << j << " "; cout << endl;
		//}
		//for(int i = 0; i < sz; i++) cout << hl.tree->query(hl.pos[i], hl.pos[i]+1) << " "; cout << endl;
		cin >> c >> x >> y;
		if(c == 'A') {
			x--, y--;
			cout << -hl.queryPath(x, y) << '\n';
		} else {
			x--;
			set_(x, -y, cur_val[x]);
			cur_val[x] = -y;
		}
	}
	return 0;
}