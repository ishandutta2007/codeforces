//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll n, m, a[maxn], b[maxn], ls[maxn], ans[maxn];
pll q[maxn];
vector<ll> vec[maxn];
vector<pll> g[maxn];
pll seg[maxn << 2];

pll mrg(pll l, pll r){
    return Mp(l.F + r.F, l.S + r.S);
}

void upd(ll id, ll s, ll e, ll l, ll r, pll x){
    if(r <= s || e <= l) return;
    if(l <= s && e <= r){
        seg[id] = mrg(seg[id], x);
        return;
    }
    ll mid = (s + e) >> 1;
    upd(id << 1, s, mid, l, r, x);
    upd(id << 1 | 1, mid, e, l, r, x);
    seg[id] = mrg(seg[id << 1], seg[id << 1 | 1]);
    return;
}
pll get(ll id, ll s, ll e, ll l, ll r){
    if(r <= s || e <= l) return Mp(0ll, 0ll);
    if(l <= s && e <= r) return seg[id];
    ll mid = (s + e) >> 1;
    return mrg(get(id << 1, s, mid, l, r), get(id << 1 | 1, mid, e, l, r));
}

int main(){
    fast_io;

    fill(ls, ls + maxn, -1);
    fill(q, q + maxn, Mp(-1ll, -1ll));

    cin >> n;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        vec[a[i]].pb(i);
        b[i] = ls[a[i]];
        ls[a[i]] = i;
    }
    for(ll i = 0; i < maxn; i++){
        ls[i] = -1;
        for(ll j = 0; j + 2 < (ll)vec[i].size(); j++){
            if(vec[i][j + 1] * 2 != vec[i][j] + vec[i][j + 2]){
                q[vec[i][j + 2]] = Mp(vec[i][j], ls[i]);
                ls[i] = vec[i][j];
            }
        }
    }
    cin >> m;
    for(ll i = 0; i < m; i++){
        ll l, r;
        cin >> l >> r;
        g[r - 1].pb(Mp(l - 1, i));
    }
    for(ll i = 0; i < n; i++){
        if(b[i] != -1){
            upd(1, 0, n, b[i], b[i] + 1, Mp(-1ll, 0ll));
        }
        upd(1, 0, n, i, i + 1, Mp(1ll, 0ll));
        if(q[i].F != -1){
            if(q[i].S != -1){
                upd(1, 0, n, q[i].S, q[i].S + 1, Mp(0ll, -1ll));
            }
            upd(1, 0, n, q[i].F, q[i].F + 1, Mp(0ll, 1ll));
        }
        for(pll l : g[i]){
            pll p = get(1, 0, n, l.F, n);
            if(p.F == p.S) p.F++;
            ans[l.S] = p.F;
        }
    }
    for(ll i = 0; i < m; i++){
        cout << ans[i] << '\n';
    }

    return 0;
}