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
#define all(a) (a).begin, (a).end()
#define F first
#define S second
#define lc (id << 1)
#define rc (id << 1 | 1)


ll n, m;
string st;
pair<char, pll> q[maxn];
vector<pll> a;
pll seg[maxn << 2];
ll vis[maxn];

void upd(ll id, ll s, ll e, ll l, ll r){
    if(r <= s || e <= l) return;
    if(l <= s && e <= r){
        if(vis[s]){
            seg[id] = Mp(-1ll, -1ll);
        }
        else{
            seg[id] = Mp(a[s].S, a[s].F);
        }
        vis[s] ^= 1;
        return;
    }
    ll mid = (s + e) / 2;
    upd(lc, s, mid, l, r);
    upd(rc, mid, e, l, r);
    seg[id] = max(seg[lc], seg[rc]);
    return;
}
pll get(ll id, ll s, ll e, ll l, ll r, ll x){
    ll mid = (s + e) / 2;
    if(r <= s || e <= l) return Mp(-1ll, -1ll);
    if(l <= s && e <= r){
        if(seg[id].F <= x) return Mp(-1ll, -1ll);
        if(e - s == 1) return seg[id];
        if(seg[lc].F > x) return get(lc, s, mid, l, r, x);
        return get(rc, mid, e, l, r, x);
    }
    pll p = get(lc, s, mid, l, r, x);
    if(p.F != -1) return p;
    return get(rc, mid, e, l, r, x);
}

int main(){
    fast_io;

    fill(seg, seg + (maxn << 2), Mp(-1ll, -1ll));

    cin >> n;
    for(ll i = 0; i < n; i++){
        cin >> st >> q[i].S.F >> q[i].S.S;
        q[i].F = st[0];
        a.pb(q[i].S);
    }
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    m = a.size();
    for(ll i = 0; i < n; i++){
        ll x = lower_bound(a.begin(), a.end(), q[i].S) - a.begin();
        if(q[i].F == 'f'){
            pll p = get(1, 0, m, upper_bound(a.begin(), a.end(), Mp(q[i].S.F, inf)) - a.begin(), m, q[i].S.S);
            if(p.F == -1) cout << "-1\n";
            else cout << p.S << " " << p.F << '\n';
        }
        else upd(1, 0, m, x, x + 1);
    }


    return 0;
}