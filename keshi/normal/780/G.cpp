//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

const ll maxn = 3e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define all(vec) (vec).begin(), (vec).end()
#define lc (id << 1)
#define rc (id << 1 | 1)

ll n, H, W, al[maxn], ar[maxn];
vector<pair<pll, pll> > a;
vector<pll> vec;
pair<ll, pll> seg[maxn << 2];

pair<ll, pll> mx(pair<ll, pll> l, pair<ll, pll> r){
    pair<ll, pll> id = max(l, r);
    if(id.S.F == 0) id = min(l, r);
    return id;
}

void bld(ll id, ll s, ll e){
    if(e - s == 1){
        seg[id] = Mp(vec[s].S, Mp(0ll, s));
        if(vec[s].S == 0) seg[id].S.F++;
        return;
    }
    ll mid = (s + e) >> 1;
    bld(lc, s, mid);
    bld(rc, mid, e);
    seg[id] = mx(seg[lc], seg[rc]);
    return;
}
void upd(ll id, ll s, ll e, ll l, ll r, ll x){
    if(r <= s || e <= l) return;
    if(l <= s && e <= r){
        seg[id].S.F = x;
        return;
    }
    ll mid = (s + e) >> 1;
    upd(lc, s, mid, l, r, x);
    upd(rc, mid, e, l, r, x);
    seg[id] = mx(seg[lc], seg[rc]);
    return;
}
pair<ll, pll> get(ll id, ll s, ll e, ll l, ll r){
    if(r <= s || e <= l) return Mp(-1ll, Mp(0ll, 0ll));
    if(l <= s && e <= r) return seg[id];
    ll mid = (s + e) >> 1;
    return mx(get(lc, s, mid, l, r), get(rc, mid, e, l, r));
}
ll Sum(ll id, ll s, ll e){
    if(e - s == 1) return seg[id].S.F;
    ll mid = (s + e) >> 1;
    ll x = Sum(lc, s, mid) + Sum(rc, mid, e);
    if(x >= mod) x -= mod;
    return x;
}

int main(){
    fast_io;
//    freopen("in4.txt", "r+", stdin);

    cin >> H >> W >> n;
    a.resize(n);
    for(ll i = 0; i < n; i++){
        cin >> a[i].F.F >> a[i].S.F >> a[i].S.S >> a[i].F.S;
        a[i].F.F = H - a[i].F.F + 1;
    }
    for(ll i = 1; i <= W; i++){
        vec.pb(Mp(i, 0));
    }
    sort(all(a));
    for(ll i = 0; i < n; i++){
        if(a[i].S.F != 1){
            vec.pb(Mp(a[i].S.F - 1, a[i].F.F));
        }
        if(a[i].S.S != W){
            vec.pb(Mp(a[i].S.S + 1, a[i].F.F));
        }
    }
    sort(all(vec));
//    for(pll i : vec){
//        cout << i.F << " " << i.S << '\n';
//    }
    for(ll i = 0; i < n; i++){
        if(a[i].S.F != 1){
            al[i] = lower_bound(all(vec), Mp(a[i].S.F - 1, a[i].F.F)) - vec.begin();
        }
        if(a[i].S.S != W){
            ar[i] = lower_bound(all(vec), Mp(a[i].S.S + 1, a[i].F.F)) - vec.begin();
        }
        if(a[i].S.F == 1) al[i] = ar[i];
        if(a[i].S.S == W) ar[i] = al[i];
    }
    ll S = (ll)vec.size();
    bld(1, 0, S);
    for(ll i = 0; i < n; i++){
        ll x = 0, xl, xr;
        xl = lower_bound(all(vec), Mp(a[i].S.F, -inf)) - vec.begin();
        xr = upper_bound(all(vec), Mp(a[i].S.S, inf)) - vec.begin();
//        cout << "? " << a[i].F.F << " " << a[i].F.S << " " << a[i].S.F << " " << a[i].S.S << '\n';
//        cout << "! " << xl << " " << xr << '\n';
        pair<ll, pll> p = get(1, 0, S, xl, xr);
//        cout << "& " << p.F << " " << p.S.F << " " << p.S.S << '\n';
        while(a[i].F.F - p.F <= a[i].F.S && p.S.F > 0){
            upd(1, 0, S, p.S.S, p.S.S + 1, 0);
            x += p.S.F;
            if(x >= mod) x -= mod;
            p = get(1, 0, S, xl, xr);
//            cout << "& " << p.F << " " << p.S.F << " " << p.S.S << '\n';
        }
        if(al[i] == ar[i]) x <<= 1;
        if(x >= mod) x -= mod;
//        cout << "* " << al[i] << " " << ar[i] << '\n';
        upd(1, 0, S, ar[i], ar[i] + 1, x);
        upd(1, 0, S, al[i], al[i] + 1, x);
    }
    cout << Sum(1, 0, S);


    return 0;
}