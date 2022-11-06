#include <bits/stdc++.h>
#define fs first
#define se second
#define y0 qwertyuiop
#define y1 asdfghjkl

#ifdef imeimi
#define debug(...) printf(__VA_ARGS__)
#else
#define debug(...)
#endif

using namespace std;
typedef long long llong;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<llong, llong> pll;
typedef pair<ld, ld> pdd;

int n, m, k, q;
vector<pll> edge[100001];

int P[100001];
llong D[100001];

struct _edge {
    llong x, y, w;
    bool operator<(const _edge &p) const {
        return w < p.w;
    }
};

int S[100001];
vector<_edge> es;
int find(int x) {
    if (P[x]) return find(P[x]);
    return x;
}

int merge(int x, int y, llong d) {
    x = find(x);
    y = find(y);
    if (x == y) return 0;
    if (S[x] < S[y]) swap(x, y);
    P[y] = x;
    D[y] = d;
    S[x] += S[y];
    return 1;
}

llong query(int x, int y) {
    llong ans = 0;
    while (x != y) {
        if (D[x] < D[y]) swap(x, y);
        ans = max(ans, D[y]);
        y = P[y];
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cout.precision(30); cout << fixed;
    cin >> n >> m >> k >> q;
    for (int i = 0; i < m; ++i) {
        int x, y, w;
        cin >> x >> y >> w;
        edge[x].emplace_back(y, w);
        edge[y].emplace_back(x, w);
    }
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    for (int i = 1; i <= k; ++i) {
        P[i] = i;
        D[i] = 0;
        pq.emplace(0, i);
    }
    for (int i = k + 1; i <= n; ++i) {
        P[i] = -1;
        D[i] = 1e18;
    }
    while (!pq.empty()) {
        llong d, x;
        tie(d, x) = pq.top();
        pq.pop();
        if (D[x] != d) continue;
        for (pll i : edge[x]) {
            llong nd = d + i.se;
            if (nd < D[i.fs]) {
                D[i.fs] = nd;
                P[i.fs] = P[x];
                pq.emplace(nd, i.fs);
            }
        }
    }
    for (int x = 1; x <= n; ++x) {
        for (pll i : edge[x]) {
            if (i.fs < x) continue;
            if (P[x] == P[i.fs]) continue;
            es.push_back({ P[x], P[i.fs], D[x] + D[i.fs] + i.se });
        }
    }
    for (int i = 1; i <= k; ++i) {
        P[i] = 0;
        D[i] = 1e18;
        S[i] = 1;
    }
    sort(es.begin(), es.end());
    for (_edge i : es) {
        merge(i.x, i.y, i.w);
    }
    for (int i = 1; i <= q; ++i) {
        int x, y;
        cin >> x >> y;
        printf("%lld\n", query(x, y));
    }
    return 0;
}