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
#define lc (id << 1)
#define rc (id << 1 | 1)

struct spell{
    ll a, b, c, d;
};
struct node{
    ll val, mn, ind;
    node(){
        val = inf;
    }
};

ll n, d[maxn], par[maxn];
pll b[maxn];
node seg[maxn * 4];
spell a[maxn];
queue<ll> q;

void bld(ll id, ll s, ll e){
    if(e - s == 1){
        seg[id].ind = s;
        seg[id].mn = b[s].S;
        seg[id].val = a[b[s].S].b;
        return;
    }
    ll mid = (s + e) >> 1;
    bld(lc, s, mid);
    bld(rc, mid, e);
    seg[id] = seg[lc];
    if(seg[lc].val > seg[rc].val){
        seg[id] = seg[rc];
    }
    return;
}
void upd(ll id, ll s, ll e, ll l, ll r){
    if(r <= s || e <= l) return;
    if(l <= s && e <= r){
        seg[id].val = inf;
        return;
    }
    ll mid = (s + e) >> 1;
    upd(lc, s, mid, l, r);
    upd(rc, mid, e, l, r);
    seg[id] = seg[lc];
    if(seg[lc].val > seg[rc].val){
        seg[id] = seg[rc];
    }
    return;
}
node get(ll id, ll s, ll e, ll l, ll r){
    if(r <= s || e <= l) return node();
    if(l <= s && e <= r) return seg[id];
    ll mid = (s + e) >> 1;
    node ln = get(lc, s, mid, l, r);
    node rn = get(rc, mid, e, l, r);
    if(ln.val < rn.val) return ln;
    return rn;
}

int main(){
    fast_io;
    cout.flush();

    cin >> n;
    for(ll i = 0; i < n; i++){
        cin >> a[i].a >> a[i].b >> a[i].c >> a[i].d;
        b[i] = Mp(a[i].a, i);
    }
    fill(d, d + n, -1);
    sort(b, b + n);
    bld(1, 0, n);
    q.push(n);
    ll cnt = 0;
    while(!q.empty()){
        ll v = q.front();
        cnt++;
        q.pop();
        ll x = upper_bound(b, b + n, Mp(a[v].c, inf)) - b;
        node y = get(1, 0, n, 0, x);
        while(y.val <= a[v].d){
            d[y.mn] = d[v] + 1;
            par[y.mn] = v;
            q.push(y.mn);
            upd(1, 0, n, y.ind, y.ind + 1);
            y = get(1, 0, n, 0, x);
        }
    }
    cout << d[n - 1] << '\n';
    if(d[n - 1] == -1) return 0;
    ll x = n - 1;
    vector<ll> vec;
    while(x != n){
        vec.pb(x);
        x = par[x];
    }
    reverse(vec.begin(), vec.end());
    for(ll i : vec){
        cout << i + 1 << " ";
    }

    return 0;
}