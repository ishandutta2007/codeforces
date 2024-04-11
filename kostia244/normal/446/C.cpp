#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<int>;
const int maxn = 3e5 + 33;
const int mod = 1e9 + 9;
const int r5 = 383008016, invr5 = 276601605, phi = 691504013, invphi = 691504012,
		phi2 = 308495997, invphi2 = 308495996;
int add(int a) {
	if(a<0) a+=mod;
	return a;
}
template<typename... T>
int add(int a, T... args) {
	if(a<0) a+=mod;
	a += add(args...);
	if(a>=mod) a-=mod;
	return a;
}
int mul(int a) {
	return a;
}
template<typename... T>
int mul(int a, T... args) {
	return (a*1ll*mul(args...))%mod;
}

struct node {
	int cur=0, lazy=0;
};
node merge(node a, node b) {
	a.cur = add(a.cur, b.cur);
	return a;
}
#define gol(x) ((x)<<1)
#define gor(x) ((x)<<1|1)
struct segtree {
	int n, r, inv;
	node t[4*maxn];
	int pw[maxn], g[maxn];
	segtree(int n, int r, int inv) : n(n), r(r), inv(inv) {
		pw[0] = g[0] = 1;
		for(int i = 1; i < n+3; i++) {
			pw[i] = mul(pw[i-1], r);
			g[i] = add(g[i-1], pw[i]);
		}
	}
	int geo(int x, int n) {
		return mul(x,g[n-1]);
	}
	void push(int v, int l, int r) {
		if(!t[v].lazy) return;
		t[v].cur = add(t[v].cur, geo(t[v].lazy, r-l+1));
		if(l!=r) {
			t[gol(v)].lazy = add(t[gol(v)].lazy, t[v].lazy);
			t[gor(v)].lazy = add(t[gor(v)].lazy, mul(t[v].lazy, pw[((l+r)>>1)+1-l]));
		}
		t[v].lazy = 0;
	}
	void upd(int v, int l, int r, int ql, int qr, int c) {
		push(v, l, r);
		if(r<ql||l>qr) return;
		if(ql <= l && r <= qr) {
			t[v].lazy = add(t[v].lazy, mul(pw[l-ql], c));
			push(v, l, r);
			return;
		}
		int mid = (l+r)>>1;
		upd(gol(v), l, mid, ql, qr, c);
		upd(gor(v), mid+1, r, ql, qr, c);
		t[v] = merge(t[gol(v)], t[gor(v)]);
	}
	void upd(int l, int r, int c) {
		upd(1, 1, n, l, r, c);
	}
	node get(int v, int l, int r, int ql, int qr) {
		push(v, l, r);
		if(r<ql||l>qr) return node();
		if(ql <= l && r <= qr) {
			return t[v];
		}
		int mid = (l+r)>>1;
		return merge(get(gol(v), l, mid, ql, qr), get(gor(v), mid+1, r, ql, qr));
	}
	int get(int l, int r) {
		return get(1, 1, n, l, r).cur;
	}
};
int n, m, a[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i] = add(a[i], a[i-1]);
	}
	segtree x(n, phi, invphi2), y(n, phi2, invphi);
	int t, l, r;
	while(m--) {
		cin >> t >> l >> r;
		if(t==2) {
			cout << add(mul(invr5, add(x.get(l, r), -y.get(l, r))), add(a[r], -a[l-1])) << "\n";
		} else {
			x.upd(l, r, phi);
			y.upd(l, r, phi2);
		}
	}
}