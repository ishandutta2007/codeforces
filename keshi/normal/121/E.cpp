//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

const ll maxn = 1e5 + 100;
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
#define rc (lc | 1)

ll n, q, a[maxn], seg[maxn << 2], lz[maxn << 2], nxt[maxn], fen[maxn];
bool ok[maxn];
set<ll> st;

void upd2(ll x, ll y){
	//cout << "# " << x << " " << y << "\n";
	for(x += 5; x < maxn; x += x & -x){
		fen[x] += y;
	}
	return;
}
ll get2(ll x){
	ll y = 0;
	for(x += 5; x > 0; x -= x & -x){
		y += fen[x];
	}
	return y;
}
void bld(ll id, ll s, ll e){
	if(e - s == 1){
		seg[id] = nxt[a[s]] - a[s];
		if(ok[a[s]]){
			st.insert(s);
			upd2(s, 1);
		}
		return;
	}
	ll mid = (s + e) >> 1;
	bld(lc, s, mid);
	bld(rc, mid, e);
	seg[id] = min(seg[lc], seg[rc]);
}
void upd(ll id, ll s, ll e, ll l, ll r, ll x){
	if(r <= s || e <= l) return;
	if(l <= s && e <= r){
		seg[id] -= x;
		lz[id] -= x;
		return;
	}
	seg[lc] += lz[id];
	lz[lc] += lz[id];
	seg[rc] += lz[id];
	lz[rc] += lz[id];
	lz[id] = 0;
	ll mid = (s + e) >> 1;
	upd(lc, s, mid, l, r, x);
	upd(rc, mid, e, l, r, x);
	seg[id] = min(seg[lc], seg[rc]);
	return;
}
void fix(ll id, ll s, ll e){
	if(seg[id] > 0) return;
	if(e - s == 1){
		a[s] = nxt[a[s]] - seg[id];
		if(ok[a[s]]){
			st.insert(s);
			upd2(s, 1);
		}
		seg[id] = nxt[a[s]] - a[s];
		return;
	}
	seg[lc] += lz[id];
	lz[lc] += lz[id];
	seg[rc] += lz[id];
	lz[rc] += lz[id];
	lz[id] = 0;
	ll mid = (s + e) >> 1;
	fix(lc, s, mid);
	fix(rc, mid, e);
	seg[id] = min(seg[lc], seg[rc]);
	return;
}

int main(){
    fast_io;
    
    nxt[10010] = inf;
    for(ll i = 10010; i--;){
    	ll x = i;
    	ok[i] = 1;
    	while(x){
    		if(x % 10 != 4 && x % 10 != 7) ok[i] = 0;
    		x /= 10;
		}
		if(ok[i + 1]) nxt[i] = i + 1;
		else nxt[i] = nxt[i + 1];
	}
	cin >> n >> q;
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	bld(1, 0, n);
	while(q--){
		string s;
		ll l, r;
		cin >> s >> l >> r;
		l--;
		if(s == "add"){
			ll x;
			cin >> x;
			upd(1, 0, n, l, r, x);
			auto it = st.lower_bound(l);
			while(it != st.end() && *it < r){
				upd2(*it, -1);
				it = st.erase(it);
			}
			fix(1, 0, n);
		}
		else{
			cout << get2(r - 1) - get2(l - 1) << "\n";
		}
	}
 
    return 0;
}