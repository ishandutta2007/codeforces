#include<bits/stdc++.h>
using namespace std;
#define all(x) begin(x), end(x)
using ll = long long;
const int maxn = 1<<16;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
enum seg_type { seg_not_lazy, seg_lazy, seg_beats };
template<class node, seg_type type>
struct segment_tree
{
	using node_container = typename node::node_container;
	using lazy_container = typename node::lazy_container;
	#define enable_if(x) template <const bool T = (x), typename enable_if<T, bool>::type = 0>
	#define enable_if_not(x) template <const bool T = (x), typename enable_if<!T, bool>::type = 0>

private:
	enable_if(type != seg_not_lazy)
	inline void push(int x, int b, int e, int m)
	{
		if (st[x].lazy())
		{
			st[x + 1].apply(b, m, st[x].lazy);
			st[x + ((m - b) << 1)].apply(m, e, st[x].lazy);
			st[x].lazy = lazy_container();
		}
	}

	enable_if_not(type != seg_not_lazy)
	inline void push(int x, int b, int e, int m) {}

	template<typename RAIter>
	void build(int x, int b, int e, const RAIter &a)
	{
		if (b+1 == e)
		{
			st[x].nod.build(a[b]);
			return;
		}

		int m = (b + e) >> 1;
		int y = x + ((m - b) << 1);

		build(x + 1, b, m, a);
		build(y, m, e, a);
		st[x].nod = st[x + 1].nod + st[y].nod;
	}

	enable_if_not(type == seg_beats)
	void update_(int x, int b, int e)
	{
		if (lo <= b && e <= hi)
		{
			st[x].apply(b, e, lazy);
			return;
		}

		int m = (b + e) >> 1;
		int y = x + ((m - b) << 1);
		push(x, b, e, m);

		if (lo < m) update_(x + 1, b, m);
		if (m < hi) update_(y, m, e);
		st[x].nod = st[x + 1].nod + st[y].nod;
	}

	enable_if(type == seg_beats)
	void update_(int x, int b, int e)
	{
		if (st[x].break_condition(lazy)) return;

		if (lo <= b && e <= hi && st[x].tag_condition(lazy))
		{
			st[x].apply(b, e, lazy);
			return;
		}

		int m = (b + e) >> 1;
		int y = x + ((m - b) << 1);
		push(x, b, e, m);

		if (lo < m) update_(x + 1, b, m);
		if (m < hi) update_(y, m, e);
		st[x].nod = st[x + 1].nod + st[y].nod;
	}

	node_container query(int x, int b, int e)
	{
		if (lo <= b && e <= hi)
			return st[x].nod;

		int m = (b + e) >> 1;
		int y = x + ((m - b) << 1);
		push(x, b, e, m);

		if (m >= hi) return query(x + 1, b, m);
		if (m <= lo) return query(y, m, e);
		return query(x + 1, b, m) + query(y, m, e);
	}

	template<class P>
	int find_first(int x, int b, int e, const P &f)
	{
		if (b+1 == e)
			return f(st[x]) ? b : -1;

		int m = (b + e) >> 1;
		int y = x + ((m - b) << 1);
		push(x, b, e, m);

		if (lo < m && f(st[x + 1]))
		{
			auto t = find_first(x + 1, b, m, f);
			if (t != -1) return t;
		}
		if (m < hi && f(st[y]))
			return find_first(y, m, e, f);
		return -1;
	}

	template<class P>
	int find_last(int x, int b, int e, const P &f)
	{
		if (b+1 == e)
			return f(st[x]) ? b : -1;

		int m = (b + e) >> 1;
		int y = x + ((m - b) << 1);
		push(x, b, e, m);

		if (m < hi && f(st[y]))
		{
			auto t = find_last(y, m, e, f);
			if (t != -1) return t;
		}
		if (lo < m && f(st[x + 1]))
			return find_last(x + 1, b, m, f);
		return -1;
	}

	lazy_container lazy;
	int n, lo, hi;
	vector<node> st;

public:
	template<typename RAIter>
	void build(const RAIter &a)
	{
		build(0, 0, n, a);
	}

	void update(int l, int r, const lazy_container &x)
	{
		lo = l, hi = r, lazy = x, update_(0, 0, n);
	}

	node_container query(int l, int r)
	{
		return lo = l, hi = r, query(0, 0, n);
	}

