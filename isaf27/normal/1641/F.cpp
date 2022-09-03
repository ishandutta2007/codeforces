#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double ld;
mt19937 rnd(228);
#define TIME (clock() * 1.0 / CLOCKS_PER_SEC)

const int M = 5e4 + 239;
const int X = (int)(1e8) + 239;
const int T = (1 << 17) + 239;
const ld pi = acos((ld)-1.0);

int n, l, k, bd, x[M], y[M];
int idx[M], sz_idx;

int divide(int a, int b) {
    if (a >= 0 || a % b == 0) {
        return a / b;
    }
    return -(abs(a) / b) - 1;
}

class Hasher {
public:
    size_t operator()(const pair<int, int>& key) const {
        return ((ll)(key.first + X) << 30LL) + (ll)key.second;
    }
};

struct helper {
    int R = 0;
    int l = 0;
    int r = 0;
    unordered_map<pair<int, int>, unordered_set<int>, Hasher> in;

    template <typename P>
    void upload(int x, int y, P pred) {
        int xi = divide(x, R);
        int yi = divide(y, R);
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                auto it = in.find(make_pair(xi + dx, yi + dy));
                if (it != in.end()) {
                    for (int i : it->second) {
                        if (pred(i)) {
                            idx[sz_idx++] = i;
                        }
                    }
                }
            }
        }
    }

    void add(int i) {
        int xi = divide(::x[i], R);
        int yi = divide(::y[i], R);
        in[make_pair(xi, yi)].insert(i);
    }

    void del(int i) {
        int xi = divide(::x[i], R);
        int yi = divide(::y[i], R);
        in[make_pair(xi, yi)].erase(i);
    }

    void remake(ld new_r) {
        R = ceil(new_r) + 1;
        in.clear();
        in.reserve(sz_idx * 2);
        for (int i = l; i < r; i++) {
            add(i);
        }
    }

    void move_left() {
        del(l);
        l++;
    }

    void move_right() {
        add(r);
        r++;
    }
};

ld dist(int i, int j) {
    return hypot(x[j] - x[i], y[j] - y[i]);
}

ld angle(int i, int j) {
    return atan2(y[j] - y[i], x[j] - x[i]);
}

int tree[T], add[T];

void build(int i, int l, int r) {
    tree[i] = 0;
    add[i] = 0;
    if (r - l == 1) {
        return;
    }
    int mid = (l + r) / 2;
    build(2 * i + 1, l, mid);
    build(2 * i + 2, mid, r);
}

inline void push(int i, int l, int r) {
    tree[i] += add[i];
    if (r - l > 1) {
        add[2 * i + 1] += add[i];
        add[2 * i + 2] += add[i];
    }
    add[i] = 0;
}

void upd(int i, int l, int r, int ql, int qr, int x) {
    push(i, l, r);
    if (r <= ql || qr <= l) {
        return;
    }
    if (ql <= l && r <= qr) {
        add[i] += x;
        push(i, l, r);
        return;
    }
    int mid = (l + r) / 2;
    upd(2 * i + 1, l, mid, ql, qr, x);
    upd(2 * i + 2, mid, r, ql, qr, x);
    tree[i] = max(tree[2 * i + 1], tree[2 * i + 2]);
}

void clear(int i, int l, int r) {
    push(i, l, r);
    if (tree[i] == 0) {
        return;
    }
    tree[i] = 0;
    if (r - l > 1) {
        int mid = (l + r) / 2;
        clear(2 * i + 1, l, mid);
        clear(2 * i + 2, mid, r);
    }
}

int s[M], cnt;
vector<pair<ld, int>> events;

bool check(int p, ld t) {
    if (sz_idx < k - 1) {
        return false;
    }
    bool ans = false;
    events.clear();
    events.reserve(sz_idx * 2);
    cnt = 0;
    for (int ii = 0; ii < sz_idx; ii++) {
        int i = idx[ii];
        ld d = dist(p, i);
        if (d > 2 * t) {
            continue;
        }
        ld a = angle(p, i);
        ld len = acos(min((ld)1.0, d / (2 * t)));
        ld lg = a - len;
        ld rg = a + len;
        if (lg < -pi) {
            lg += 2 * pi;
        }
        if (rg > pi) {
            rg -= 2 * pi;
        }
        events.emplace_back(lg, -1 - i);
        events.emplace_back(rg, 1 + i);
        if (lg > rg) {
            upd(0, 0, bd, max(0, i - l + 1), min(bd, i + 1), 1);
            s[cnt++] = i;
            if (tree[0] >= k - 1) {
                ans = true;
            }
        }
    }
    if (!ans) {
        sort(events.begin(), events.end());
        for (const auto& t : events) {
            if (t.second < 0) {
                int i = -t.second - 1;
                upd(0, 0, bd, max(0, i - l + 1), min(bd, i + 1), 1);
            } else {
                int i = t.second - 1;
                upd(0, 0, bd, max(0, i - l + 1), min(bd, i + 1), -1);
            }
            if (tree[0] >= k - 1) {
                ans = true;
            }
        }
    }
    for (int i = 0; i < cnt; i++) {
        upd(0, 0, bd, max(0, s[i] - l + 1), min(bd, s[i] + 1), -1);
    }
    return ans;
}

ld func(helper& hl, helper& hr, int p, ld pa) {
    auto is_good = [&](int i) {
        return dist(p, i) <= 2 * pa;
    };
    sz_idx = 0;
    hl.upload(x[p], y[p], is_good);
    hr.upload(x[p], y[p], is_good);
    if (!check(p, pa)) {
        return pa;
    }
    ld lg = 0;
    ld rg = pa;
    for (int i = 0; i < 70; i++) {
        ld mid = (lg + rg) / 2;
        if (check(p, mid)) {
            rg = mid;
        } else {
            lg = mid;
        }
    }
    hl.remake(2 * rg);
    hr.remake(2 * rg);
    return rg;
}

void solve() {
    cin >> n >> l >> k;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    bd = n - l + 1;

    int s = sqrt((ld)(l - 1) / (k - 1));
    ld ans = ((1e8 / s) * sqrt(2)) + 1;

    helper hl, hr;
    hl.remake(2 * ans);
    hr.remake(2 * ans);
    for (int i = 0; i < l; i++) {
        hr.move_right();
    }

    build(0, 0, bd);
    for (int i = 0; i < n; i++) {
        hr.move_left();

        // solve
        ans = min(ans, func(hl, hr, i, ans));

        if (i + 1 == n) {
            break;
        }
        if (i + l < n) {
            hr.move_right();
        }
        if (i - l + 1 >= 0) {
            hl.move_left();
        }
        hl.move_right();
    }
    cout << ans << "\n";
}

int main() {
#ifdef ONPC
    freopen("input", "r", stdin);
#endif
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(20);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}