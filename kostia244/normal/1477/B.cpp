#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 4055, mod = 1e9 + 7;
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
		ll x;

		template<typename T>
		inline void build(const T &a) // build(leave) from a
		{
			x = a == '1';
		}

		friend node_container operator+(node_container l, const node_container &r) // merge l and r
		{
			l.x += r.x;
			return l;
		}

		node_container() : x(0) {}
	} nod;

	struct lazy_container
	{
		ll val = -1;

		inline bool operator()() // has lazy
		{
			return val != -1;
		}

		lazy_container(ll V = -1) : val(V) {}
	} lazy;

	inline void apply(int l, int r, lazy_container &p) // apply lazy
	{
		if (p.val != -1)
		{
			nod.x = (r-l)*p.val;
			lazy.val = p.val;
		}
	}
};
void solve() {
	int n, q;
	string s, t;
	cin >> n >> q >> t >> s;
	vector<array<int, 2>> a(q);
	for(auto &[l, r] : a) cin >> l >> r;
	reverse(all(a));
	segment_tree<node, seg_lazy> st(n);
	st.build(s.begin());
	int good = 1;
	//for(int i = 0; i < n; i++) cout << st.query(i, i+1).x; cout << endl;
	for(auto &[l, r] : a) {l--;
		int sum = st.query(l, r).x, len = r-l;
		//cout << l << " " << r << " || " << sum << endl;
		if(sum*2 == len) {
			good = 0;
			break;
		}
		st.update(l, r, node::lazy_container(sum > (len-sum)));
		
		//for(int i = 0; i < n; i++) cout << st.query(i, i+1).x; cout << endl;
	}
	//cout << t << "v" << endl;
	for(int i = 0; i < n; i++) good &= (t[i]-'0') == st.query(i, i+1).x;
	cout << (good ? "YES" : "NO") << '\n';
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) solve();
}