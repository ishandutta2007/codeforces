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

ll n, a[maxn], lz[maxn], mn[maxn], cnt[maxn], ans;
vector<ll> st, ts;

void bld(ll id, ll s, ll e){
    mn[id] = 1;
    cnt[id] = e - s;
    if(e - s == 1) return;
    ll mid = (s + e) / 2;
    bld(id * 2, s, mid);
    bld(id * 2 + 1, mid, e);
    return;
}

void upd(ll id, ll s, ll e, ll l, ll r, ll x){
    if(r <= s || e <= l) return;
    if(l <= s && e <= r){
        mn[id] += x;
        lz[id] += x;
        return;
    }
    ll mid = (s + e) / 2;
    mn[id * 2] += lz[id];
    lz[id * 2] += lz[id];
    mn[id * 2 + 1] += lz[id];
    lz[id * 2 + 1] += lz[id];
    lz[id] = 0;
    upd(id * 2, s, mid, l, r, x);
    upd(id * 2 + 1, mid, e, l, r, x);
    mn[id] = min(mn[id * 2], mn[id * 2 + 1]);
    cnt[id] = 0;
    if(mn[id] == mn[id * 2]) cnt[id] += cnt[id * 2];
    if(mn[id] == mn[id * 2 + 1]) cnt[id] += cnt[id * 2 + 1];
    return;
}

int main(){
    fast_io;

    cin >> n;
    for(ll i = 0; i < n; i++){
        ll v, u;
        cin >> v >> u;
        a[v - 1] = u - 1;
    }
    bld(1, 0, n);
    st.pb(-1);
    ts.pb(-1);
    for(ll i = 0; i < n; i++){
        while(st.back() != -1 && a[i] > a[st.back()]){
            ll x = a[i] - a[st.back()];
            st.pop_back();
            upd(1, 0, n, st.back() + 1, i, x);
        }
        st.pb(i);
        while(ts.back() != -1 && a[i] < a[ts.back()]){
            ll x = a[ts.back()] - a[i];
            ts.pop_back();
            upd(1, 0, n, ts.back() + 1, i, x);
        }
        ts.pb(i);
        upd(1, 0, n, 0, i + 1, -1);
        ans += cnt[1];
    }
    cout << ans;

    return 0;
}