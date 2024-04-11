#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
struct RMQ {
	vector<vector<int>> s;
	void build(vector<int> a) {
		s.emplace_back(a);
		for(int k = 1; (1<<k) <= a.size(); k++) {
			s.emplace_back(s.back());
			for(int i = 0; i+(1<<(k-1)) < a.size(); i++) {
				s.back()[i] = max(s.back()[i], s.back()[i+(1<<(k-1))]);
			}
		}
	}
	int qry(int l, int r) {
		if(l >= r) return -1;
		int k = __lg(r-l);
		return max(s[k][l], s[k][r-(1<<k)]);
	}
};
struct PathMin {//nonzero w
	int n;
	vector<int> p, a;
	RMQ r;
	int find(int v) { return p[v]==-1?v:p[v]=find(p[v]); }
	PathMin(vector<array<int, 3>> edges) : n(edges.size()+1), p(n, -1) {
		sort(all(edges));
		vector<list<int>> L(n);
		for(int i = 0; i < n; i++)
			L[i] = {i};
		for(auto [w, u, v] : edges) {
			u = find(u), v = find(v);
			L[u].push_back(-w);
			L[u].splice(L[u].end(), L[v]);
			p[v] = u;
		}
		for(auto i : L[find(0)]) {
			if(i < 0)
				a.push_back(-i);
			else
				p[i] = a.size();
		}
		r.build(a);
	}
	int qry(int u, int v) {
		if(min(u, v) < 0) return -1;
		if(p[u] > p[v]) swap(u, v);
		return r.qry(p[u], p[v]);
	}
};
PathMin pm({});
struct SegTree {
	struct S {
		int v, lazy, val, ful, fv;
		S(int V = -1) : v(V), lazy(-1), val(-1), ful(-1), fv(V) {}
		void apply(int l) {
			if(l==-1) return;
			lazy = l;
			if(l) val = ful, v = fv;
			else val = -1, v = -1;
		}
		friend S operator+(S a, S b) {
			S res;
			res.v = max(a.v, b.v);
			res.val = max({a.val, b.val, pm.qry(a.v, b.v)});
			res.ful = max({a.ful, b.ful, pm.qry(a.fv, b.fv)});
			res.fv = max(a.fv, b.fv);
			return res;
		}
	};
	int n;
	vector<S> tree;
	SegTree(int n, vector<array<int, 3>> edges) : n(n), tree(4*n) {
		pm = PathMin(edges);
		build(1, 0, n-1);
	}
	void push(int v) {
		tree[2*v].apply(tree[v].lazy);
		tree[2*v+1].apply(tree[v].lazy);
		tree[v].lazy = -1;
	}
	void build(int v, int l, int r) {
		if(l == r) {
			tree[v] = S(l);
			tree[v].apply(0);
		} else {
			int m = (l+r)/2;
			build(2*v, l, m);
			build(2*v+1, m+1, r);
			tree[v] = tree[2*v]+tree[2*v+1];
		}
	}
	void upd(int v, int l, int r, int ql, int qr, int val) {
		if(r < ql || qr < l) return;
		if(ql <= l && r <= qr) {
			tree[v].apply(val);
			return;
		}
		push(v);
		int m = (l+r)/2;
		upd(2*v, l, m, ql, qr, val);
		upd(2*v+1, m+1, r, ql, qr, val);
		tree[v] = tree[2*v]+tree[2*v+1];
	}
	int get(int v) {
		return max(tree[1].val, pm.qry(tree[1].v, v));
	}
};
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<array<int, 3>> edges(n-1);
	for(auto &[w, u, v] : edges)
		cin >> u >> v >> w, u--,v--;
	SegTree tree(n, edges);
	for(int t, l, r, i = 0; i < m; i++) {
		cin >> t >> l; l--;
		if(t < 3) {
			cin >> r;
			tree.upd(1, 0, n-1, l, r-1, t==1);
		} else {
			cout << tree.get(l) << '\n';
		}
	}
}