#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,sse4.1")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct node {
	int key, pri, cnt, mx, lazy;
	node *l, *r;
	node(int k = 0) : key(k), pri(rng()), cnt(1), l(0), r(0), mx(k), lazy(0) {}
};
using pnode = node*;
int cnt(pnode v) { return v?v->cnt:0;}
int mx(pnode v) { return v?v->mx:(-(1<<30));}
void push(pnode v) {
	if(!v) return;
	v->key += v->lazy;
	if(v->l) v->l->lazy += v->lazy;
	if(v->r) v->r->lazy += v->lazy;
	v->lazy = 0;
}
void upd(pnode v) {
	if(!v) return;
	v->cnt = 1 + cnt(v->l) + cnt(v->r);
	v->mx = max({v->key, mx(v->l), mx(v->r)});
}
pnode merge(pnode a, pnode b) {
	push(a), push(b);
	if(!a||!b) return a?:b;
	if(a->pri < b->pri) {
		a->r = merge(a->r, b);
		upd(a);
		return a;
	}
	b->l = merge(a, b->l);
	upd(b);
	return b;
}
template<bool implicit>
array<pnode, 2> split(pnode v, int k) {
	push(v);
	if(!v) return {0, 0};
	if(implicit ? (1+cnt(v->l)>=k) : (v->key>=k)) {
		auto [x, y] = split<implicit>(v->l, k);
		v->l = y, upd(v);
		return {x, v};
	}
	auto [x, y] = split<implicit>(v->r, k + implicit*(-cnt(v->l)-1));
	v->r = x, upd(v);
	return {v, y};
}
pnode erase(pnode v, int x) {
	push(v);
	if(!v) return 0;
	if(v->key == x) return merge(v->l, v->r);
	if(v->key > x) {
		v->l = erase(v->l, x), upd(v);
		return v;
	}
	v->r = erase(v->r, x), upd(v);
	return v;
}
 
deque<node> buffer;
pnode newnode(int k) {
	buffer.emplace_back(k);
	return &buffer.back();
}
template<int imp>
array<pnode, 3> split(pnode v, int a, int b) {//[a;b]
	auto [s, t] = split<imp>(v, b+1);
	auto [p, q] = split<imp>(s, a);//p, q, t
	return {p, q, t};
}
void print(pnode r) {
	if(!r) return;
	push(r);
	print(r->l);
	cout << r->key << " ";
	print(r->r);
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n;
	cin >> n;
	pnode rt = 0;
	for(int l, r, i = 0; i < n; i++) {
		cin >> l >> r;
		auto [T, Z] = split<0>(rt, r);
		auto [X, Y] = split<0>(T, l);
		if(Z) Z = split<1>(Z, 2)[1];
		if(Y) Y->lazy++;
		X = merge(X, newnode(l));
		X = merge(X, Y);
		rt = merge(X, Z);
	}
	cout << cnt(rt) << '\n';
}