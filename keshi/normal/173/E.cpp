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

ll n, m, k, h[maxn], a[maxn], sz[maxn], d[maxn], ans[maxn];
pll b[maxn], c[maxn];
ll seg[maxn << 2], mx[maxn << 2];
vector<pair<pll, ll> > g[maxn];

void upd(ll id, ll s, ll e, ll l, ll r, ll x){
    if(r <= s || e <= l) return;
    if(l <= s && e <= r){
        seg[id] += x;
        return;
    }
    ll mid = (s + e) >> 1;
    upd(lc, s, mid, l, r, x);
    upd(rc, mid, e, l, r, x);
    seg[id] = seg[lc] + seg[rc];
    return;
}
ll get(ll id, ll s, ll e, ll l, ll r){
    if(r <= s || e <= l) return 0ll;
    if(l <= s && e <= r) return seg[id];
    ll mid = (s + e) >> 1;
    return get(lc, s, mid, l, r) + get(rc, mid, e, l, r);
}
void bld(ll id, ll s, ll e){
    mx[id] = -1;
    if(e - s == 1) return;
    ll mid = (s + e) >> 1;
    bld(lc, s, mid);
    bld(rc, mid, e);
    return;
}
void up2(ll id, ll s, ll e, ll l, ll r, ll x){
    if(r <= s || e <= l) return;
    if(l <= s && e <= r){
        mx[id] = x;
        return;
    }
    ll mid = (s + e) >> 1;
    up2(lc, s, mid, l, r, x);
    up2(rc, mid, e, l, r, x);
    mx[id] = max(mx[lc], mx[rc]);
    return;
}
ll ge2(ll id, ll s, ll e, ll l, ll r){
    if(r <= s || e <= l) return -1;
    if(l <= s && e <= r) return mx[id];
    ll mid = (s + e) >> 1;
    return max(ge2(lc, s, mid, l, r), ge2(rc, mid, e, l, r));
}

int main(){
    fast_io;

    cin >> n >> k;
    for(ll i = 0; i < n; i++){
        cin >> h[i];
        c[i] = Mp(h[i], i);
    }
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        b[i] = Mp(a[i], i);
    }
    sort(b, b + n);
    sort(c, c + n);
    for(ll i = 0; i < n;){
        ll j = i;
        while(j < n && c[i].F == c[j].F){
            d[j] = lower_bound(b, b + n, Mp(a[c[j].S], c[j].S)) - b;
            upd(1, 0, n, d[j], d[j] + 1, 1);
            j++;
        }
        for(ll o = i; o < j; o++){
           sz[o] = get(1, 0, n, lower_bound(b, b + n, Mp(a[c[o].S] - k, -inf)) - b, upper_bound(b, b + n, Mp(a[c[o].S] + k, inf)) - b);
        }
        i = j;
    }
    cin >> m;
    for(ll i = 0; i < m; i++){
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        if(a[x] < a[y]) swap(x, y);
        ll z = max(h[x], h[y]);
        g[lower_bound(c, c + n, Mp(z, -inf)) - c].pb(Mp(Mp(a[x] - k, a[y] + k), i));
    }
    bld(1, 0, n);
    for(ll i = n; i--;){
        up2(1, 0, n, d[i], d[i] + 1, sz[i]);
        for(auto j : g[i]){
            ans[j.S] = ge2(1, 0, n, lower_bound(b, b + n, Mp(j.F.F, -inf)) - b, upper_bound(b, b + n, Mp(j.F.S, inf)) - b);
        }
    }
    for(ll i = 0; i < m; i++){
        cout << ans[i] << '\n';
    }

    return 0;
}