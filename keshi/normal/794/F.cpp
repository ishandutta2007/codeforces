//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 1e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define lc (id << 1)
#define rc (id << 1 | 1)

struct node{
    ll s, lz[10], val[10];
    node(){
        s = 0;
        for(ll i = 0; i < 10; i++){
            lz[i] = i;
            val[i] = 0;
        }
    }
};

ll n, q, a[maxn];
node seg[maxn << 2];

void bld(ll id, ll s, ll e){
    if(e - s == 1){
        seg[id].s = a[s];
        ll x = 1;
        while(a[s]){
            seg[id].val[a[s] % 10] += x;
            x *= 10;
            a[s] /= 10;
        }
        return;
    }
    ll mid = (s + e) >> 1;
    bld(lc, s, mid);
    bld(rc, mid, e);
    seg[id].s = seg[lc].s + seg[rc].s;
    for(ll i = 0; i < 10; i++){
        seg[id].val[i] = seg[lc].val[i] + seg[rc].val[i];
    }
    return;
}

void Do(ll id, ll x, ll y){
    if(x == y) return;
    seg[id].s += seg[id].val[x] * (y - x);
    seg[id].val[y] += seg[id].val[x];
    seg[id].val[x] = 0;
    for(ll i = 0; i < 10; i++){
        if(seg[id].lz[i] == x) seg[id].lz[i] = y;
    }
    return;
}

void shift(ll id){
    ll ds = 0;
    ll dx[10];
    fill(dx, dx + 10, 0);
    for(ll i = 0; i < 10; i++){
        dx[seg[id].lz[i]] += seg[lc].val[i];
        seg[lc].lz[i] = seg[id].lz[seg[lc].lz[i]];
        ds += seg[lc].val[i] * (seg[id].lz[i] - i);
    }
    seg[lc].s += ds;
    for(ll i = 0; i < 10; i++){
        seg[lc].val[i] = dx[i];
    }
    fill(dx, dx + 10, 0);
    ds = 0;
    for(ll i = 0; i < 10; i++){
        dx[seg[id].lz[i]] += seg[rc].val[i];
        seg[rc].lz[i] = seg[id].lz[seg[rc].lz[i]];
        ds += seg[rc].val[i] * (seg[id].lz[i] - i);
    }
    seg[rc].s += ds;
    for(ll i = 0; i < 10; i++){
        seg[rc].val[i] = dx[i];
        seg[id].lz[i] = i;
    }
    return;
}

void upd(ll id, ll s, ll e, ll l, ll r, ll x, ll y){
    if(r <= s || e <= l) return;
    if(l <= s && e <= r){
        Do(id, x, y);
        return;
    }
    ll mid = (s + e) >> 1;
    shift(id);
    upd(lc, s, mid, l, r, x, y);
    upd(rc, mid, e, l, r, x, y);
    seg[id].s = seg[lc].s + seg[rc].s;
    for(ll i = 0; i < 10; i++){
        seg[id].val[i] = seg[lc].val[i] + seg[rc].val[i];
    }
    return;
}
ll get(ll id, ll s, ll e, ll l, ll r){
    if(r <= s || e <= l) return 0;
    if(l <= s && e <= r){
        return seg[id].s;
    }
    ll mid = (s + e) >> 1;
    shift(id);
    return get(lc, s, mid, l, r) + get(rc, mid, e, l, r);
}

int main(){
    fast_io;

    cin >> n >> q;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    bld(1, 0, n);
    for(ll i = 0; i < q; i++){
        ll t, l, r, x, y;
        cin >> t >> l >> r;
        if(t == 2){
            cout << get(1, 0, n, l - 1, r) << '\n';
        }
        else{
            cin >> x >> y;
            upd(1, 0, n, l - 1, r, x, y);
        }
    }

    return 0;
}