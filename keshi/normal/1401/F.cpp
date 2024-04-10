//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll n, q, m, seg[maxn], f[maxn];

void upd(ll id, ll h, ll s, ll e, ll l, ll r, ll x){
    if(r <= s || e <= l) return;
    if(l <= s && e <= r){
        seg[id] = x;
        return;
    }
    ll mid = (s + e) / 2;
    if(f[h]){
        upd(id * 2, h - 1, mid, e, l, r, x);
        upd(id * 2 + 1, h - 1, s, mid, l, r, x);
    }
    else{
        upd(id * 2, h - 1, s, mid, l, r, x);
        upd(id * 2 + 1, h - 1, mid, e, l, r, x);
    }
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
    return;
}
ll get(ll id, ll h, ll s, ll e, ll l, ll r){
    if(r <= s || e <= l) return 0;
    if(l <= s && e <= r) return seg[id];
    ll mid = (s + e) / 2;
    if(f[h]){
        return get(id * 2, h - 1, mid, e, l, r) + get(id * 2 + 1, h - 1, s, mid, l, r);
    }
    return get(id * 2, h - 1, s, mid, l, r) + get(id * 2 + 1, h - 1, mid, e, l, r);
}

int main(){
    fast_io;

    cin >> n >> q;
    m = (1ll << n);
    for(ll i = 0; i < m; i++){
        ll x;
        cin >> x;
        upd(1, n - 1, 0, m, i, i + 1, x);
    }
    for(ll i = 0; i < q; i++){
        ll t, l, r;
        cin >> t;
        if(t == 1){
            cin >> l >> r;
            upd(1, n - 1, 0, m, l - 1, l, r);
        }
        if(t == 2){
            cin >> l;
            for(ll j = 0; j < l; j++){
                f[j] ^= 1;
            }
        }
        if(t == 3){
            cin >> l;
            f[l] ^= 1;
        }
        if(t == 4){
            cin >> l >> r;
            cout << get(1, n - 1, 0, m, l - 1, r) << '\n';
        }
    }

    return 0;
}