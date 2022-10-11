//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll lg = 31;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()
#define lc (id << 1)
#define rc (id << 1 | 1)

struct node{
	ll mn, cnt[lg], lz;
	node(){
		mn = 0;
		lz = 0;
		fill(cnt, cnt + lg, 0);
	}
	void operator+=(ll x){
		mn += x;
		lz += x;
		return;
	}
};

ll n, k, q, cnt[lg];
pair<pll, pll> b[maxn];
node seg[maxn << 2];
vector<ll> vec, v2;
vector<pair<pll, ll> > g[maxn];

ll cal(ll x, ll y){
	return ((x + (1 << y)) >> (y + 1)) & 1;
}

void bld(ll id, ll s, ll e){
	if(e - s == 1){
		seg[id].mn = 0;
		for(ll i = 0; i < lg; i++){
			seg[id].cnt[i] = cal(vec[e], i) - cal(vec[s], i);
		}
		return;
	}
	ll mid = (s + e) >> 1;
	bld(lc, s, mid);
	bld(rc, mid, e);
	seg[id].mn = min(seg[lc].mn, seg[rc].mn);
	for(ll i = 0 ; i < lg; i++){
		seg[id].cnt[i] = 0;
		if(seg[id].mn == seg[lc].mn) seg[id].cnt[i] += seg[lc].cnt[i];
		if(seg[id].mn == seg[rc].mn) seg[id].cnt[i] += seg[rc].cnt[i];
		seg[id].cnt[i] &= 1;
	}
	return;
}
void upd(ll id, ll s, ll e, ll l, ll r, ll x){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		seg[id] += x;
		return;
	}
	ll mid = (s + e) >> 1;
	seg[lc] += seg[id].lz;
	seg[rc] += seg[id].lz;
	seg[id].lz = 0;
	upd(lc, s, mid, l, r, x);
	upd(rc, mid, e, l, r, x);
	seg[id].mn = min(seg[lc].mn, seg[rc].mn);
	for(ll i = 0 ; i < lg; i++){
		seg[id].cnt[i] = 0;
		if(seg[id].mn == seg[lc].mn) seg[id].cnt[i] += seg[lc].cnt[i];
		if(seg[id].mn == seg[rc].mn) seg[id].cnt[i] += seg[rc].cnt[i];
		seg[id].cnt[i] &= 1;
	}
	return;
}


int main(){
    fast_io;

	cin >> n >> q >> k;

	for(ll i = 0; i < q; i++){
		cin >> b[i].F.F >> b[i].F.S >> b[i].S.F >> b[i].S.S;
		vec.pb(b[i].F.S - 1);
		vec.pb(b[i].S.S);
		v2.pb(b[i].F.F - 1);
		v2.pb(b[i].S.F);
	}
	vec.pb(0);
	vec.pb(n);
	sort(all(vec));
	vec.resize(unique(all(vec)) - vec.begin());
	ll N = Sz(vec) - 1;
	bld(1, 0, N);
	sort(all(v2));
	v2.resize(unique(all(v2)) - v2.begin());
	for(ll i = 0; i < q; i++){
		ll x = lower_bound(all(v2), b[i].F.F - 1) - v2.begin();
		ll y = lower_bound(all(v2), b[i].S.F) - v2.begin();
		ll x2 = lower_bound(all(vec), b[i].F.S - 1) - vec.begin();
		ll y2 = lower_bound(all(vec), b[i].S.S) - vec.begin();
		g[x].pb(Mp(Mp(x2, y2), 1));
		g[y].pb(Mp(Mp(x2, y2), -1));
	}
	ll prv = 0;
	ll t = 0;
	while((1 << (t + 1)) <= k) t++;
	for(ll i = 0; i < Sz(v2); i++){
		node p = seg[1], d;
		for(ll j = 0; j < lg; j++){
			if(p.mn == 0) p.cnt[j] = cal(n, j) - p.cnt[j];
			else p.cnt[j] = cal(n, j);
			d.cnt[j] = cal(v2[i], j) - cal(prv, j);
		}
		ll x = 0, y = 0;
		for(ll j = lg; j--;){
			x += p.cnt[j];
			x &= 1;
			cnt[min(j, t)] += (d.cnt[j] * x + p.cnt[j] * y) & 1;
			y += d.cnt[j];
			y &= 1;
		}
		for(auto j : g[i]){
			upd(1, 0, N, j.F.F, j.F.S, j.S);
		}
		prv = v2[i];
	}
	for(ll i = 0; i < lg; i++){
		if(cnt[i] & 1){
			cout << "Hamed";
			return 0;
		}
	}
	cout << "Malek";

    return 0;
}