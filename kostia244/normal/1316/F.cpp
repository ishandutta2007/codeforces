#include<bits/stdc++.h>
#define data lol
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 1<<19, mod = 1e9 + 7;
const ll i2 = (mod+1)/2;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int ipw[maxn];
struct data {
	int cnt, val, pre, suf;
	data(int x) : cnt(1), val(0), pre(x*i2%mod), suf(x*i2%mod) {};
	data() : cnt(0), val(0), pre(0), suf(0) {};
	friend data operator+(data a, data b) {
		data c;
		c.cnt = a.cnt + b.cnt;
		c.val = (a.val + b.val + a.suf*1ll*b.pre)%mod;
		c.pre = (a.pre + b.pre*1ll*ipw[a.cnt])%mod;
		c.suf = (b.suf + a.suf*1ll*ipw[b.cnt])%mod;
		return c;
	}
};
struct node {
	int key, pri;
	data d;
	node *l, *r;
	node(int x = 0) : pri(rng()), key(x), d(x), l(0), r(0) {}
};
using pnode = node*;
deque<node> buffer;
pnode makenode(int x) {
	buffer.emplace_back(x);
	return &buffer.back();
}
data get_data(pnode v) { return v?v->d:data(); }
void update(pnode v) {
	v->d = get_data(v->l) + data(v->key) + get_data(v->r);
}
pnode merge(pnode x, pnode y) {
	if(!x||!y) return x?:y;
	if(x->pri > y->pri) {
		x->r = merge(x->r, y);
		update(x);
		return x;
	}
	y->l = merge(x, y->l);
	update(y);
	return y;
}
array<pnode, 2> split(pnode x, int k) {//<k | >k
	if(!x) return {0, 0};
	if(x->key <= k) {
		auto [l, r] = split(x->r, k);
		x->r = l;
		update(x);
		return array{x, r};
	}
	auto [l, r] = split(x->l, k);
	x->l = r;
	update(x);
	return array{l, x};
}
pnode erase_(pnode x, int v) {
	if(!x) return 0;
	if(x->key == v) return merge(x->l, x->r);
	if(x->key < v) {
		x->r = erase_(x->r, v);
		update(x);
	} else {
		x->l = erase_(x->l, v);
		update(x);
	}
	return x;
}
void erase(pnode &r, int x) {
	r = erase_(r, x);
}
void insert(pnode &r, int x) {
	auto [a, b] = split(r, x);
	r = merge(a, merge(makenode(x), b));
}

int n, m, p[maxn];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	clog.tie(&cerr)->sync_with_stdio(1);//super optimization
	ipw[0] = 1;
	for(int i = 1; i < maxn; i++) ipw[i] = ipw[i-1]*i2%mod;
	cin >> n;
	pnode root = 0;
	for(int i = 1; i <= n; i++) cin >> p[i], insert(root, p[i]);
	cout << get_data(root).val << '\n';
	cin >> m;
	for(int f, x, i = 0; i < m; i++) {
		cin >> f >> x;
		erase(root, p[f]);
		insert(root, p[f] = x);
		cout << get_data(root).val << '\n';
	}
}