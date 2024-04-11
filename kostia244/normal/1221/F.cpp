#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#define M_PI 3.14159265358979323846
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using ld = long double;
using vec = complex<ld>;
const ld eps = 1e-7;
ld dot(vec a, vec b) {
	return (conj(a) * b).real();
}
ld cross(vec a, vec b) {
	return (conj(a) * b).imag();
}
istream& operator>>(istream& in, vec& p) {
	ld x, y;
	in >> x >> y;
	p = vec(x, y);
	return in;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct node {
	ll mx, lazy, i;
	node(ll val = -1e17, int _i = -1) {
		mx = val;
		lazy = 0;
		i = _i;
	}
};
node merge(node a, node b) {
	if(a.mx < b.mx)
		swap(a, b);
	a.lazy = 0;
	return a;
}
struct segment_tree {
	int n;
	vector<node> tree;

	void push(int v, int l, int r) {
		if (tree[v].lazy == 0)
			return;
		tree[v].mx += tree[v].lazy;
		if (l != r) {
			tree[v << 1].lazy += tree[v].lazy;
			tree[v << 1 | 1].lazy += tree[v].lazy;
		}
		tree[v].lazy = 0;
	}

	void init(int nn) {
		this->n = nn;
		tree.resize(4 * n + 6);
	}

	void set(int i, ll v) {
		set(1, 1, n, i, v, i);
	}
	void set(int v, int l, int r, int i, ll val, ll iii) {
		push(v, l, r);
		if (i < l || i > r)
			return;
		if (l == r) {
			tree[v] = node(val, iii);
			return;
		}
		int mid = (l + r) >> 1;
		set(v << 1, l, mid, i, val, iii);
		set(v << 1 | 1, mid + 1, r, i, val, iii);
		tree[v] = merge(tree[v << 1], tree[v << 1 | 1]);
	}

	void add(int l, int r, ll val) {
		add(1, 1, n, l, r, val);
	}
	void add(int v, int l, int r, int ql, int qr, ll val) {
		push(v, l, r);
		if (qr < l || r < ql)
			return;
		if (l >= ql && r <= qr) {
			tree[v].lazy += val;
			push(v, l, r);
			return;
		}
		int mid = (l + r) >> 1;
		add(v << 1, l, mid, ql, qr, val);
		add(v << 1 | 1, mid + 1, r, ql, qr, val);
		tree[v] = merge(tree[v << 1], tree[v << 1 | 1]);
	}

	node get(int l, int r) {
		return get(1, 1, n, l, r);
	}
	node get(int v, int l, int r, int ql, int qr) {
		if (qr < l || ql > r)
			return node();
		if (l >= ql && r <= qr) {
			return tree[v];
		}
		int mid = (l + r) >> 1;
		return merge(get(v << 1, l, mid, ql, qr),
				get(v << 1 | 1, mid + 1, r, ql, qr));
	}

};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	map<int, vector<pair<int, int>>> g;
	vi ls;
	map<int, int> lid;
	for (int x, y, c, i = 0; i < n; i++) {
		cin >> x >> y >> c;
		if (x > y)
			swap(x, y);
		g[y].pb( { x, c });
		ls.pb(x);
	}

	sort(all(ls));
	ls.erase(unique(all(ls)), ls.end());

	segment_tree st;
	st.init(ls.size());
	for (int i = 0; i < ls.size(); i++) {
		st.set(i + 1, ls[i]);
		lid[ls[i]] = i + 1;
	}
	ll ans = 0;
	pi a ={2000000000, 2000000000};
	for (auto &seg : g) {
		for (auto i : seg.second) {
			st.add(1, lid[i.first], i.second);
		}
		auto it = upper_bound(all(ls), seg.first);
		if (it != ls.begin()) {
			int p = it-ls.begin();
			node t = st.get(1, p);
			if(ans < t.mx-seg.first) {
				ans = t.mx-seg.first;
				a = {ls[t.i-1], seg.first};
			}
		}
	}
	cout << ans << "\n" << a.first << " " << a.first << " " << a.second << " " << a.second;
}