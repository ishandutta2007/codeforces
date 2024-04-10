#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int, int, int> T;

int n, m, q, ans[202020];
pair<int, int> edges[201010];
vector<T> Q[201010];
vector<pair<int, int>> X;

struct SEG {
    int tree[201010];

    void init(int n) {
        for (int i = 0; i <= n; i++) tree[i] = 0;
    }
    void update(int a, int x) {
        for (; a < 201010; a += a & -a) tree[a] += x;
    }
    int query(int l, int r) {
        int val = 0;
        for (; r; r -= r & -r) val += tree[r];
        for (--l; l; l -= l & -l) val -= tree[l];
        return val;
    }
} Seg;

struct DSU {
    int par[101010];
    set<int> St[101010];

    void init(int n) {
        for (int i = 1; i <= n; i++) {
            par[i] = i;
            St[i].clear(); St[i].insert(i);
        }
    }
    int Find(int a) {
        return par[a] = (par[a] == a) ? a : (Find(par[a]));
    }
    void Union(int a, int b, int i) {
        a = Find(a); b = Find(b);
        if (a == b) return;
        if (St[a].size() < St[b].size()) {
            swap(a, b);
        }
        par[b] = a;
        for (int x : St[b]) {
            if (St[a].find(x - 1) != St[a].end()) {
                X.emplace_back(i, x - 1);
            }
            if (St[a].find(x + 1) != St[a].end()) {
                X.emplace_back(i, x);
            }
        }
        for (int x : St[b]) {
            St[a].insert(x);
        }
        St[b].clear();
    }
} D;

void solve() {
    cin >> n >> m >> q;
    D.init(n); X.clear();
    for (int i = 1; i <= m; i++) {
        int x, y; cin >> x >> y;
        edges[i] = { x, y };
        D.Union(x, y, i);
    }
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        Q[m / 2].emplace_back(i, l, r, 0, m);
    }
    int IT = 20;
    vector<T> V;
    while (--IT) {
        int p = 0;
        Seg.init(n);
        for (int t = 1; t <= m + 1; t++) {
            for (auto [i, l, r, lo, hi] : Q[t - 1]) {
                if (lo == hi) {
                    ans[i] = t - 1;
                    continue;
                }
                if (l == r || Seg.query(l, r - 1) == r - l) {
                    V.emplace_back(i, l, r, lo, (lo + hi) / 2);
                }
                else V.emplace_back(i, l, r, 1 + (lo + hi) / 2, hi);
            }
            Q[t - 1].clear();
            while (p < X.size() && X[p].first == t) {
                auto [a, b] = X[p]; ++p;
                Seg.update(b, 1);
            }
        }
        for (auto [i, l, r, lo, hi] : V) {
            Q[(lo + hi) / 2].emplace_back(i, l, r, lo, hi);
        }
        V.clear();
    }
    for (int i = 0; i < q; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';
}
int main() {
    cin.tie(0); ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
        solve();
    }
}