#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 1<<19, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define INLINE inline __attribute__ (( always_inline ))
struct link_cut_tree {
	struct node {
		array<node*, 2> c;
		node *p;
		int rev, cnt;
		ll cadd, vadd;
		pair<ll, int> f, mf;
		node() : c{0, 0}, p(0), rev(0), cnt(1), cadd(0), vadd(0), f{0, 0}, mf(f) {}
		INLINE friend void con(node *x, int d, node *y) {
			if(x && d >= 0) x->c[d] = y;
			if(y) y->p = x;
		}
		INLINE int dir() {
			if(!p) return -2;
			if(p->c[0] == this) return 0;
			if(p->c[1] == this) return 1;
			return -1;
		}
		INLINE void rotate() {
			auto g = p;
			int d = dir();
			con(g->p, g->dir(), this);
			con(g, d, c[!d]);
			con(this, !d, g);
			g->update();
		}
		void clear() {
			if(dir() >= 0) p->clear(); push();
		}
		INLINE void splay() {
			clear();
			while(dir() >= 0) {
				if(p->dir() >= 0) (p->dir() == dir() ? p : this)->rotate();
				rotate();
			}
			update();
		}
		INLINE void reverse() {
			swap(c[0], c[1]), rev ^= 1;
		}
		INLINE void apply(ll x) {
			cadd += x;
			vadd += x;
			f.first += x;
			mf.first += x;
		}
		INLINE void push() {
			if(rev) {
				for(auto i : c) if(i) i->reverse();
				rev = 0;
			}
			if(cadd) {
				for(auto i : c) if(i) i->apply(cadd);
				cadd = 0;
			}
		}
		INLINE void update() {
			cnt = 1;
			mf = f;
			for(auto i : c) if(i) {
				cnt += i->cnt;
				mf = min(mf, i->mf);
			}
		}
		INLINE void update_vsub(node *x, int add) {
			if(add) x->apply(-vadd);
			else x->apply(vadd);
			
		}
		INLINE void setval(pair<ll, int> x) {
			f = x;
			update();
		}
	};
	INLINE void expose(node *u) {
		for(node *v = u, *p = 0; v; v = v->p) {
			v->splay();
			if(v->c[1]) v->update_vsub(v->c[1], 1);
			if(p) v->update_vsub(p, 0);
			v->c[1] = p, v->update(), p = v;
		}
		u->splay();
	}
	INLINE void make_root(node *v) {
		expose(v), v->reverse();
	}
	INLINE int depth(node *v) {
		expose(v);
		return v->cnt;
	}
	INLINE void link(node *u, node *v) {
		expose(u), make_root(v);
		con(u, 1, v);
		u->update();
	}
	INLINE void cut(node *v) {
		expose(v);
		v->c[0]->p = 0;
		v->c[0] = 0;
		v->update();
	}
	INLINE void cut(node *u, node *v) {
		cut(depth(u) > depth(v) ? u : v);
	}
	INLINE node *root(node *v) {
		expose(v);
		while(v->push(), v->c[0]) v = v->c[0];
		return v->splay(), v;
	}
	INLINE node *par(node *v) {
		expose(v);
		v = v->c[0];
		while(v->push(), v->c[1]) v = v->c[1];
		return v->splay(), v;
	}
	INLINE bool connected(node *u, node *v) {
		return root(u) == root(v);
	}
	vector<node> a;
	link_cut_tree(int n) : a(n) {}
	int operator[](node *v) { return v-&a[0]; }
	node *operator[](int v) { return &a[v]; }
};
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m, q;
	cin >> n >> m >> q;
	link_cut_tree lct(n+1);
	vector<array<int, 2>> e(n-1);
	for(auto &[x, y] : e) cin >> x >> y;
	vector<vector<ll>> f(n+1);
	vector<int> gtv(m+1);
	for(int c, i = 1; i <= m; i++) {
		cin >> c;
		gtv[i] = c;
		f[c].push_back(i);
	}
	for(int i = 1; i <= n; i++) f[i].push_back(1ll<<55);
	for(int i = 1; i <= n; i++) reverse(all(f[i]));
	for(int i = 1; i <= n; i++) {
		lct[i]->setval({f[i].back(), min(1ll<<30, f[i].back())});
	}
	for(auto &[x, y] : e) lct.link(lct[x], lct[y]);
	for(int t, u, v, k; q--;) {
		cin >> t;
		if(t == 1) {
			cin >> u >> v >> k;
			lct.make_root(lct[u]);
			lct.expose(lct[v]);
			vector<int> ans;
			for(int IT = k; IT--;) {
				auto [__weight, id] = lct[v]->mf;
				if(id > m) break;
				u = gtv[id];
				ans.push_back(id);
				ll add = __weight - id;
				f[u].pop_back();
				lct.expose(lct[u]);
				lct[u]->setval({f[u].back() + add, min(1ll<<30, f[u].back())});
				lct.expose(lct[v]);
			}
			cout << ans.size() << " ";
			for(auto i : ans) cout << i << " "; cout << '\n';
		} else {
			lct.make_root(lct[1]);
			cin >> u >> k;
			auto p = u == 1 ? 0 : lct.par(lct[u]);
			if(p) lct.cut(lct[u]);
			lct[u]->apply(k);
			if(p) lct.link(p, lct[u]);
		}
	}
}