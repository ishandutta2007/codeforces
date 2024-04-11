#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
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

	segment_tree(int n) : n(n), st(2 * n - 1) {}
};

struct node // arithmetic progression
{
	struct node_container
	{
		struct data {
			int a, b, c, ab, bc, abc;
			data() {
				a = b = c = ab = bc = abc = -(1<<20);
			}
			friend data operator+(const data &l, const data &r) {
				data res;
				res.a = max(l.a, r.a);
				res.b = max(l.b, r.b);
				res.c = max(l.c, r.c);
				res.ab = max({l.ab, r.ab, l.a+r.b});
				res.bc = max({l.bc, r.bc, l.b+r.c});
				res.abc = max({l.abc, r.abc, l.a + r.bc, l.ab + r.c});
				return res;
			}
		};
		array<data, 2> d;

		template<typename T>
		inline void build(T a) // build(leave) from a
		{
			int t = a >= 1<<30;
			if(t) a -= 1<<30;
			d[0].b = d[1].b = -2*a;d[t].a = d[t].c = a;
			d[t].ab = d[t].bc = -a; d[t].abc = 0;
		}

		friend node_container operator+(node_container l, const node_container &r) // merge l and r
		{
			node_container a;a.d = {l.d[0]+r.d[0], l.d[1]+r.d[1]};
			return a;
		}

		node_container() {}
	} nod;

	struct lazy_container
	{
		int rev = 0;
		inline bool operator()() // has lazy
		{
			return rev;
		}
		lazy_container(int rev = 0) : rev(rev) {}
	} lazy;

	inline void apply(int l, int r, lazy_container &p) // apply lazy
	{
		lazy.rev ^= 1;
		swap(nod.d[0], nod.d[1]);
	}
};
struct diameter {
	int n;
	vector<array<int, 3>> edges;
	vector<vector<array<int, 2>>> g;
	vector<int> h, tin, tout, tour;
	segment_tree<node, seg_lazy> st;
	diameter(vector<array<int, 3>> el) : n(el.size()+1), edges(el), g(n), h(n), tin(n), tout(n), st(2*n-1) {
		for(auto &[x, y, z] : el) {
			g[x].push_back({y, z});
			g[y].push_back({x, z});
		}
		dfs(0, 0);
		for(auto &[x, y, z] : edges) if(tin[x] > tin[y]) swap(x, y);
		st.build(tour.begin());
	}
	void dfs(int v, int dep) {
		tin[v] = tour.size();
		tour.push_back(dep + (h[v]<<30));
		for(auto &[i, w] : g[v]) {
			g[i].erase(find(all(g[i]), array<int, 2>{v, w}));
			h[i] = h[v] ^ w;
			dfs(i, dep+1);
			tour.push_back(dep + (h[v]<<30));
		}
		tout[v] = tour.size();
	}
	int update(int v) {
		v = edges[v][1];
		st.update(tin[v], tout[v], node::lazy_container(1));
		auto t = st.query(0, 2*n-1);
		//cout << t.d[0].a << " " << t.d[0].b << " " << t.d[0].c << endl;
		return max(t.d[0].abc, t.d[1].abc);
	}
};
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, x, y;
	cin >> n;
	vector<array<int, 3>> er(n-1);
	for(auto &i : er) cin >> i[0] >> i[1] >> i[2], --i[0], --i[1];
	diameter d(er);
	for(cin >> x; x--;) {
		cin >> y;
		cout << d.update(--y) << '\n';
	}
	return 0;
}