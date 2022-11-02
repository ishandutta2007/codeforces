#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

const int N = (int)2e5 + 5;
const double O = 1e9 + 7;

struct node {
    int64 x, y;
    node operator+(node p) { return {x + p.x, y + p.y}; }
    node operator-(node p) { return {x - p.x, y - p.y}; }
    int64 operator*(node p) { return x * p.y - y * p.x; }
    int64 operator|(node p) { return x * p.x + y * p.y; }
    bool inline operator==(const node &rhs) const {
        return x == rhs.x && y == rhs.y;
    }
};

struct line {
    node v;
    int64 c;
    line(node p, node q) : v(q - p), c(v * p) {}
    bool is_on(node p) { return v * p == c; }
};

int n, k;
node p[N];

line find_line() {
    for (int i = 0; i < 3; ++i) {
        for (int j = i + 1; j < 3; ++j) {
            line l(p[i], p[j]);
            int cnt = 0;
            for (int t = 0; t < n; ++t) {
                if (l.is_on(p[t])) ++cnt;
            }
            if (cnt == n - 1) return l;
        }
    }
    exit(0);
}

int main() {
    cin >> n >> k, --k;
    for (int i = 0; i < n; ++i) cin >> p[i].x >> p[i].y;
    node save = p[k];
    line l = find_line();
    for (int i = 0; i < n; ++i) {
        if (!l.is_on(p[i])) {
            swap(p[i], p[n - 1]);
            break;
        }
    }
    --n;
    auto proj_cmp = [&](node p, node q) { return (l.v | p) < (l.v | q); };
    sort(p, p + n, proj_cmp);
    auto dist = [&](int i, int j) {
        return hypot(p[i].x - p[j].x, p[i].y - p[j].y);
    };
    auto cover = [&](int l, int r) {
        return min(dist(l, n), dist(r, n)) + dist(l, r);
    };
    for (int i = 0; i <= n; ++i) {
        if (p[i] == save) {
            k = i;
            break;
        }
    }
    double ans = O;
    if (k == n) {
        ans = cover(0, n - 1);
    } else {
        for (int i = 0; i <= k; ++i) {
            double d =
                min(dist(k, i) + dist(n - 1, n), dist(k, n - 1) + dist(i, n)) +
                dist(i, n - 1);
            if (i > 0) d += cover(0, i - 1);
            ans = min(ans, d);
        }
        for (int i = k; i < n; ++i) {
            double d = min(dist(k, i) + dist(0, n), dist(k, 0) + dist(i, n)) +
                       dist(0, i);
            if (i < n - 1) d += cover(i + 1, n - 1);
            ans = min(ans, d);
        }
    }
    printf("%.15g\n", ans);
    return 0;
}