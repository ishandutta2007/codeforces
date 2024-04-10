#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
constexpr int INF = 1e9;
constexpr LL INFLL = 1e18;
struct Node {
    int mx, lazy;
};
Node t[1 << 20];
vector<int> v;
void pushDown(int p) {
    t[2 * p].mx += t[p].lazy;
    t[2 * p].lazy += t[p].lazy;
    t[2 * p + 1].mx += t[p].lazy;
    t[2 * p + 1].lazy += t[p].lazy;
    t[p].lazy = 0;
}
void pushUp(int p) {
    t[p].mx = max(t[2 * p].mx, t[2 * p + 1].mx);
}
void build(int p, int l, int r, int c0) {
    t[p].lazy = 0;
    if (r - l == 1) {
        t[p].mx = c0 - v[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * p, l, mid, c0);
    build(2 * p + 1, mid, r, c0);
    pushUp(p);
}
int rangeMax(int p, int l, int r, int x, int y) {
    if (l >= y || r <= x)
        return -INF;
    if (l >= x && r <= y)
        return t[p].mx;
    int mid = (l + r) / 2;
    pushDown(p);
    int lc = rangeMax(2 * p, l, mid, x, y);
    int rc = rangeMax(2 * p + 1, mid, r, x, y);
    return max(lc, rc);
}
void rangeAdd(int p, int l, int r, int x, int y, int v) {
    if (l >= y || r <= x)
        return;
    if (l >= x && r <= y) {
        t[p].mx += v;
        t[p].lazy += v;
        return;
    }
    int mid = (l + r) / 2;
    pushDown(p);
    rangeAdd(2 * p, l, mid, x, y, v);
    rangeAdd(2 * p + 1, mid, r, x, y, v);
    pushUp(p);
}
void solve() {
    int n, m, c, c0;
    cin >> n >> m >> c >> c0;
    LL ans = 0;
    priority_queue<tuple<int, int, int>> h;
    vector<tuple<int, int, int>> f(n);
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        int t, a, b;
        cin >> t >> a >> b;
        f[i] = {t, a, b};
        v[i] = t;
    }
    ++n;
    f.emplace_back(m, 0, 0);
    v.push_back(m);
    sort(f.begin(), f.end());
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for (auto &[t, a, b] : f)
        t = lower_bound(v.begin(), v.end(), t) - v.begin();
    build(1, 0, v.size(), c0);
    for (auto [t, a, b] : f) {
        int x = -rangeMax(1, 0, v.size(), t, t + 1);
        while (x > 0 && !h.empty()) {
            auto [b, a, t] = h.top();
            h.pop();
            b = -b;
            int lim = min(a, max(0, c - rangeMax(1, 0, v.size(), t, v.size())));
            if (lim <= x) {
                ans += LL(lim) * b;
                x -= lim;
                if (lim > 0)
                    rangeAdd(1, 0, v.size(), t, v.size(), lim);
            } else {
                ans += LL(x) * b;
                rangeAdd(1, 0, v.size(), t, v.size(), x);
                h.emplace(-b, a - x, t);
                x = 0;
                break;
            }
        }
        if (x > 0) {
            cout << "-1\n";
            return;
        }
        h.emplace(-b, a, t);
    }
    cout << ans << "\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}