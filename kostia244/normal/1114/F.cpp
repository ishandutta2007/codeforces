//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const ll mod = 1e9 + 7;
const ll inf = 1e18;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n, m, a[400100], pr[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41,
		43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113,
		127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193,
		197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271,
		277, 281, 283, 293 }, phi[70];
ll bp(ll a, ll p) {
	ll res = 1;
	while(p){
		if(p&1) res = (res*a)%mod;
		a = (a*a)%mod;
		p>>=1;
	}
	return res;
}
ll getmsk(ll _l) {
	ll msk = 0;
	if(_l>1) {
		for(int i = 0; i < 62; i++)
			if(_l%pr[i]==0)
				msk|=1ll<<i;
	}
	return msk;
}
struct node {
	ll msk, mul, lmsk, lmul;
	node(ll _l = 1) : mul(_l) {
		msk = getmsk(mul);
		cl();
	}
	void cl() {
		lmsk = 0, lmul = 1;
	}
};
node merge(node a, node b) {
	a.msk|=b.msk;
	a.mul = (a.mul*b.mul)%mod;
	a.cl();
	return a;
}
struct segtree {
	int n;
	vector<node> t;
	void init(int n) {
		this->n = n;
		t.resize(4*n+4);
		build(1, 1, n);
	}
	void build(int v, int l, int r) {
		if(l==r) {
			t[v] = node(a[l]);
			return;
		}
		int mid = (l+r)>>1;
		build(v<<1, l, mid);
		build(v<<1|1, mid+1, r);
		t[v] = merge(t[v<<1], t[v<<1|1]);
	}
	void push(int v, int l, int r) {
		t[v].msk|=t[v].lmsk;
		t[v].mul = (t[v].mul*bp(t[v].lmul, r-l+1))%mod;
		if(l!=r) {
			t[v<<1].lmsk|=t[v].lmsk;
			t[v<<1|1].lmsk|=t[v].lmsk;
			t[v<<1].lmul = (t[v<<1].lmul*t[v].lmul)%mod;
			t[v<<1|1].lmul = (t[v<<1|1].lmul*t[v].lmul)%mod;
		}
		t[v].cl();
	}
	void upd(int v, int l, int r, int ql, int qr, ll vl, ll msk) {
		push(v, l, r);
		if(r<ql||l>qr) return;
		if(ql<=l&&r<=qr) {
//			cerr << l << " " << r << " " << vl << " (" << msk << ")\n";
			t[v].lmsk|=msk;
			t[v].lmul=(t[v].lmul*vl)%mod;
			push(v,l,r);
			return;
		}
		int mid = (l+r)>>1;
		upd(v<<1, l, mid, ql, qr, vl, msk);
		upd(v<<1|1, mid+1, r, ql, qr, vl, msk);
		t[v] = merge(t[v<<1], t[v<<1|1]);
	}
	void upd(int l, int r, ll vl) {
		upd(1, 1, n, l, r, vl, getmsk(vl));
	}
	node get(int v, int l, int r, int ql, int qr) {
		push(v, l, r);
		if(r<ql||l>qr) return node();
		if(ql <= l && r <= qr) {
			return t[v];
		}
		int mid = (l+r)>>1;
		return merge(get(v<<1, l, mid, ql, qr), get(v<<1|1, mid+1, r, ql, qr));
	}
	ll get(ll l, ll r) {
		node t = get(1, 1, n, l, r);
		ll ans = t.mul;
//		cout << ans << "(\n";
		for(int i = 0; i < 62; i++)
			if(t.msk&(1ll<<i))
				ans = (ans*phi[i])%mod;
		return ans;
	}
};
segtree st;
int main() { //DINIC ORZ
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for(int i =0; i < 62; i++)
		phi[i] = ((pr[i]-1)*1ll*bp(pr[i], mod-2))%mod;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	st.init(n);
	string t;
	int l, r, x;
	while(m--) {
		cin >> t >> l >> r;
		if(t[0]=='T') {
			cout << st.get(l, r) << "\n";
		} else {
			cin >> x;
			st.upd(l, r, x);
		}
	}
}