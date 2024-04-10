//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second

struct node{
    ll mn0, mn1, r0, r1, sz, lz;
    node(){
        mn0 = mn1 = r0 = r1 = inf;
        sz = lz = 0;
    }
};

ll n, m, a[maxn];
bool ans[maxn];
pair<pll, pll> q[maxn];
node seg[maxn];

bool ok(node x){
    //cout << "? " << x.sz << " " << x.mn0 << " " << x.mn1 << " " << x.r0 << " " << x.r1 << '\n';
    if(x.mn1 <= 0) return 0;
    if(x.mn0 < 0) return 0;
    ll y = x.r0;
    if(x.sz & 1) y *= -1;
    if(y != 0 && y != 1) return 0;
    if((x.sz + x.r0) & 1) return 1;
    if(x.r1 <= (x.sz & 1)) return 0;
    return 0;
}

node mrg(node l, node r){
    if(r.sz == 0) return l;
    if(l.sz == 0) return r;
    node mid;
    mid.sz = l.sz + r.sz;
    r.mn0 -= l.r0;
    r.mn1 += l.r0;
    if(l.sz & 1) swap(r.mn0, r.mn1);
    mid.mn0 = min(l.mn0, r.mn0);
    mid.mn1 = min(l.mn1, r.mn1);
    if(l.sz & 1){
        mid.mn0 = min(mid.mn0, l.r0);
    }
    else{
        mid.mn1 = min(mid.mn1, l.r0);
    }
    if(r.sz & 1){
        r.r0 -= l.r0;
        r.r1 += l.r1;
    }
    else{
        r.r0 += l.r0;
        r.r1 -= l.r0;
    }
    if(r.sz == 1) r.r1 = l.r0;
    mid.r0 = r.r0;
    mid.r1 = r.r1;
    return mid;
}

void Do(ll id, ll x){
    seg[id].mn0 += x;
    seg[id].lz += x;
    if(seg[id].sz & 1) seg[id].r0 += x;
    else seg[id].r1 += x;
    return;
}

void bld(ll id, ll s, ll e){
    seg[id] = node();
    seg[id].sz = e - s;
    if(e - s == 1){
        seg[id].r0 = a[s];
        return;
    }
    ll mid = (s + e) / 2;
    bld(id * 2, s, mid);
    bld(id * 2 + 1, mid, e);
    seg[id] = mrg(seg[id * 2], seg[id * 2 + 1]);
    return;
}

void upd(ll id, ll s, ll e, ll l, ll r, ll x){
    if(r <= s || e <= l) return;
    if(l <= s && e <= r){
        Do(id, x);
        return;
    }
    ll mid = (s + e) / 2;
    Do(id * 2, seg[id].lz);
    Do(id * 2 + 1, seg[id].lz);
    seg[id].lz = 0;
    upd(id * 2, s, mid, l, r, x);
    upd(id * 2 + 1, mid, e, l, r, x);
    seg[id] = mrg(seg[id * 2], seg[id * 2 + 1]);
    return;
}
node get(ll id, ll s, ll e, ll l, ll r){
    if(r <= s || e <= l) return node();
    if(l <= s && e <= r) return seg[id];
    ll mid = (s + e) / 2;
    Do(id * 2, seg[id].lz);
    Do(id * 2 + 1, seg[id].lz);
    seg[id].lz = 0;
    return mrg(get(id * 2, s, mid, l, r), get(id * 2 + 1, mid, e, l, r));
}

int main(){
    fast_io;

    cin >> n;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    cin >> m;
    for(ll i = 0; i < m; i++){
        cin >> q[i].F.F >> q[i].S.F >> q[i].S.S;
        if(q[i].F.F == 1){
            cin >> q[i].F.S;
        }
    }
    bld(1, 0, n);
    for(ll i = 0; i < m; i++){
        if(q[i].F.F == 1){
            upd(1, 0, n, q[i].S.F, q[i].S.S + 1, q[i].F.S);
        }
        else{
            //cout << "!1\n";
            upd(1, 0, n, q[i].S.F, q[i].S.F + 1, -1);
            ans[i] |= ok(get(1, 0, n, q[i].S.F, q[i].S.S + 1));
            upd(1, 0, n, q[i].S.F, q[i].S.F + 1, 1);
        }
    }
    reverse(a, a + n);
    for(ll i = 0; i < m; i++){
        q[i].S.F = n - 1 - q[i].S.F;
        q[i].S.S = n - 1 - q[i].S.S;
        swap(q[i].S.F, q[i].S.S);
    }
    bld(1, 0, n);
    for(ll i = 0; i < m; i++){
        if(q[i].F.F == 1){
            upd(1, 0, n, q[i].S.F, q[i].S.S + 1, q[i].F.S);
        }
        else{
            //cout << "!2\n";
            upd(1, 0, n, q[i].S.F, q[i].S.F + 1, -1);
            ans[i] |= ok(get(1, 0, n, q[i].S.F, q[i].S.S + 1));
            upd(1, 0, n, q[i].S.F, q[i].S.F + 1, 1);
        }
    }
    for(ll i = 0; i < m; i++){
        if(q[i].F.F == 2) cout << ans[i] << "\n";
    }
    return 0;
}