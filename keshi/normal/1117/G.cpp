//In the name of God
#pragma GCC optimize("Ofast")
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
#define lc (id << 1)
#define rc (id << 1 | 1)

ll n, q, a[maxn], ql[maxn], ans[maxn];
vector<ll> g[maxn];
vector<ll> st;

struct node{
    ll sum;
    int cnt, lz;
    node(){
        sum = cnt = lz = 0;
    }
};
node seg[maxn << 2];

node mrg(node l, node r){
    node id;
    id.sum = l.sum + r.sum;
    id.cnt = l.cnt + r.cnt;
    return id;
}
void shift(ll id){
    seg[lc].sum += seg[lc].cnt * seg[id].lz;
    seg[rc].sum += seg[rc].cnt * seg[id].lz;
    seg[lc].lz += seg[id].lz;
    seg[rc].lz += seg[id].lz;
    seg[id].lz = 0;
    return;
}
void bld(ll id, ll s, ll e){
    seg[id].cnt = e - s;
    if(e - s == 1) return;
    ll mid = (s + e) >> 1;
    bld(lc, s, mid);
    bld(rc, mid, e);
    return;
}
void dis(ll id, ll s, ll e, ll l, ll r){
    if(r <= s || e <= l) return;
    if(l <= s && e <= r){
        seg[id].cnt = 0;
        return;
    }
    ll mid = (s + e) >> 1;
    shift(id);
    dis(lc, s, mid, l, r);
    dis(rc, mid, e, l, r);
    seg[id] = mrg(seg[lc], seg[rc]);
    return;
}
void upd0(ll id, ll s, ll e, ll l, ll r){
    if(r <= s || e <= l) return;
    if(l <= s && e <= r){
        seg[id].sum += seg[id].cnt;
        seg[id].lz++;
        return;
    }
    ll mid = (s + e) >> 1;
    shift(id);
    upd0(lc, s, mid, l, r);
    upd0(rc, mid, e, l, r);
    seg[id] = mrg(seg[lc], seg[rc]);
    return;
}
ll get0(ll id, ll s, ll e, ll l, ll r){
    if(r <= s || e <= l) return 0;
    if(l <= s && e <= r) return seg[id].sum;
    ll mid = (s + e) >> 1;
    shift(id);
    return get0(lc, s, mid, l, r) + get0(rc, mid, e, l, r);
}
struct nod{
    ll sum;
    int lz;
    nod(){
        sum = lz = 0;
    }
};
nod se[maxn << 2];
void upd1(ll id, ll s, ll e, ll l, ll r){
    if(r <= s || e <= l) return;
    if(l <= s && e <= r){
        se[id].sum += e - s;
        se[id].lz++;
        return;
    }
    ll mid = (s + e) >> 1;
    se[lc].sum += se[id].lz * (mid - s);
    se[rc].sum += se[id].lz * (e - mid);
    se[lc].lz += se[id].lz;
    se[rc].lz += se[id].lz;
    se[id].lz = 0;
    upd1(lc, s, mid, l, r);
    upd1(rc, mid, e, l, r);
    se[id].sum = se[lc].sum + se[rc].sum;
    return;
}
ll get1(ll id, ll s, ll e, ll l, ll r){
    if(r <= s || e <= l) return 0;
    if(l <= s && e <= r) return se[id].sum;
    ll mid = (s + e) >> 1;
    se[lc].sum += se[id].lz * (mid - s);
    se[rc].sum += se[id].lz * (e - mid);
    se[lc].lz += se[id].lz;
    se[rc].lz += se[id].lz;
    se[id].lz = 0;
    return get1(lc, s, mid, l, r) + get1(rc, mid, e, l, r);
}

int main(){
    fast_io;

    cin >> n >> q;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
    }
    for(ll i = 0; i < q; i++){
        cin >> ql[i];
    }
    for(ll i = 0; i < q; i++){
        ll qr;
        cin >> qr;
        g[qr - 1].pb(i);
    }
    st.pb(-1);
    bld(1, 0, n);
    for(ll i = 0; i < n; i++){
        while(st.back() != -1ll && a[st.back()] < a[i]){
            dis(1, 0, n, st.back(), st.back() + 1);
            st.pop_back();
        }
        upd0(1, 0, n, 0, i);
        upd1(1, 0, n, st.back() + 1, i + 1);
        st.pb(i);
        for(ll j : g[i]){
            ans[j] = get0(1, 0, n, ql[j] - 1, i + 1) + get1(1, 0, n, ql[j] - 1, i + 1);
        }
    }
    for(ll i = 0; i < q; i++){
        cout << ans[i] << " ";
    }
    

    return 0;
}