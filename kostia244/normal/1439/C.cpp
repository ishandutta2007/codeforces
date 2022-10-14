#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,sse4.1")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
#define apply fuckstl
using namespace std;
using ll = long long;
const int maxn = 1<<18, mod = 1000000007;
struct node {
	ll sum, mn, lazy;
	node(ll x = 0) : sum(x), mn(x), lazy(-1) {}
};//{const, coef}
node tree[4*maxn];
void apply(int v, ll upd) {
	tree[v].lazy = upd;
}
void push(int v, int l, int r) {
	if(tree[v].lazy == -1) return;
	tree[v].sum = (r-l+1)*tree[v].lazy;
	tree[v].mn = tree[v].lazy;
	if(l != r) {
		apply(2*v, tree[v].lazy);
		apply(2*v+1, tree[v].lazy);
	}
	tree[v].lazy = -1;
}
node merge(node a, node b) {
	node c;
	c.sum = a.sum + b.sum;
	c.mn = min(a.mn, b.mn);
	return c;
}
void update(int ql, int qr, ll upd, int v, int l, int r) {
	push(v, l, r);
	if(qr < l || r < ql) return;
	if(ql <= l && r <= qr) {
		apply(v, upd);
		push(v, l, r);
		return;
	}
	int mid = (l+r)/2;
	update(ql, qr, upd, 2*v, l, mid);
	update(ql, qr, upd, 2*v+1, mid+1, r);
	tree[v] = merge(tree[2*v], tree[2*v+1]);
}

int find(int k, int v, int l, int r) {
	push(v, l, r);
	if(tree[v].mn > k) return -1;
	if(l == r) return l;
	int mid = (l+r)/2;
	int t = find(k, 2*v, l, mid);
	if(t != -1) return t;
	return find(k, 2*v+1, mid+1, r);
}
ll sim(int ql, ll &hv, int v, int l, int r) {
	push(v, l, r);
	if(r < ql) return r;
	if(l == r) {
		//cout << l << " - " << tree[v].sum << endl;
		if(hv >= tree[v].sum) {hv -= tree[v].sum; return l;}
		return l-1;
	}
	if(ql <= l && hv >= tree[v].sum) {hv -= tree[v].sum; return r;}
	//cout << (l==r) << " " << hv << endl;
	int mid = (l+r)/2;
	ll t = sim(ql, hv, 2*v, l, mid);
	if(t == mid) t = sim(ql, hv, 2*v+1, mid+1, r);
	return t;
}
void dfs(int v, int l, int r) {
	push(v, l, r);
	if(l == r) {
		cout << tree[v].sum << " ";
		return;
	}
	int mid = (l+r)/2;
	dfs(2*v, l, mid);
	
	dfs(2*v+1, mid+1, r);
}
int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, q;
	cin >> n >> q;
	for(int t, i = 1; i <= n; i++) {
		cin >> t;
		update(i, i, t, 1, 1, n);
	}
	for(ll t, x, y; q--;) {
		cin >> t >> x >> y;
		if(t== 1) {
			int p = find(y, 1, 1, n);
			if(p != -1) {
				update(p, x, y, 1, 1, n);
			}
		} else {
			int ans = 0;
			while(tree[1].mn <= y && x <= n) {
				int pos = max((int)x, find(y, 1, 1, n));
				int nx = 1+sim(pos, y, 1, 1, n);
				ans += nx-pos;
				//cout << pos << " " << nx << " " << y << endl;
				x = nx;
			}
			cout << ans << '\n';
		}
		//dfs(1, 1, n);cout << '\n';
	}
}