	template<class P>
	int find_first(int l, int r, const P &f)
	{
		return lo = l, hi = r, find_first(0, 0, n, f);
	}

	template<class P>
	int find_last(int l, int r, const P &f)
	{
		return lo = l, hi = r, find_last(0, 0, n, f);
	}

	segment_tree(int n = 1) : n(n), st(2 * n - 1) {}
};

struct node // sub of squares
{
	struct node_container
	{
		array<ll, 3> s;
		template<typename T>
		inline void build(const T &a) // build(leave) from a
		{
			ll t = 1;
			for(int i = 0; i < 3; i++) {
				s[i] = t;
				t *= a;
			}
		}

		friend node_container operator+(node_container l, const node_container &r) // merge l and r
		{
			for(int i = 0; i < 3; i++) l.s[i] += r.s[i];
			return l;
		}

		node_container() : s{1, 0, 0} {}
	} nod;

	struct lazy_container
	{
		ll add = 0;

		inline bool operator()() // has lazy
		{
			return add != 0;
		}

		lazy_container(ll _add = 0) : add(_add) {}
	} lazy;

	inline void apply(int l, int r, lazy_container &p) // apply lazy
	{
		lazy.add += p.add;
		nod.s[2] = nod.s[2] + 2*p.add*nod.s[1] + p.add*p.add*nod.s[0];
		nod.s[1] += nod.s[0]*p.add;
	}
};
struct virtual_tree
{
	vector<int> tour, depth, pos, mp;
	vector<vector<int>> table;

	virtual_tree(vector<vector<int>> &adj)
	{
		pos = mp = vector<int>(adj.size());
		function<void(int, int, int)> dfs = [&](int u, int p, int d)
		{
			pos[u] = tour.size();
			tour.push_back(u);
			depth.push_back(d);

			for (int v : adj[u])
				if (v != p)
				{
					dfs(v, u, d+1);
					tour.push_back(u);
					depth.push_back(d);
				}			
		};
		dfs(0, -1, 0);

		int t = tour.size(), lg = __lg(t);
		table.resize(lg+1, vector<int>(t));
		iota(table[0].begin(), table[0].end(), 0);
		for (int j = 0; j < lg; ++j)
			for (int i = 0; i + (1<<(j+1)) <= t; ++i)
				table[j+1][i] = argmin(table[j][i], table[j][i+(1<<j)]);
	}

	inline int argmin(int i, int j) { return depth[i] < depth[j] ? i : j; }

	inline int lca(int u, int v)
	{
		int i = pos[u], j = pos[v];
		if (i > j) swap(i, j);
		int l = __lg(j - i);
		return i == j ? u : tour[argmin(table[l][i], table[l][j-(1<<l)])];
	}

	inline int dist(int u, int v)
	{
		return depth[pos[u]] + depth[pos[v]] - 2*depth[pos[lca(u, v)]];
	}

	vector<vector<pair<int, int>>> compress(vector<int> c)
	{
		auto cmp = [&](const int &x, const int &y) { return pos[x] < pos[y]; };

		sort(c.begin(), c.end(), cmp);
		for (int i = 1, sz = c.size(); i < sz; ++i)
			c.push_back(lca(c[i-1], c[i]));

		sort(c.begin(), c.end(), cmp);
		c.erase(unique(c.begin(), c.end()), c.end());

		vector<vector<pair<int, int>>> g(c.size());
		vector<int> s;

		// u become mp[u]

		for (auto &u : c)
		{
			mp[u] = &u-&c[0];
			while (!s.empty() && lca(s.back(), u) != s.back())
				s.pop_back();

			if (!s.empty())
			{
				int d = dist(s.back(), u);
				g[mp[s.back()]].push_back({ mp[u], d });
				g[mp[u]].push_back({ mp[s.back()], d });
			}

			s.push_back(u);
		}

		return g;
	}
};
const int C = 2000;
map<int, int> freq, stid;
int n, mf, q;
ll ccost, cost[maxn];

vector<vector<int>> g {{1}, {0}};
virtual_tree lca(g);

int col[maxn];

