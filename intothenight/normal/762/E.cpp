#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/rope>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
mt19937 rng(high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(high_resolution_clock::now().time_since_epoch().count());
template<typename T> T ctmax(T &x, const T &y){ return x = max(x, y); }
template<typename T> T ctmin(T &x, const T &y){ return x = min(x, y); }
template<typename T> using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename P, typename R, typename T = int, typename L = int>
struct treap{
	struct node{
		node *l = 0, *r = 0;
		T val, subtr_val;
		L lazy;
		int priority, sz = 1, ind = 0;
		node(T val, L lazy, int ind = 0): val(val), subtr_val(val), lazy(lazy), ind(ind), priority(rng()){ }
	};
	node *root = 0;
	P push; // push: update Lazy to child val and subtr_val
	R refresh; // refresh: Recalculate sz and subtr_val
	template<typename IT>
	treap(IT begin, IT end, P push, R refresh, L lazy_init = 0): push(push), refresh(refresh){
		root = build(begin, end, lazy_init);
	}
	treap(int n, P push, R refresh, T val_init = 0, L lazy_init = 0): push(push), refresh(refresh){
		root = build(n, val_init, lazy_init);
	}
	void heapify(node *u){
		if(u){
			node *v = u;
			if(u->l && u->l->priority > v->priority) v = u->l;
			if(u->r && u->r->priority > v->priority) v = u->r;
			if(u != v){
				swap(u->priority, v->priority);
				heapify(v);
			}
		}
	}
	template<typename IT>
	node *build(IT begin, IT end, T lazy_init){
		if(begin == end) return 0;
		IT mid = begin + (end - begin >> 1);
		node *c = new node(*mid, lazy_init);
		c->l = build(begin, mid, lazy_init), c->r = build(mid + 1, end, lazy_init);
		heapify(c), refresh(c);
		return c;
	}
	node *build(int n, T val_init, T lazy_init){
		if(!n) return 0;
		int m = n >> 1;
		node *c = new node(val_init, lazy_init);
		c->l = build(m, val_init, lazy_init), c->r = build(n - m - 1, val_init, lazy_init);
		heapify(c), refresh(c);
		return c;
	}
	int get_sz(node *u){
		return u ? u->sz : 0;
	}
	pair<node *, node *> split(node* u, int k){
		if(!u) return { };
		push(u);
		if(u->val >= k){
		// if(get_sz(u->l) >= k){ // For the implicit treap
			auto [a, b] = split(u->l, k);
			u->l = b;
			refresh(u);
			return {a, u};
		}
		else{
			auto [a, b] = split(u->r, k);
			// auto [a, b] = split(u->r, k - get_sz(u->l) - 1); // For the implicit treap
			u->r = a;
			refresh(u);
			return {u, b};
		}
	}
	node *merge(node *u, node *v){
		if(!u || !v) return u ?: v;
		push(u), push(v);
		if(v->priority < u->priority){
			u->r = merge(u->r, v);
			refresh(u);
			return u;
		}
		else{
			v->l = merge(u, v->l);
			refresh(v);
			return v;
		}
	}
	node *insert(node *u, node *t){
		if(!u) return t;
		auto [a, b] = split(u, t->val);
		return merge(merge(a, t), b);
	}
};
/*
	auto push = [&](auto *u){
		if(u && u->lazy){
			if(u->l){
				u->l->lazy += u->lazy;
				u->l->val += u->lazy;
				u->l->subtr_val += u->lazy * u->l->sz;
			}
			if(u->r){
				u->r->lazy += u->lazy;
				u->r->val += u->lazy;
				u->r->subtr_val += u->lazy * u->r->sz;
			}
			u->lazy = 0;
		}
	};
	auto refresh = [&](auto *u){
		u->sz = (u->l ? u->l->sz : 0) + (u->r ? u->r->sz : 0) + 1;
		u->subtr_val = (u->l ? u->l->subtr_val : 0) + (u->r ? u->r->subtr_val : 0) + u->val;
	};
*/

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int n, k;
	cin >> n >> k;
	const int mxf = 1e4;
	vector<vector<array<int, 2>>> a(mxf);
	for(auto i = 0; i < n; ++ i){
		int x, r, f;
		cin >> x >> r >> f, -- f;
		a[f].push_back({r, x});
	}
	for(auto &x: a){
		sort(x.rbegin(), x.rend());
	}
	auto push = [&](auto *u){
	};
	auto refresh = [&](auto *u){
		u->sz = (u->l ? u->l->sz : 0) + (u->r ? u->r->sz : 0) + 1;
	};
	treap tr(0, push, refresh);
	typedef treap<decltype(push), decltype(refresh), int, int> Treap;
	long long res = 0;
	for(auto f = 0; f < mxf; ++ f){
		static vector<array<int, 2>> cur;
		cur.clear();
		tr.root = 0;
		for(auto g = max(0, f - k); g < min(mxf, f + k + 1); ++ g){
			if(f != g){
				for(auto p: a[g]){
					cur.push_back(p);
				}
			}
		}
		sort(cur.begin(), cur.end());
		for(auto [rad, x]: a[f]){
			while(!cur.empty() && (cur.back()[0] > rad || cur.back()[0] == rad && cur.back()[1] > x)){
				int y = cur.back()[1];
				cur.pop_back();
				tr.root = tr.insert(tr.root, new Treap::node(y, 0));
			}
			Treap::node *a, *b, *c;
			tie(a, b) = tr.split(tr.root, x - rad);
			tie(b, c) = tr.split(b, x + rad + 1);
			res += tr.get_sz(b);
			tr.root = tr.merge(tr.merge(a, b), c);
			tr.root = tr.insert(tr.root, new Treap::node(x, 0));
		}
	}
	cout << res;
	return 0;
}

/*

*/

////////////////////////////////////////////////////////////////////////////////////////
//                                                                                    //
//                                   Coded by Aeren                                   //
//                                                                                    //
////////////////////////////////////////////////////////////////////////////////////////