//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll maxm = 6;
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
    ll w[2][maxm], lz;
    node(){
        for(ll i = 0; i < 2; i++){
            for(ll j = 0; j < maxm; j++){
                w[i][j] = j;
            }
        }
        lz = 0;
    }
};

ll n, m, q, a[maxn];
node seg[maxn << 2];

node mrg(node l, node r){
    node mid;
    for(ll i = 0; i < 2; i++){
        for(ll j = 0; j <= m; j++){
            mid.w[i][j] = l.w[i][r.w[i][j]];
        }
    }
    return mid;
}

void bld(ll id, ll s, ll e){
    if(e - s == 1){
        for(ll i = 0; i < 2; i++){
            for(ll j = 0; j <= m; j++){
                if(((a[s] + i) & 1) && j == m){
                    seg[id].w[i][j] = 0;
                }
                else{
                    seg[id].w[i][j] = min(m, j + 1);
                }
            }
        }
        return;
    }
    ll mid = (s + e) >> 1;
    bld(lc, s, mid);
    bld(rc, mid, e);
    seg[id] = mrg(seg[lc], seg[rc]);
    return;
}

void Do(ll id){
    for(ll j = 0; j <= m; j++){
        swap(seg[id].w[0][j], seg[id].w[1][j]);
    }
    seg[id].lz ^= 1;
    return;
}
void Shift(ll id){
    if(seg[id].lz == 0) return;
    Do(lc);
    Do(rc);
    seg[id].lz = 0;
    return;
}

void upd(ll id, ll s, ll e, ll l, ll r){
    if(r <= s || e <= l) return;
    if(l <= s && e <= r){
        Do(id);
        return;
    }
    ll mid = (s + e) >> 1;
    Shift(id);
    upd(lc, s, mid, l, r);
    upd(rc, mid, e, l, r);
    seg[id] = mrg(seg[lc], seg[rc]);
    return;
}
node get(ll id, ll s, ll e, ll l, ll r){
    if(r <= s || e <= l) return node();
    if(l <= s && e <= r) return seg[id];
    ll mid = (s + e) >> 1;
    Shift(id);
    return mrg(get(lc, s, mid, l, r), get(rc, mid, e, l, r));
}

int main(){
    fast_io;

    cin >> n >> m >> q;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    bld(1, 0, n);
    for(ll i = 0; i < q; i++){
        ll t, l, r, x;
        cin >> t >> l >> r;
        if(t == 1){
            cin >> x;
            if(x & 1){
                upd(1, 0, n, l - 1, r);
            }
        }
        else{
            if(get(1, 0, n, l - 1, r).w[0][m] == 0){
                cout << 2;
            }
            else{
                cout << 1;
            }
            cout << '\n';
        }
    }

    return 0;
}