#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using namespace __gnu_pbds;
using ll = long long;
using vi = vector<ll>;
using vvi = vector<vector<ll>>;
const ll mod = (1e9 + 7);
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
struct node {
	ll mx, lazy=0;
	node(ll _mx = 0) {
		mx = _mx;
	}
};
node merge(node a, node b) {
	a.mx = max(a.mx, b.mx);
	a.lazy = 0;
	return a;
}
struct segtree {
	int n;
	vector<node> tree;
	void init(int sz) {
		n = sz;
		tree.assign(4*sz + 1, node());
	}
	void push(int v, int l, int r) {
		tree[v].mx += tree[v].lazy;
		if(l != r) {
			tree[v<<1].lazy += tree[v].lazy;
			tree[v<<1|1].lazy += tree[v].lazy;
		}
		tree[v].lazy = 0;
	}
	void set(int v, int l, int r, int i, ll x) {
		push(v, l, r);
		if(l > i || r < i) return;
		if(l == r) {
			tree[v] = x;
			return;
		}
		int mid = (l+r)>>1;
		set(v<<1, l, mid, i, x);
		set(v<<1|1, mid+1, r, i, x);
		tree[v] = merge(tree[v<<1], tree[v<<1|1]);
	}
	void set(int i, ll x) {
		set(1, 0, n, i, x);
	}
	void add(int v, int l, int r, int ql, int qr, ll x) {
		push(v, l, r);
		if(l > qr || r < ql) return;
		if(r <= qr && l >= ql) {
			tree[v].lazy += x;
			push(v,l,r);
			return;
		}
		int mid = (l+r)>>1;
		add(v<<1, l, mid, ql, qr, x);
		add(v<<1|1, mid+1, r, ql, qr, x);
		tree[v] = merge(tree[v<<1], tree[v<<1|1]);
	}
	void add(int l, int r, ll x) {
		add(1, 0, n, l, r, x);
	}
	node get(int v, int l, int r, int ql, int qr) {
		push(v, l, r);
		if(l > qr || r < ql) return node();
		if(l >= ql && r <= qr) {
			return tree[v];
		}
		int mid = (l+r)>>1;
		return merge(get(v<<1, l, mid, ql, qr), get(v<<1|1, mid+1, r, ql, qr));
	}
	ll get(int l, int r) {
		return get(1, 0, n, l, r).mx;
	}
};
int a[40000], dp[40000];
int n, k;
segtree x;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	x.init(n+5);
	for(int i = 0; i < k;i++) {
		for(int j = 1; j <= n; j++)
			x.set(j, dp[j-1]);
		x.set(0, 0);
		vi lst(n+1, -1);
		for(int j = 1; j <= n; j++) {
			x.add(lst[a[j]]+1, j, 1);
			lst[a[j]]=j;
			dp[j] = x.get(0, j);
		}
	}
	cout << dp[n];
}