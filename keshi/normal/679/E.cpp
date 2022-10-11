//In the name of God
#pragma GCC optimize("O2")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 1e5 + 100;
const ll maxk = 10;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

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

ll n, q, a[maxn], px[maxk], cnt, b[maxn];
bool vis[maxn << 2], vis2[maxn << 2];
pll lz[maxn << 2];
pll seg[maxn << 2];
pll sg[maxn << 2];
set<ll> st;

void bld(ll id, ll s, ll e){
	if(e - s == 1){
		sg[id].S = a[s];
		for(ll i = 0; i < maxk; i++){
			if(a[s] <= px[i]){
				seg[id] = Mp(px[i] - a[s], s);
				b[s] = px[i] - a[s];
				break;
			}
		}
		return;
	}
	ll mid = (s + e) >> 1;
	bld(lc, s, mid);
	bld(rc, mid, e);
	seg[id] = min(seg[lc], seg[rc]);
	return;
}
void Do(ll id, ll s, ll e, pll x){
	if(x.S){
		seg[id].F = x.S;
		seg[id].S = s;
		lz[id].S = x.S;
		lz[id].F = 0;
		vis[id] = 1;
		return;
	}
	if(vis[id]){
		seg[id].F += x.F;
		lz[id].S += x.F;
	}
	else{
		seg[id].F += x.F;
		lz[id].F += x.F;
	}
	return;
}
void push(ll id, ll s, ll e){
	ll mid = (s + e) >> 1;
	Do(lc, s, mid, lz[id]);
	Do(rc, mid, e, lz[id]);
	lz[id] = Mp(0, 0);
	vis[id] = 0;
	return;
}
void upd(ll id, ll s, ll e, ll l, ll r, pll x){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		Do(id, s, e, x);
		return;
	}
	ll mid = (s + e) >> 1;
	push(id, s, e);
	upd(lc, s, mid, l, r, x);
	upd(rc, mid, e, l, r, x);
	seg[id] = min(seg[lc], seg[rc]);
	return;
}
void Do2(ll id, pll x){
	if(x.S){
		sg[id] = Mp(0, x.S);
	}
	sg[id].F += x.F;
	return;
}
void upd2(ll id, ll s, ll e, ll l, ll r, pll x){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		Do2(id, x);
		return;
	}
	ll mid = (s + e) >> 1;
	Do2(lc, sg[id]);
	Do2(rc, sg[id]);
	sg[id] = Mp(0, 0);
	upd2(lc, s, mid, l, r, x);
	upd2(rc, mid, e, l, r, x);
	return;
}
ll get(ll id, ll s, ll e, ll l, ll r){
	if(r <= s || e <= l) return 0;
	if(l <= s && e <= r){
		return sg[id].S + sg[id].F;
	}
	ll mid = (s + e) >> 1;
	Do2(lc, sg[id]);
	Do2(rc, sg[id]);
	sg[id] = Mp(0, 0);
	return get(lc, s, mid, l, r) + get(rc, mid, e, l, r);
}

void fix(){
	while(seg[1].F < 0){
		ll x = seg[1].S;
		ll z = get(1, 0, n, x, x + 1);
		ll o = seg[1].F;
		ll y = *st.upper_bound(x);
		ll p = -1;
		for(ll i = 0; i < maxk; i++){
			if(px[i] == z + o){
				p = i;
			}
		}
		for(ll i = 0; i < maxk; i++){
			if(px[i] >= z){
				upd(1, 0, n, x, y, Mp(px[i] - px[p], 0));
				break;
			}
		}
	}
	return;
}

void Dob(ll l, ll r, ll x){
	st.insert(l);
	st.insert(r);
	upd(1, 0, n, l, r, Mp(-x, 0));
	upd2(1, 0, n, l, r, Mp(x, 0));
	fix();
	return;
}


int main(){
    fast_io;

	px[0] = 1;
	for(ll i = 1; i < maxk; i++){
		px[i] = px[i - 1] * 42;
	}
	cin >> n >> q;
	for(ll i = 0; i < n; i++){
		cin >> a[i];
		st.insert(i);
	}
	st.insert(n);
	bld(1, 0, n);
	for(ll i = 0; i < q; i++){
		ll t;
		cin >> t;
		if(t == 1){
			ll x;
			cin >> x;
			cout << get(1, 0, n, x - 1, x) << '\n';
		}
		else if(t == 2){
			ll l, r, x;
			cin >> l >> r >> x;
			l--;
			st.insert(l);
			st.insert(r);
			while(*st.upper_bound(l) < r){
				st.erase(st.upper_bound(l));
			}
			for(ll j = 0; j < maxk; j++){
				if(px[j] >= x){
					upd(1, 0, n, l, r, Mp(0, px[j] - x));
					break;
				}
			}
			upd2(1, 0, n, l, r, Mp(0, x));
		}
		else{
			ll l, r, x;
			cin >> l >> r >> x;
			l--;
			Dob(l, r, x);
			while(seg[1].F == 0){
				Dob(l, r, x);
			}
		}
	}

    return 0;
}