#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,sse4.1")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
#define apply fuckstl
#define int long long
using namespace std;
using ll = int64_t;
const int maxn = 1<<19, mod = 1000000007;
struct node {
	ll sum, mn;
	array<ll, 2> lazy;
	node(ll x = 0) : sum(x), mn(x), lazy{0, 1} {}
};//{const, coef}
node tree[4*maxn];
void apply(int v, array<ll, 2> upd) {
	tree[v].lazy[0] *= upd[1];
	tree[v].lazy[1] *= upd[1];
	tree[v].lazy[0] += upd[0];
}
void push(int v, int l, int r) {
	tree[v].sum = tree[v].sum*tree[v].lazy[1] + tree[v].lazy[0]*(r-l+1);
	tree[v].mn = tree[v].mn*tree[v].lazy[1] + tree[v].lazy[0];
	if(l != r) {
		apply(2*v, tree[v].lazy);
		apply(2*v+1, tree[v].lazy);
	}
	tree[v].lazy = {0, 1};
}
node merge(node a, node b) {
	node c;
	c.sum = a.sum + b.sum;
	c.mn = min(a.mn, b.mn);
	return c;
}
void update(int ql, int qr, array<ll, 2> upd, int v, int l, int r) {
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
int n;
string s;
int32_t main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> s;
	int lst0 = -1;
	ll ans = 0;
	for(int i = 0; i < n; i++) {
		if(s[i] == '0') {
			lst0 = i;
			ans += tree[1].sum;
			//dfs(1, 0, n-1);cout << '\n';
			continue;
		}
		update(lst0+1, i, {1, 1}, 1, 0, n-1);
		int streak = i-lst0;
		int pos = find(streak, 1, 0, n-1);
		if(pos != -1 && pos <= lst0) {
			update(pos, lst0, {streak, 0}, 1, 0, n-1);
		}
		ans += tree[1].sum;
		//dfs(1, 0, n-1);cout << '\n';
	}
	cout << ans << '\n';
}