int h[maxn], sz[maxn], head[maxn], p[maxn], tin[maxn], tout[maxn], timer = 0;
void calc(int v) {
	sz[v] = 1;
	for(int &i : g[v]) {
		g[i].erase(find(all(g[i]), v));
		h[i] = h[v]+1;
		p[i] = v;
		calc(i);
		if(sz[g[v][0]] < sz[i]) swap(g[v][0], i);
		sz[v] += sz[i];
	}
}
void build_hld(int v) {
	tin[v] = timer++;
	for(auto i : g[v]) {
		head[i] = g[v][0] == i ? head[v] : i;
		build_hld(i);
	}
	tout[v] = timer;
}

vector<int> al[maxn];
ll S2[maxn], S1[maxn], S0[maxn];
void insert_slow(int c, int V) {
	al[c].push_back(V);
	S0[c]++;
	S1[c] += h[al[c].back()];
	for(auto i : al[c]) {
		S2[c] += h[lca.lca(i, al[c].back())]*(1 + (i != al[c].back()));
	}
}
void erase_slow(int c, int V) {
	int pos = find(all(al[c]), V)-al[c].begin();
	swap(al[c].back(), al[c][pos]);
	for(auto i : al[c]) {
		S2[c] -= h[lca.lca(i, al[c].back())]*(1 + (i != al[c].back()));
	}
	S0[c]--;
	S1[c] -= h[al[c].back()];
	al[c].pop_back();
}

segment_tree<node, seg_lazy> st[51];
void insert_fast(int c, int v, int delta = 1) {
	int id;
	if(!stid.count(c)) {
		id = stid.size();
		stid[c] = id;
	}
	id = stid[c];
	//cout << v << endl;
	while(true) {
		st[id].update(tin[head[v]], tin[v]+1, node::lazy_container(delta));
		if(head[v]) v = p[head[v]];
		else break;
	}
}
void erase_fast(int c, int v) {
	insert_fast(c, v, -1);
}

void insert(int c, int v) {
	if(freq[c] < C) insert_slow(c, v);
	else insert_fast(c, v);
}
void erase(int c, int v) {
	if(freq[c] < C) erase_slow(c, v);
	else erase_fast(c, v);
}

using ld = long double;
ld calc_slow(int col) {//(R - ccost)^2 = R^2 - 2Rccost + ccost^2
	//cout << col << " ::: " << S2[col] << " " << S1[col] << " " << cost[col] << endl;
	ld ans = 0;
	ans += (ld(S2[col])/n)*cost[col]*cost[col];
	ans -= 2.*(ld(S1[col])/n)*cost[col]*ccost;
	ans += ccost*1ll*ccost;
	return ans;
}
ld calc_fast(int c) {
	int id;
	if(!stid.count(c)) {
		id = stid.size();
		stid[c] = id;
	}
	id = stid[c];
	auto tst = st[id].query(0, n).s;
	ld S1 = tst[1];
	ld S2 = tst[2];
	//cout << c << " :: " << S1 << " " << S2 << " " << cost[c] << endl;
	id = stid[c];
	ld ans = 0;
	ans += (ld(S2)/n)*cost[c]*cost[c];
	ans -= 2.*(ld(S1)/n)*cost[c]*ccost;
	ans += ccost*1ll*ccost;
	return ans;
}
ld calcans(int c) {
	if(freq[c] < C) return calc_slow(c);
	else return calc_fast(c);
}

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> mf >> q >> ccost;
	vector<ll> T(n);
	for(int i = 0; i < 51; i++) st[i] = segment_tree<node, seg_lazy>(n), st[i].build(T.begin());
	for(int i = 0; i < n; i++) {
		cin >> col[i];
		freq[col[i]]++;
	}
	g.assign(n, {});
	for(int t, i = 1; i < n; i++) {
		cin >> t;--t;
		g[i].push_back(t);
		g[t].push_back(i);
	}
	for(int i = 1; i <= mf; i++) cin >> cost[i];
	vector<array<int, 3>> qu(q);
	for(auto &[x,y,z] : qu) {
		cin >> x >> y;z = -1;
		if(x == 1) cin >> z, freq[z]++;
		//cout << x << " " << y << " " << z << endl;
	}
	
	lca = virtual_tree(g);
	h[0] = 1;
	calc(0);
	build_hld(0);
	
	for(int i = 0; i < n; i++) insert(col[i], i);
	
	cout << fixed << setprecision(7);
	for(auto [t, x, y] : qu) {
		if(t == 1) {
			x--;
			erase(col[x], x);
			insert(col[x] = y, x);
		} else {
			cout << calcans(x) << '\n';
		}
	}
}