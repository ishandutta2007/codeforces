#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define pb push_back
using namespace std;using ll = long long;
using vi = vector<ll>;
const int maxn = 1<<17, mlg = 17, mod = 998244353;
ll ans = 0;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define debug(x) 69
struct treap {
	struct node {
		node *l, *r;
		int val, pri, cnt;
		ll sm;
		node(int v = 0) : l(0), r(0), cnt(1), sm(v), val(v), pri(rng()) {}
	};
	using pnode = node*;
	pnode root = 0;
	ll aux = 0;
	void upd(pnode v) {
		if(v) {
			v->sm = (v->l?v->l->sm:0) + (v->r?v->r->sm:0) + v->val;
			v->cnt = (v->l?v->l->cnt:0) + (v->r?v->r->cnt:0) + 1;
		}
	}
	pnode merge(pnode a, pnode b) {
		if(!a || !b) return a ?: b;
		if(a->pri < b->pri) {
			a->r = merge(a->r, b);
			upd(a);
			return a;
		}
		b->l = merge(a, b->l);
		upd(b);
		return b;
	}
	pair<pnode, pnode> split(pnode v, int k) {
		if(!v) return {0, 0};
		if(v->val <= k) {
			auto t = split(v->r, k);
			v->r = t.first;
			upd(v);
			return {v, t.second};
		}
		auto t = split(v->l, k);
		v->l = t.second;
		upd(v);
		return {t.first, v};
	}
	void insert(int x, int q = 1) {
		auto t = split(root, x);
		ll delta = 0;
		if(t.first) delta += t.first->sm;
		if(t.second) delta += t.second->cnt*1ll*x;
		ans += delta;
		aux += delta;
		root = merge(merge(t.first, new node(x)), t.second);
		debug({
			cout << "Insertion :\n";
			cout << "{";
			print(root);
			cout << "}";
			cout << sum() << ";\n";
			cout << x << " + " << delta << '\n';
		});
	}
	int size() {
		return root ? root->cnt : 0;
	}
	ll sum() {
		return root ? root->sm : 0;
	}
	void dfs(pnode rt, treap &t) {
		if(!rt) return;
		dfs(rt->l, t);
		t.insert(rt->val, 0);
		dfs(rt->r, t);
	}
	void print(pnode rt) {
		if(!rt) return;
		print(rt->l);
		cout << rt->val << ", ";
		print(rt->r);
	} 
};
struct range {
	int l, r;
	treap t;
	range(int l = 0, int r = 0) : l(l), r(r) {}
	range* merge(range *o) {
		if(o->t.size() > t.size()) {
			o->merge(this);
			return o;
		}
		debug({
		cout << "merging " << l << " " << r << " and " << o->l << " " << o->r << '\n';
		cout << "{";
		t.print(t.root);
		cout << "}";
		cout << t.sum() << ";\n";
		cout << "{";
		o->t.print(o->t.root);
		cout << "}";
		cout << o->t.sum() << ";\n";
		});
		if(o->l < l) {
			debug(cout << "delta = " << abs(o->l - l) << " * " << t.sum() << '\n');
			ans -= (l - o->l)*t.sum();
		} else {
			debug(cout << "delta = " << abs(o->l - l) << " * " << o->t.sum() << '\n');
			ans -= (o->l - l)*o->t.sum();
		}
		
		l = min(l, o->l);
		r = max(r, o->r);
		ans -= o->t.aux;
		o->t.dfs(o->t.root, t);
		debug({
		cout << "resulted in " << l << " " << r << '\n';
		cout << "{";
		t.print(t.root);
		cout << "}";
		cout << t.sum() << ";\n";
		});
		return this;
	}
};
map<int, range*> L, R;
void add(range* a) {
	debug(cout << a->l << " " << a->r << " added.\n");
	L[a->l] = a;
	R[a->r] = a;
}
void rem(range* a) {
	debug(cout << a->l << " " << a->r << " removed.\n");
	L.erase(a->l);
	R.erase(a->r);
}
void insert(int a, int b) {
	debug(cout << "inserting " << a << " " << b << '\n');
	auto it = L.upper_bound(a);
	range *x;
	if(it != L.begin() && (--it)->second->r >= a) {
		x = it->second;
		debug({
			cout << "contained in " << x->l << " " << x->r << " " << x->t.size() << '\n';
			cout << "{";
			x->t.print(x->t.root);
			cout << "}";
			cout << x->t.sum() << ";\n";
			cout << -(x->l-a)*1ll*b << " subtract\n";
		});
		rem(x);
		debug(cout << "ANS: " << ans << '\n');
		x->t.insert(b);
		debug(cout << "ANS: " << ans << '\n');
		ans -= (a-x->l)*1ll*b;
		debug(cout << "ANS: " << ans << " : " << x->l << " " << a << '\n');
		x->r++;
	} else{
		debug(cout << "creating a new range\n");
		x = new range(a, a);
		x->t.insert(b);
	}
	if(R.count(x->l-1)) {
		auto t = R[x->l-1];
		rem(t);
		x = x->merge(t);
	}
	if(L.count(x->r+1)) {
		auto t = L[x->r+1];
		rem(t);
		x = x->merge(t);
	}
	add(x);
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	/*
	treap a, b;
	a.insert(1);
	b.insert(-1);
	a.print(a.root);cout << '\n';
	b.print(b.root);cout << '\n';
	b.dfs(b.root, a);
	a.print(a.root);cout << '\n';
	*/
	int n, a, b;
	cin >> n;
	while(n--) {
		cin >> a >> b;
		insert(a, b);
		debug({
		for(auto i : L) cout << (i.second->l) << " " << (i.second->r) << '\n';
		cout << "ANSWER: ";
		});
		cout << ans << '\n';
	}
}