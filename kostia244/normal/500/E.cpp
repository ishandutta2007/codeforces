// Problem: E. New Year Domino
// Contest: Codeforces - Good Bye 2014
// URL: https://codeforces.com/contest/500/problem/E
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;

template<typename F>
void multitest(F func) {
	int t;
	cin >> t;
	while(t--) func();
}
void report(int ok) {
	cout << (ok?"YES":"NO") << '\n';
}

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

struct node
{
	struct node_container
	{
		array<ll, 2> x;

		template<typename T>
		inline void build(const T &a) // build(leave) from a
		{
			x = {0, a};
		}

		friend node_container operator+(node_container l, node_container r) // merge l and r
		{
			if(l.x > r.x) swap(l.x, r.x);
			if(l.x[0] == r.x[0]) l.x[1] += r.x[1];
			return l;
		}

		node_container() : x({0, 0}) {}
	} nod;

	struct lazy_container
	{
		ll add = 0;

		inline bool operator()() // has lazy
		{
			return add;
		}

		lazy_container(ll x = 0) : add(x) {}
	} lazy;

	inline void apply(int l, int r, lazy_container &p) // apply lazy
	{
		nod.x[0] += p.add;
		lazy.add += p.add;
	}
};

int n, q;
vector<array<int, 2>> a;
vector<vector<array<int, 2>>> queries;
vector<int> ans, coord;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//multitest([&](){});
	cin >> n;
	a.resize(n);
	for(auto &[p, l] : a) {
		cin >> p >> l;
		coord.push_back(p);
		coord.push_back(p+l);
	}
	sort(all(coord));
	coord.erase(unique(all(coord)), coord.end());
	cin >> q;
	queries.resize(n);
	ans.resize(q);
	segment_tree<node, seg_lazy> st(coord.size());
	vector<int> f(coord.size());
	for(int i = 0; i < coord.size(); i++)
		f[i] = i+1 < coord.size() ? coord[i+1]-coord[i] : 0;
	st.build(f.begin());
	for(int l, r, i = 0; i < q; i++) {
		cin >> l >> r;
		l--,r--;
		queries[l].push_back({r, i});
	}
	auto get = [&](int x) { return lower_bound(all(coord), x) - coord.begin(); };
	for(int i = n; i--;) {
		st.update(get(a[i][0]), get(a[i][0]+a[i][1]), node::lazy_container(1));
		for(auto [r, id] : queries[i]) {
			auto t = st.query(get(a[i][0]), get(a[r][0]));
			ans[id] = t.x[0] > 0 ? 0 : t.x[1];
		}
	}
	for(auto i : ans) cout << i << '\n';
}