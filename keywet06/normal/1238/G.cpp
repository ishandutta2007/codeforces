#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

const int INF32 = 1e9;

struct Node {
    int mx, lazy;
};

Node t[1 << 20];

std::vector<int> v;

void PushDown(int p) {
    t[2 * p].mx += t[p].lazy;
    t[2 * p].lazy += t[p].lazy;
    t[2 * p + 1].mx += t[p].lazy;
    t[2 * p + 1].lazy += t[p].lazy;
    t[p].lazy = 0;
}

void PushUp(int p) { t[p].mx = max(t[2 * p].mx, t[2 * p + 1].mx); }

void Build(int p, int l, int r, int c0) {
    t[p].lazy = 0;
    if (r - l == 1) {
        t[p].mx = c0 - v[l];
        return;
    }
    int mid = (l + r) / 2;
    Build(2 * p, l, mid, c0);
    Build(2 * p + 1, mid, r, c0);
    PushUp(p);
}

int RangeMax(int p, int l, int r, int x, int y) {
    if (l >= y || r <= x) return -INF32;
    if (l >= x && r <= y) return t[p].mx;
    int mid = (l + r) / 2;
    PushDown(p);
    int lc = RangeMax(2 * p, l, mid, x, y);
    int rc = RangeMax(2 * p + 1, mid, r, x, y);
    return max(lc, rc);
}

void RangeAdd(int p, int l, int r, int x, int y, int v) {
    if (l >= y || r <= x) return;
    if (l >= x && r <= y) {
        t[p].mx += v;
        t[p].lazy += v;
        return;
    }
    int mid = (l + r) / 2;
    PushDown(p);
    RangeAdd(2 * p, l, mid, x, y, v);
    RangeAdd(2 * p + 1, mid, r, x, y, v);
    PushUp(p);
}

void solve() {
    int n, m, c, c0;
    std::cin >> n >> m >> c >> c0;
    int64 ans = 0;
    std::priority_queue<std::tuple<int, int, int> > h;
    std::vector<std::tuple<int, int, int> > f(n);
    v.resize(n);
    for (int i = 0; i < n; ++i) {
        int t, a, b;
        std::cin >> t >> a >> b;
        f[i] = {t, a, b};
        v[i] = t;
    }
    ++n;
    f.emplace_back(m, 0, 0);
    v.push_back(m);
    std::sort(f.begin(), f.end());
    std::sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    for (auto &[t, a, b] : f) {
        t = lower_bound(v.begin(), v.end(), t) - v.begin();
    }
    Build(1, 0, v.size(), c0);
    for (auto [t, a, b] : f) {
        int x = -RangeMax(1, 0, v.size(), t, t + 1);
        while (x > 0 && !h.empty()) {
            auto [b, a, t] = h.top();
            h.pop();
            b = -b;
            int Lim = min(a, max(0, c - RangeMax(1, 0, v.size(), t, v.size())));
            if (Lim <= x) {
                ans += int64(Lim) * b;
                x -= Lim;
                if (Lim > 0) RangeAdd(1, 0, v.size(), t, v.size(), Lim);
            } else {
                ans += int64(x) * b;
                RangeAdd(1, 0, v.size(), t, v.size(), x);
                h.emplace(-b, a - x, t);
                x = 0;
                break;
            }
        }
        if (x > 0) return void(std::cout << "-1\n");
        h.emplace(-b, a, t);
    }
    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    while (T--) solve();
    return 0;
}