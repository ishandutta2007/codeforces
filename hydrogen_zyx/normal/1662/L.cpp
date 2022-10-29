#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1 << 20;
const ll inf = 0x3f3f3f3f3f3f3f3f;

pair<ll, ll> p[N];

ll tree[N << 1];

void init() {
    for (ll i = 0; i < (N << 1); i++) tree[i] = -inf;
}

ll merge_range(ll a, ll b) {
    return max(a, b);
}

ll query(ll k, ll l, ll r, ll ql, ll qr) {
    if (qr < l || r < ql) return -inf;
    if (ql <= l && r <= qr) {
        return tree[k];
    }
    ll mid = (l + r) >> 1;
    ll lq = query(k << 1, l, mid, ql, qr);
    ll rq = query(k << 1 | 1, mid + 1, r, ql, qr);
    return merge_range(lq, rq);
}

void modify(ll k, ll l, ll r, ll pos, ll x) {
    if (l == r) {
        tree[k] = max(tree[k], x);
        return;
    }
    ll mid = (l + r) >> 1;
    if (pos <= mid) modify(k << 1, l, mid, pos, x);
    else modify(k << 1 | 1, mid + 1, r, pos, x);
    tree[k] = merge_range(tree[k << 1], tree[k << 1 | 1]);
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll n, v;
    cin >> n >> v;
    for (ll i = 0; i < n; i++) cin >> p[i].first;
    for (ll i = 0; i < n; i++) cin >> p[i].second;
    vector<ll> vx, vy;
    for (ll i = 0; i < n; i++) {
        p[i].first *= v;
        auto tmp = p[i];
        p[i].first = tmp.first - tmp.second;
        p[i].second = tmp.first + tmp.second;
        vx.push_back(p[i].first);
        vy.push_back(p[i].second);
    }
    vx.push_back(-inf), vy.push_back(-inf);
    vx.push_back(0), vy.push_back(0);
    sort(vx.begin(), vx.end()), sort(vy.begin(), vy.end());
    vx.erase(unique(vx.begin(), vx.end()), vx.end());
    vy.erase(unique(vy.begin(), vy.end()), vy.end());

    for (ll i = 0; i < n; i++) {
        p[i].first = lower_bound(vx.begin(), vx.end(), p[i].first) - vx.begin();
        p[i].second = lower_bound(vy.begin(), vy.end(), p[i].second) - vy.begin();
    }

    sort(p, p + n, [](pair<ll, ll> a, pair<ll, ll> b) {
        if (a.second != b.second) return a.second < b.second;
        else return a.first < b.first;
    });

    ll posx = lower_bound(vx.begin(), vx.end(), 0) - vx.begin();
    ll posy = lower_bound(vy.begin(), vy.end(), 0) - vy.begin();
    init();
    ll ans = 0;
    bool ok = 0;
    for (ll i = 0; i < n; i++) {
        if (!ok && p[i].second >= posy) modify(1, 1, N, posx, 0), ok = 1;
        ll val = query(1, 1, N, 1, p[i].first) + 1;
        ans = max(val, ans);
        modify(1, 1, N, p[i].first, val);
    }
    cout << ans << endl;
}