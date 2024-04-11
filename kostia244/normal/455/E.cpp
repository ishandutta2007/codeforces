#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,sse4.1")
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 1<<17;
using func = array<ll, 2>;
ll eval(const func &f, ll x){
	return f[0] + x*f[1];
}
struct node {
	node *l = 0, *r = 0;
	func f{};
};
using pnode = node*;
deque<node> buffer;
pnode newnode() {
	buffer.emplace_back();
	return &buffer.back();
}
void add(func f, pnode &rt, int l, int r) {
	if(l > r) return;
	if(!rt) {
		rt = newnode();
		rt->f = f;
		return;
	}
	int mid = l + (r-l+1)/2;
	if(eval(rt->f, mid) > eval(f, mid)) swap(rt->f, f);
	if(eval(f, l) < eval(rt->f, l)) add(f, rt->l, l, mid);
	else add(f, rt->r, mid+1, r);
}
ll get(ll x, pnode rt, int l, int r) {
	if(!rt) return 1ll<<60;
	ll cur = eval(rt->f, x);
	int mid = l + (r-l+1)/2;
	if(x <= mid) cur = min(cur, get(x, rt->l, l, mid));
	else cur = min(cur, get(x, rt->r, mid+1, r));
	return cur;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll n, m, x, y, inf = 1e5 + 33;
	cin >> n;
	vector<ll> a(n), pre(n);
	vector<pnode> fuck(2*n, 0);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		pre[i] += a[i];
		if(i) pre[i] += pre[i-1];
		for(int j = i+n; j; j>>=1) add({-pre[i]+a[i]*(i+1), a[i]}, fuck[j], -inf, inf);
	}
	for(int i = (cin >> m, 0); i < m; i++) {
		cin >> x >> y;y--;
		ll ans = 1ll<<60;
		for(int r = n+y+1, l = n+y-x+1; l < r; l>>=1, r>>=1) {
			if(l&1) ans = min(ans, get(x-y-1, fuck[l++], -inf, inf)+pre[y]);
			if(r&1) ans = min(ans, get(x-y-1, fuck[--r], -inf, inf)+pre[y]);
		}
		cout << ans << '\n';
	}

}