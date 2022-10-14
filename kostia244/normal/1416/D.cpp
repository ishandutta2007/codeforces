//Why am I doing this?
#pragma GCC optimize("Ofast,unroll-loops,inline")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
#define INLINE inline __attribute__ (( always_inline ))
struct TTree {
	#define con(a, b, c) b = c;\
				if(c) c->p = a;
	struct node {
		node *p, *lt;
		array<array<node*,2>,2> c;
		int rev;
		template<int tt> INLINE int dir() {
			if(p) {
				if(p->c[tt][0] == this) return 0;
				if(p->c[tt][1] == this) return 1;
			}
			return -1;
		}
		template<int tt> INLINE void rotate(int d) {
			auto g = p;
			p = g->p;
			if(tt == 0) {
				swap(c[1], g->c[1]);
				for(auto &i : c[1]) if(i) i->p = this;
			}
			con(g, g->c[tt][d], c[tt][!d]);
			con(this, c[tt][!d], g);
			g->update();
			if(!p) return;
			if(p->lt == g) p->lt = this;
			for(auto &i : p->c) for(auto &j : i) if(j == g) j = this;
		}
		void flush() {
			if(p) p->flush(); push();
		}
		template<int tt> INLINE void splay() {
			for(int x, y; (x = dir<tt>()) >= 0;) {
				if((y = p->dir<tt>()) >= 0)
					(x == y ? p : this)->rotate<tt>(x), x = y;
				rotate<tt>(x);
			}
			update();
		}
		
		int val, mx;
		node(int x = 0) : p(0), lt(0), c{}, rev(0), val(x), mx(x) {}
		INLINE void reverse() {swap(c[0][0], c[0][1]); rev ^= 1;}
		INLINE void push() {
			if(rev) {
				for(auto i : c[0]) if(i) i->reverse();
				rev = 0;
			}
		}
		INLINE void update() {
			mx = val;
			for(auto x : c) for(auto i : x)
				if(i) mx = max(mx, i->mx);
			if(lt) mx = max(mx, lt->mx);
		}
	};
	void expose(node *u) {
		u->flush();
		u->splay<0>(), u->splay<1>();
		for(node *v = u->p; v; v = v->p) {
			v->splay<0>(), v->splay<1>();
			auto x = v->lt;
			if(auto z = v->c[0][1]) {
				z->push();
				swap(z->c[1], x->c[1]);
				v->lt = z;
				for(auto i : z->c[1]) if(i) i->p = z;
				z->update();
			} else if(!x->c[1][0]) {
				con(v, v->lt, x->c[1][1]);
			} else {
				auto z = x->c[1][0];
				con(v, v->lt, z);
				while(z->push(), z->c[1][1]) z = z->c[1][1];
				z->splay<1>();
				con(z, z->c[1][1], x->c[1][1]);
				z->update();
			}
			x->c[1].fill(0);
			v->c[0][1] = x;
			x->update();
			v->update();
		}
		u->splay<0>();
		if(auto z = u->c[0][1]) {
			z->push();
			con(z, z->c[1][1], u->lt);
			con(u, u->lt, z);
			u->c[0][1] = 0;
			z->update();
			u->update();
		}
	}
	INLINE void make_root(node *v) {
		expose(v), v->reverse();
	}
	INLINE void link(node *u, node *v) {
		expose(u), make_root(v);
		con(u, u->c[0][1], v);
		u->update();
	}
	INLINE void cut(node *u) {
		expose(u);
		u->c[0][0]->p = 0;
		u->c[0][0] = 0;
		u->update();
	}
	INLINE void cut(node *u, node *v) {
		expose(u), v->flush(), v->splay<0>();
		if(v->p) {//v is the lower one
			swap(u, v);
			expose(u);
		} else u->splay<0>();
		u->c[0][0]->p = 0;
		u->c[0][0] = 0;
		u->update();
	}
	
	vector<node> a;
	TTree(int n) : a(n) {}
	node *operator[](int v) { return &a[v]; }
	int operator[](node *v) { return v-&a[0]; }
};
struct dsu {
	vector<int> r, p;
	dsu(int n = 0) : r(n, 1), p(n, -1) {}
	int par(int v) { return p[v] == -1 ? v : p[v] = par(p[v]); }
	bool join(int u, int v) {
		u = par(u), v = par(v);
		if(u == v) return 0;
		if(r[u] < r[v]) swap(u, v);
		r[u] += r[v];
		p[v] = u;
		return 1;
	}
};
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m, q;
	cin >> n >> m >> q;
	vector<array<int, 2>> queries(q), edges(m);
	vector<int> rem_time(m, -(1<<30)), useful(m), a(n), a2i(n+1);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		a2i[a[i]] = i;
	}
	for(auto &[f, t] : edges) cin >> f >> t, --f, --t;
	int T = 0;
	for(auto &[t, x] : queries) {
		cin >> t >> x;x--;
		if(t == 2) rem_time[x] = --T;
	}
	vector<array<int, 4>> ms;
	for(int i = 0; i < m; i++)
		ms.push_back({rem_time[i], i, edges[i][0], edges[i][1]});
	dsu d(n);
	sort(all(ms));
	for(auto &[t, id, u, v] : ms) {
		useful[id] = d.join(u, v);
	}
	
	TTree tt(n);
	for(int i = 0; i < n; i++) tt[i]->mx = tt[i]->val = a[i];
	for(int i = 0; i < m; i++)
		if(useful[i])
			tt.link(tt[edges[i][0]], tt[edges[i][1]]);
	for(auto &[t, x] : queries) {
		if(2-t) {
			tt.expose(tt[x]);
			cout << tt[x]->mx << '\n';
			if(tt[x]->mx) {
				x = a2i[tt[x]->mx];
				tt.expose(tt[x]);
				tt[x]->val = 0;
				tt[x]->update();
			}
		} else if(useful[x]) {
			tt.cut(tt[edges[x][0]], tt[edges[x][1]]);
		}
	}
}