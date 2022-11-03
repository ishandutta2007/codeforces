#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MAXN = 201005;
const ll NO = 1000000007;
ll tree[4 * MAXN], psh[4 * MAXN], left0[4 * MAXN], left1[4 * MAXN];
ll t[MAXN], l[MAXN], r[MAXN], pt[2 * MAXN];
map<ll, ll> mp;

void build(ll idx, ll l, ll r) {
    tree[idx] = psh[idx] = 0;
    left1[idx] = NO;
    left0[idx] = l;
    if(r - l == 1){
        return;
    }
    ll mid = (l + r) >> 1LL;
    build(idx << 1LL, l, mid);
    build((idx << 1LL) + 1, mid, r);
}

void apply_only_here(ll idx, ll l, ll r, ll type) {
    switch(type){
        case 1:
            psh[idx] = type;
            tree[idx] = r - l;
            left1[idx] = l;
            left0[idx] = NO;
            break;
        case 2:
            psh[idx] = type;
            tree[idx] = 0;
            left0[idx] = l;
            left1[idx] = NO;
            break;
        case 3:
            psh[idx] = 3 - psh[idx];
            tree[idx] = r - l - tree[idx];
            swap(left0[idx], left1[idx]);
            break;
    }
}

void push_from(ll idx, ll l, ll r) {
    if(psh[idx] && r - l > 1) {
        ll mid = (l + r) >> 1LL;
        apply_only_here(idx << 1LL, l, mid, psh[idx]);
        apply_only_here((idx << 1LL) + 1, mid, r, psh[idx]);
        psh[idx] = 0;
    }
}

void update(ll type, ll idx, ll l, ll r, ll L, ll R) {
    if(L >= R || L >= r || l >= R){
        return;
    }
    push_from(idx, l, r);
    if(l == L && r == R){
        apply_only_here(idx, l, r, type);
        return;
    }
    ll mid = (l + r) >> 1LL;
    update(type, idx << 1LL, l, mid, L, min(R, mid));
    update(type, (idx << 1LL) + 1, mid, r, max(L, mid), R);
    left0[idx] = min(left0[idx << 1LL], left0[(idx << 1LL) + 1]);
    left1[idx] = min(left1[idx << 1LL], left1[(idx << 1LL) + 1]);
}

int main() {
    ll n;
    cin >> n;
    set<ll> st;
    for(ll i = 0; i < n; ++i){
        cin >> t[i] >> l[i] >> r[i];
        ++r[i];
        st.insert(l[i]);
        st.insert(r[i]);
    }
    st.insert(1);
    ll ptr = 0;
    for(auto k: st){
        mp[k] = ptr;
        pt[ptr++] = k;
    }
    build(1, 0, 2 * n);
    for(ll i = 0; i < n; ++i){
        l[i] = mp[l[i]];
        r[i] = mp[r[i]];
        update(t[i], 1, 0, 2 * n, l[i], r[i]);
        ll ans = left0[1];
        if(ans == NO) {
            cout << pt[st.size() - 1] << endl;
        }else{
            cout << pt[ans] << endl;
        }
    }
    return 0;
}