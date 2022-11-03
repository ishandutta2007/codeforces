#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const ll MAXN = 1LL << 17LL;

ll tree[4 * MAXN];

void build(ll t[]) {
    for(ll i = 0; i < 4 * MAXN; ++i){
        t[i] = 0;
    }
}

void update(ll t[], ll idx, ll l, ll r, ll target, ll val){
    if(l > target || r < target){
        return;
    }
    t[idx] += val;
    if(l == r){
        return;
    }
    ll mid = (l + r) >> 1LL;
    update(t, idx << 1LL, l, mid, target, val);
    update(t, idx << 1LL | 1LL, mid + 1, r, target, val);
}

ll get(ll t[], ll idx, ll l, ll r, ll tl, ll tr) {
    if(l > r || l > tr || r < tl){
        return 0;
    }
    if(l == tl && r == tr){
        return t[idx];
    }
    ll mid = (l + r) >> 1LL;
    ll ans = 0;
    ans += get(t, idx << 1LL, l, mid, tl, min(tr, mid));
    ans += get(t, idx << 1LL | 1LL, mid + 1, r, max(mid + 1, tl), tr);
    return ans;
}


ll binsearch(vector<ll>& v, ll val){
    ll l, mid, r;
    if(v.back() <= val){
        return (ll)v.size();
    }
    if(v[0] > val){
        return 0;
    }
    l = 0;
    r = (ll)v.size();
    while(r - l > 1){
        mid = (l + r) >> 1LL;
        if(v[mid] > val){
            r = mid;
        }else{
            l = mid;
        }
    }
    return r;
}


int main() {
    ll n;
    cin >> n;
    vector<ll> a(n);
    vector<vector<ll>> b(100001);
    set<ll> deleted;
    for(ll i = 0; i < n; ++i){
        cin >> a[i];
        b[a[i]].push_back(i);
    }
    ll ans = 0;
    ll pos = -1;
    ll del = 0;
    build(tree);
    for(ll i = 1; i <= 100000; ++i){
        if(b[i].empty()){
            continue;
        }
        ll x = binsearch(b[i], pos);
        if(x == 0){
            x = (ll)b[i].size() - 1;
        }else{
            --x;
        }
        if(pos == -1){
            ans += b[i][x] + 1;
        }else{
            ans += (n + b[i][x] - pos) % n;
        }
        if(pos >= 0) {
            ans -= del;
            if (b[i][x] > pos) {
                ans += get(tree, 1, 0, n - 1, b[i][x] + 1, n - 1);
                ans += get(tree, 1, 0, n - 1, 0, pos);
            } else {
                ans += get(tree, 1, 0, n - 1, b[i][x] + 1, pos);
            }
        }
        for(auto k: b[i]){
            update(tree, 1, 0, n - 1, k, 1);
        }
        del += b[i].size();
        pos = b[i][x];
    }
    cout << ans << endl;
    return 0;
}