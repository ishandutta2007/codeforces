#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,popcnt,sse4.1,sse4.2,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<int, int>;
using vi = vector<ll>;
using vvi = vector<vi>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 1<<18, mod = 1e9 + 7 , lg = 19;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct node {
	ll sm;
	node *l, *r;
	node(ll x = 0) : sm(x) {}
};
using pnode = node*;
deque<node> buffer;
pnode newnode(ll x = 0) {
	buffer.emplace_back(x);
	return &buffer.back();
}
pnode merge(pnode a, pnode b) {
	pnode r = newnode(a->sm + b->sm);
	r->l = a, r->r = b;
	return r;
}
pnode build(int l, int r) {
	if(l == r) return newnode(0);
	int mid = (l+r)>>1;
	return merge(build(l, mid), build(mid+1, r));
}
pnode upd(int i, ll x, int l, int r, pnode rt) {
	if(i < l || i > r) return rt;
	if(l == r) return newnode(x);
	int mid = (l+r)>>1;
	return merge(upd(i, x, l, mid, rt->l), upd(i, x, mid+1, r, rt->r));
}
ll get(int ql, int qr, int l, int r, pnode rt) {
	if(r < ql || qr < l) return 0;
	if(ql <= l && r <= qr) return rt->sm;
	int mid = (l+r)>>1;
	return get(ql, qr, l, mid, rt->l) + get(ql, qr, mid+1, r, rt->r);
}
map<int, vector<array<int, 3>>> upds;
int moment[maxn], sz = 0;
pnode rtk[maxn], rtb[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int x1, x2, y1, a, b, y2, i = 0; i < n; i++) {
		cin >> x1 >> x2 >> y1 >> a >> b >> y2;
		upds[0].pb({i+1, 0, y1});
		upds[x1+1].pb({i+1, a, b});
		upds[x2+1].pb({i+1, 0, y2});
	}
	rtk[0] = build(1, n);
	rtb[0] = build(1, n);
	for(auto i : upds) {
		moment[sz] = i.first;
		for(auto j : i.second) {
			rtk[sz] = upd(j[0], j[1], 1, n, rtk[sz]);
			rtb[sz] = upd(j[0], j[2], 1, n, rtb[sz]);
		}
		sz++;
		rtk[sz] = rtk[sz-1];
		rtb[sz] = rtb[sz-1];
	}
	int m, l, r, x;
	ll lst = 0;
	cin >> m;
	while(m--) {
		cin >> l >> r >> x;
		x = (x+lst)%1000000000;
		int d = upper_bound(moment, moment+sz, x)-moment-1;
		cout << (lst = get(l, r, 1, n, rtk[d])*1ll*x + get(l, r, 1, n, rtb[d])) << '\n';
	}
}