#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

#define ll long long

const int maxn = 1 << 17;
const int inf = 2e8 + 10;

struct pt {
    int x, y;

    pt() {}
    pt(int x, int y) : x(x), y(y) {}

    bool operator< (const pt &p) {
        if (x != p.x) return x < p.x;
        return y < p.y;
    }
};

int n, k;
int distToMetro[maxn];
int p[maxn];
pt a[maxn], metro[maxn];
vector<int> list_x;


void reading() {
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &a[i].x, &a[i].y);
        a[i] = pt(a[i].x + a[i].y, a[i].x - a[i].y);
    }
    for (int i = 0; i < k; i++) {
        scanf("%d%d", &metro[i].x, &metro[i].y);
        metro[i] = pt(metro[i].x + metro[i].y, metro[i].x - metro[i].y);
    }
    // Plane is rotated by angle pi/4
}

vector<int> t[2 * maxn];

void build(int v, int tl, int tr) {
    if (tl == tr) {
        t[v] = vector<int>(1, metro[tl].y);
        return;
    }
    int tm = (tl + tr) >> 1;
    build(v * 2, tl, tm);
    build(v * 2 + 1, tm + 1, tr);
    t[v].resize(t[v * 2].size() + t[v * 2 + 1].size());
    merge(t[v * 2].begin(), t[v * 2].end(), t[v * 2 + 1].begin(), t[v * 2 + 1].end(), t[v].begin());
}

void buildTree() {
    if (!k) return;
    sort(metro, metro + k);
    for (int i = 0; i < k; i++) list_x.push_back(metro[i].x);
    build(1, 0, k - 1);
}

bool get(int v, int tl, int tr, int l, int r, int y1, int y2) {
    if (l > r) return 0;
    if (tl == l && tr == r) {
        int k = lower_bound(t[v].begin(), t[v].end(), y1) - t[v].begin();
        return k < t[v].size() && t[v][k] <= y2;
    }
    int tm = (tl + tr) >> 1;
    return get(v * 2, tl, tm, l, min(r, tm), y1, y2) || get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, y1, y2);
}

bool get(int x1, int x2, int y1, int y2) {
    if (x1 > x2 || y1 > y2) return 0;
    int l = lower_bound(list_x.begin(), list_x.end(), x1) - list_x.begin();
    int r = lower_bound(list_x.begin(), list_x.end(), x2 + 1) - list_x.begin() - 1;
    if (l == list_x.size()) return 0;
    return get(1, 0, k - 1, l, r, y1, y2);
}

bool cmp(int i, int j) {
    return distToMetro[i] < distToMetro[j];
}

void findNearestMetroes() {
    for (int i = 0; i < n; i++) {
        int l = 0, r = inf;
        while (r - l > 1) {
            int m = (l + r) >> 1;
            if (get(a[i].x - m, a[i].x + m, a[i].y - m, a[i].y + m)) r = m;
            else l = m;
        }
        if (get(a[i].x - l, a[i].x + l, a[i].y - l, a[i].y + l)) distToMetro[i] = l;
        else distToMetro[i] = r;
        p[i] = i;
    }
    sort(p, p + n, cmp);
    
    vector<int> buf1(n);
    for (int i = 0; i < n; i++) buf1[i] = distToMetro[i];
    for (int i = 0; i < n; i++) distToMetro[i] = buf1[p[i]];

    vector<pt> buf2(n);
    for (int i = 0; i < n; i++) buf2[i] = a[i];
    for (int i = 0; i < n; i++) a[i] = buf2[p[i]];
}

bool ok(int x) {
    int mnx = -inf, mxx = inf, mny = -inf, mxy = inf;

    bool f = 0;
    for (int i = n - 1; i >= -1; i--) {
        if (i == -1) {
            return 1;
        }
        if (distToMetro[i] <= x && k) {
            if (i == -1) return 1;
            int m = x - distToMetro[i];
            f |= get(mnx - m, mxx + m, mny - m, mxy + m);
            if (f) return 1;
        }
        mnx = max(mnx, a[i].x - x);
        mxx = min(mxx, a[i].x + x);
        mny = max(mny, a[i].y - x);
        mxy = min(mxy, a[i].y + x);
        if (!(mnx <= mxx && mny <= mxy)) return 0;
    }
    return 0;
}

int solve() {
    int l = 0, r = inf;
    while (r - l > 1) {
        int m = (l + r) >> 1;
        if (ok(m)) r = m;
        else l = m;
    }
    if (ok(l)) return l;
    return r;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    reading();
    buildTree();
    findNearestMetroes();
    cout << solve() << endl;

    return 0;
}