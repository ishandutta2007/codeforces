#include <bits/stdc++.h>

typedef long long int64;

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }

const int N = 220000;
const int M = N << 2;
const int64 INF = 1e18;

int n, m, ans;

int64 sm[N], a[N];
int64 rmq[M], dd[M];

map<int64, int> mm;

pair<int64, int64> b[N];

void build(int v, int tl, int tr) {
    if (tl + 1 == tr) {
        rmq[v] = sm[tl];
        return;
    }
    int m = (tl + tr) >> 1;
    build(v * 2 + 1, tl, m);
    build(v * 2 + 2, m, tr);
    rmq[v] = min(rmq[v * 2 + 1], rmq[v * 2 + 2]);
}

void add(int v, int tl, int tr, int l, int r, int64 d) {
    if (r <= tl || tr <= l) return;
    if (l <= tl && tr <= r) {
        rmq[v] += d;
        dd[v] += d;
        return;
    }
    int m = (tl + tr) >> 1;
    add(v * 2 + 1, tl, m, l, r, d);
    add(v * 2 + 2, m, tr, l, r, d);
    rmq[v] = min(rmq[v * 2 + 1], rmq[v * 2 + 2]) + dd[v];
}

int64 get(int v, int tl, int tr, int l, int r) {
    if (r <= tl || tr <= l) return INF;
    if (l <= tl && tr <= r) return rmq[v];
    int m = (tl + tr) >> 1;
    return min(get(v * 2 + 1, tl, m, l, r), get(v * 2 + 2, m, tr, l, r)) +
           dd[v];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%lld", a + i);
    for (int i = 0; i < m; ++i) scanf("%lld", &b[i].first);
    for (int i = 0; i < m; ++i) scanf("%lld", &b[i].second);
    sort(b, b + m);
    int cur = 0;
    for (int i = n - 1; i >= 0; --i) {
        while (cur < m && b[cur].first <= a[i]) {
            mm[b[cur].first] = i;
            ++cur;
        }
    }
    sm[0] = a[0];
    for (int i = 1; i < n; ++i) sm[i] = sm[i - 1] + a[i];
    build(0, 0, n);
    sort(b, b + m, cmp);
    for (int i = 0; i < m; ++i) {
        if (!mm.count(b[i].first)) continue;
        int x = mm[b[i].first];
        if (get(0, 0, n, x, n) >= b[i].second) {
            ++ans;
            add(0, 0, n, x, n, -b[i].second);
        }
    }
    cout << ans << "\n";
    return 0;
}