#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using int128 = unsigned __int128;
const int maxn = 1<<19;
struct ctx {
	int ans = -69;
	int cl = -1, cr = -1;
	int l = 0, r = 0;
	int pref = 0, suf = 0;
	int sorted = 0;
	ctx() {}
	ctx(char c) {
		cl = cr = c == '<';
		l = r = suf = pref = sorted = ans = 1;
	}
};
ctx merge(ctx a, ctx b) {
	if(a.cl == -1) return b;
	if(b.cl == -1) return a;
	ctx res;
	res.ans = max(a.ans, b.ans);
	res.cl = a.cl;
	res.cr = b.cr;
	res.pref = a.pref;
	res.suf = b.suf;
	res.l = b.l;
	res.r = a.r;
	res.sorted = a.sorted&&b.sorted&&a.cr<=b.cl;
	if(a.sorted && a.cl == a.cr) {
		res.l += (a.cr == b.cl)*b.l;
	}
	if(b.sorted && b.cl == b.cr) {
		res.r += (a.cr == b.cl)*a.r;
	}
	if(a.cr <= b.cl) {
		res.ans = max(res.ans, a.suf + b.pref);
		res.pref += a.sorted*b.pref;
		res.suf += b.sorted*a.suf;
	}
	return res;
}
struct node {
	ctx norm, inv;
	int lazy = 0;
};
int n, q;
string s;
node tree[maxn*4];
void push(int v, int l, int r) {
	if(tree[v].lazy) {
		swap(tree[v].norm, tree[v].inv);
		if(l != r) {
			tree[2*v].lazy ^= tree[v].lazy;
			tree[2*v+1].lazy ^= tree[v].lazy;
		}
		tree[v].lazy = 0;	
	}
}
void merge(int v) {
	tree[v].norm = merge(tree[2*v].norm, tree[2*v+1].norm);
	tree[v].inv = merge(tree[2*v].inv, tree[2*v+1].inv);
}
void upd(int v, int l, int r, int ql, int qr) {
	push(v, l, r);
	if(l > qr || ql > r) return;
	if(ql <= l && r <= qr) {
		tree[v].lazy ^= 1;
		push(v, l, r);
		return;
	}
	int mid = (l+r)/2;
	upd(2*v, l, mid, ql, qr);
	upd(2*v+1, mid+1, r, ql, qr);
	merge(v);
}
ctx get(int v, int l, int r, int ql, int qr) {
	push(v, l, r);
	if(l > qr || ql > r) return ctx();
	if(ql <= l && r <= qr) return tree[v].norm;
	int mid = (l+r)/2;
	return merge(get(2*v, l, mid, ql, qr), get(2*v+1, mid+1, r, ql, qr));
}
void build(int v, int l, int r) {
	if(l == r) {
		tree[v].norm = ctx(s[l]);
		tree[v].inv = ctx(s[l]^'<'^'>');
		return;
	}
	int mid = (l+r)/2;
	build(2*v, l, mid);
	build(2*v+1, mid+1, r);
	merge(v);
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> q >> s;
	s = " " + s;
	build(1, 1, n);
	for(int l, r; q--;) {
		cin >> l >> r;
		upd(1, 1, n, l, r);
		ctx t = get(1, 1, n, l, r);
		//cout << t.ans << " " << t.cl << " " << t.cr << " " << t.pref << " " << t.suf << " "
		cout << t.ans << '\n';
	}
	return 0;
}