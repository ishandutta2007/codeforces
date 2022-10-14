#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const int maxn = 1<<18, mod = 1e9 + 7;
struct node {
	ll pr, su, ans, ds;
	node(ll x = -(1ll<<50)) : pr(x), su(x), ans(x), ds(0) {}
};
node res;
node merge(node l, node r, ll x) {
	res.ds = l.ds + r.ds + x;
	res.pr = max(l.pr, l.ds + x + r.pr);
	res.su = max(l.su + x + r.ds, r.su);
	res.ans = max({l.ans, r.ans, l.su + x + r.pr});
	return res;
}
ll n, q, h[maxn], d[maxn];
node tree[4*maxn];
void build(int v, int l, int r) {
	if(l == r) {
		tree[v] = node(h[l]);
	} else {
		int mid = (l+r)/2;
		build(2*v, l, mid);
		build(2*v+1, mid+1, r);
		tree[v] = merge(tree[2*v], tree[2*v+1], d[mid]);
	}
}
node get(int ql, int qr, int v, int l, int r) {
	if(qr < l || r < ql) return node();
	if(ql <= l && r <= qr) return tree[v];
	int mid = (l+r)/2;
	return merge(
		get(ql, qr, 2*v, l, mid),
		get(ql, qr, 2*v+1, mid+1, r),
		d[mid]);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> q;
	for(int i = 1; i <= n; i++)
		cin >> d[i], d[n+i] = d[i];
	for(int i = 1; i <= n; i++)
		cin >> h[i], h[i] *= 2, h[n+i] = h[i];
	build(1, 1, 2*n);
	for(int l, r; q--;) {
		cin >> l >> r;
		if(r < l) {
			cout << get(r+1, l-1, 1, 1, 2*n).ans << '\n';
		} else {
			cout << get(r+1, n+l-1, 1, 1, 2*n).ans << '\n';
		}
	}
}