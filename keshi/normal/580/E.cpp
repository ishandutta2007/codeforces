//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef __uint128_t L;
struct FastMod {
	ull b, m;
	FastMod(ull b) : b(b), m(ull((L(1) << 64) / b)) {}
	ull od(ull a) {
		ull q = (ull)((L(m) * a) >> 64);
		ull r = a - q * b; // can be proven that 0 <= r < 2*b
		return r >= b ? r - b : r;
	}
};

typedef long long ll;

const ll maxn = 1e6 + 100;
const ll cmod = 2;
const ll mod[cmod] = {1000000007, 1000000009};
const ll inf = 1e18;
FastMod M[cmod] = {FastMod(mod[0]), FastMod(mod[1])};

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, k, p[cmod][maxn], p2[cmod][maxn], seg[cmod][maxn], lz[cmod][maxn];

ll pw(ll mo, ll pa, ll pb){
	if(pb == 0) return 1;
	ll pc = pw(mo, pa, pb / 2);
	pc = M[mo].od(pc * pc);
	if(pb & 1) pc = M[mo].od(pc * pa);
	return pc;
}

void dj(ll mo, ll id, ll s, ll e, ll x){
	lz[mo][id] = x;
	seg[mo][id] = M[mo].od(M[mo].od((p[mo][e - s] - 1) * p2[mo][1]) * x);
	return;
}

void upd(ll mo, ll id, ll s, ll e, ll l, ll r, ll x){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		dj(mo, id, s, e, x);
		return;
	}
	ll mid = (s + e) / 2;
	if(lz[mo][id] != -1){
		dj(mo, id * 2, s, mid, lz[mo][id]);
		dj(mo, id * 2 + 1, mid, e, lz[mo][id]);
		lz[mo][id] = -1;
	}
	upd(mo, id * 2, s, mid, l, r, x);
	upd(mo, id * 2 + 1, mid, e, l, r, x);
	seg[mo][id] = M[mo].od(seg[mo][id * 2] * p[mo][e - mid] + seg[mo][id * 2 + 1]);
	return;
}
ll get(ll mo, ll id, ll s, ll e, ll l, ll r){
	if(r <= s || e <= l) return 0;
	if(l <= s && e <= r) return M[mo].od(seg[mo][id] * p[mo][r - e]);
	ll mid = (s + e) / 2;
	if(lz[mo][id] != -1){
		dj(mo, id * 2, s, mid, lz[mo][id]);
		dj(mo, id * 2 + 1, mid, e, lz[mo][id]);
		lz[mo][id] = -1;
	}
	return M[mo].od(get(mo, id * 2, s, mid, l, r) + get(mo, id * 2 + 1, mid, e, l, r));
}

int main(){
	fast_io;
	ll t, l, r, d;
	char c;
	for(ll i = 0; i < cmod; i++){
		p[i][0] = 1;
		fill(lz[i], lz[i] + maxn, -1);
	}
	for(ll i = 1; i < maxn; i++){
		for(ll j = 0; j < cmod; j++){
			p[j][i] = M[j].od(p[j][i - 1] * 11);
			p2[j][i] = pw(j, p[j][i] - 1, mod[j] - 2);
		}
	}
	
	cin >> n >> m >> k;
	for(ll i = 0; i < n; i++){
		cin >> c;
		for(ll j = 0; j < cmod; j++){
			upd(j, 1, 0, n, i, i + 1, ll(c - '0') + 1);
		}
	}
	m += k;
	for(ll i = 0; i < m; i++){
		cin >> t >> l >> r >> d;
		l--;
		if(t == 1){
			for(ll j = 0; j < cmod; j++){
				upd(j, 1, 0, n, l, r, d + 1);
			}
		}
		else{
			bool ok = 1;
			for(ll j = 0; j < cmod; j++){
				if(get(j, 1, 0, n, l, r) != M[j].od(M[j].od(M[j].od(get(j, 1, 0, n, l, l + d) * (p[j][r - l - (r - l) % d] - 1)) * p2[j][d]) * p[j][(r - l) % d] + get(j, 1, 0, n, l, l + (r - l) % d))) ok = 0;
			}
			cout << (ok ? "YES\n" : "NO\n");
		}
	}
	
	return 0;
}