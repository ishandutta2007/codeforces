#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
const int maxn = 1<<18;
using node = array<ll, 6>;
int lk[3][3];
node operator+(const node &a, const node &b) {
	node c{};
	for(int i = 0; i < 3; i++)
		for(int j = i; j < 3; j++)
			c[lk[i][j]] = max(a[lk[i][j]], b[lk[i][j]]);
	for(int i = 0; i < 3; i++)
		for(int j = i; j < 3; j++)
			for(int k = j+1; k < 3; k++)
				c[lk[i][k]] = max(c[lk[i][k]], a[lk[i][j]]+b[lk[j+1][k]]);
	return c;
}
int n, q, M, tin[maxn], tout[maxn];
ll w;
ll cur[maxn], lazy[maxn*4];
vector<array<ll, 2>> ed, g[maxn];
node tree[maxn*4], tour[maxn*2];
void upd(int v, ll x) {
	node c;
	c[lk[0][0]] = c[lk[2][2]] = x;
	c[lk[1][1]] = -2*x;
	c[lk[0][1]] = c[lk[1][2]] = -x;
	c[lk[0][2]] = 0;
	tour[v] = c;
}
int timer = 0;
void dfs(int v, int p, ll d) {
	tin[v] = timer;
	upd(timer++, d);
	for(auto &[i, w] : g[v]) if(i != p) {
		dfs(i, v, d + w);
		upd(timer++, d);
	}
	tout[v] = timer;
}
void build(int v, int l, int r) {
	if(l == r) {
		tree[v] = tour[l];
		return;
	}
	int mid = (l+r)/2;
	build(2*v, l, mid);
	build(2*v+1, mid+1, r);
	tree[v] = tree[v*2] + tree[2*v+1];
}
void apply(int v, int l, int r, ll x) {
	lazy[v] += x;
	tree[v][lk[0][0]] += x;
	tree[v][lk[0][1]] -= x;
	tree[v][lk[0][2]] += 0;
	tree[v][lk[1][1]] -= 2*x;
	tree[v][lk[1][2]] -= x;
	tree[v][lk[2][2]] += x;
}
void push(int v, int l, int r, int m) {
	if(l != r) {
		apply(2*v, l, m, lazy[v]);
		apply(2*v+1, m+1, r, lazy[v]);
		lazy[v] = 0;
	}
}
void update(int ql, int qr, ll x, int v, int l, int r) {
	if(r < ql || qr < l) return;
	int mid = (l+r)/2;
	if(ql <= l && r <= qr) {
		apply(v, l, r, x);
		push(v, l, r, mid);
		return;
	}
	push(v, l, r, mid);
	update(ql, qr, x, 2*v, l, mid);
	update(ql, qr, x, 2*v+1, mid+1, r);
	tree[v] = tree[2*v] + tree[2*v + 1];
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	for(int c = 0, i = 0; i < 3; i++)
		for(int j = i; j < 3; j++)
			lk[i][j] = c++;
	cin >> n >> q >> w;
	for(ll f, t, x, i = 0; i+1 < n; i++) {
		cin >> f >> t >> x;
		cur[i] = x;
		ed.push_back({f, t});
		g[f].push_back({t, x});
		g[t].push_back({f, x});
	}
	dfs(1, 0, 0);
	M = 2*n-1;
	build(1, 0, M);
	for(auto &[x, y] : ed) if(tin[x]>tin[y]) swap(x, y);
	ll id, v, x, ans = 0;
	while(q--) {
		cin >> v >> x;
		v = ed[id = (ans+v)%(n-1)][1];
		x = (ans+x)%w;
		update(tin[v], tout[v]-1, -cur[id], 1, 0, M);
		update(tin[v], tout[v]-1, cur[id] = x, 1, 0, M);
		cout << (ans = tree[1][lk[0][2]]) << '\n';
	}
	return 0;
}