//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 1333;
const ll base = 2e5 + 183;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

ll n, m, a[maxn], b[maxn], c[maxn], p[maxn], seg[maxn << 2], cnt[maxn << 2];

void upd(ll id, ll s, ll e, ll l, ll r, ll f){
    if(r <= s || e <= l) return;
    if(l <= s && e <= r){
        seg[id] = f * b[s];
        cnt[id] = f;
        return;
    }
    ll mid = (s + e) >> 1;
    upd(id << 1, s, mid, l, r, f);
    upd(id << 1 | 1, mid, e, l, r, f);
    cnt[id] = cnt[id << 1] + cnt[id << 1 | 1];
    seg[id] = (seg[id << 1] * p[cnt[id << 1 | 1]] + seg[id << 1 | 1]) % mod;
    return;
}

int main(){
    fast_io;
    p[0] = 1;
    for(ll i = 1; i < maxn; i++){
        p[i] = (p[i - 1] * base) % mod;
    }
    cin >> n >> m;
    ll hs = 0;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        a[i]--;
        hs = (hs * base + a[i]) % mod;
    }
    for(ll i = 0; i < m; i++){
        cin >> b[i];
        b[i]--;
        c[b[i]] = i;
    }
    ll x = 0, ans = 0;
    for(ll i = 0; i < n; i++){
        upd(1, 0, m, c[i], c[i] + 1, 1);
        x += p[i];
        if(x >= mod) x -= mod;
    }
    if(seg[1] == hs) ans++;
    for(ll i = n; i < m; i++){
        hs += x;
        if(hs >= mod) hs -= mod;
        upd(1, 0, m, c[i - n], c[i - n] + 1, 0);
        upd(1, 0, m, c[i], c[i] + 1, 1);
        if(seg[1] == hs){
            ans++;
        }
    }
    cout << ans;

    return 0;
}