#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
struct link_cut_tree {
	struct node {
		array<node*, 2> c{};
		node* p = 0;
		int rev = 0, cnt = 1, mn = 1<<30, key = 1<<30;
		void set_key(int x) {key = x; update();}
		int dir() {
			if(!p) return -2;
			if(p->c[0] == this) return 0;
			if(p->c[1] == this) return 1;
			return -1;
		}
		friend void con(node *u, int d, node *v) {
			if(u && d >= 0) u->c[d] = v;
			if(v) v->p = u;
		}
		void reverse() {
			swap(c[0], c[1]), rev ^= 1;
		}
		void push() {
			if(rev) {
				for(auto i : c) if(i) i->reverse();
				rev = 0;
			}
		}
		void update() {
			cnt = 1;
			mn = key;
			for(auto i : c) if(i) {
				cnt += i->cnt;
				mn = min(mn, i->mn);
			}
		}
		void clear() {
			if(dir() >= 0) p->clear(); push();
		}
		void rotate() {
			auto g = p;
			int d = dir();
			con(g->p, g->dir(), this);
			con(g, d, c[!d]);
			con(this, !d, g);
			g->update();
		}
		void splay() {
			clear();
			while(dir() >= 0) {
				if(p->dir() >= 0) (p->dir() == dir() ? p : this)->rotate();
				rotate();
			}
			update();
		}
	};
	void expose(node *u) {
		for(node *v = u, *p = 0; v; v = v->p)
			v->splay(), v->c[1] = p, v->update(), p = v;
		u->splay();
	}
	int depth(node *v) {
		expose(v);
		return v->c[0] ? v->c[0]->cnt : 0;
	}
	void make_root(node *u) {
		expose(u);
		u->reverse();
	}
	void link(node *u, node *v) {
		make_root(v), expose(u);
		con(u, 1, v), u->update();
	}
	void cut(node *u) {
		expose(u);
		u->c[0]->p = 0;
		u->c[0] = 0;
		u->update();
	}
	void cut(node *u, node *v) {
		cut(depth(u) < depth(v) ? v : u);
	}
	node *root(node *v) {
		expose(v);
		while(v->push(), v->c[0]) v = v->c[0];
		return v->splay(), v;
	}
	bool connected(node *u, node *v) {
		return root(u) == root(v);
	}
	vector<node> a;
	link_cut_tree(int n) : a(n) {}
	int operator[](node *x) { return x - &a[0]; }
	node* operator[](int x) { return &a[x]; }
};
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m, q;
	cin >> n >> m >> q;
	vector<array<int, 2>> edges(m);
	for(auto &[x, y] : edges) cin >> x >> y, x--, y--;
	vector<int> ans, used(m);
	link_cut_tree lct(n+m);
	for(int i = 0; i < m; i++) lct[n+i]->set_key(i);
	auto cut = [&](int id) {
		id%=m;
		if(used[id]) {
			auto [u, v] = edges[id];
			auto w = lct[n+id];
			lct.cut(lct[u], w);
			lct.cut(lct[v], w);
		}
	};
	auto link = [&](int id) {
		auto [u, v] = edges[id];
		auto w = lct[n+id];
		int f = -2;
		if(lct.connected(lct[u], lct[v])) {
			int x = lct.depth(lct[u])^lct.depth(lct[v]); x/=2;
			lct.make_root(lct[u]);
			lct.expose(lct[v]);
			f = lct[v]->mn;
			cut(f);
			if(x&1) f = -2;
		}
		lct.link(lct[u], w);
		lct.link(lct[v], w);
		used[id] = 1;
		return f;
	};
	int cur = -1;
	for(int i = 0; i < m; i++) {
		cur = max(cur, link(i));
	}
	if(cur == -1) ans = vector<int>(m+1, m);
	else {
		ans.push_back(m-cur-1);
		for(int i = 0; i < m; i++) {
			lct[n+i]->set_key(m+i);
			cur = max(cur, link(i));
			ans.push_back(m+i-cur);
		}
	}
	for(int l, r; q--;) {
		cin >> l >> r;--l;
		r = m - (r-l);
		cout << (ans[l] < r ? "YES" : "NO") << '\n';
	}
}