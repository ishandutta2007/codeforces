// Retired?
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = long unsigned long;
using ld = double long;

int n, k;
int a[1 << 20];
string par;

struct edge {
    int u, v;

    bool operator< (const edge& o) const {
        return tie(u, v) < tie(o.u, o.v);
    }
};

bool cmp_weight(const edge& x, const edge& y) {
    return a[x.u] + a[x.v] > a[y.u] + a[y.v];
}

const int LEFT = 8;
const int BOUND = 4;
const int QUEUED = 2;
const int STALE = 1;

struct spfa {
    struct sedge {
        int y, w;
    };

    int n;
    vector<vector<sedge>> e;
    string tip;
    vector<int> pre;

    spfa(int n) : n(n), e(n), tip(n, 0), pre(n, -1) {}

    void add_edge(int x, int y, int d, bool rev) {
        e[x].push_back({y, d});
        if (rev) {
            tip[x] |= BOUND;
            tip[y] |= BOUND;
        }
    }

    void mark_left(int x) {
        tip[x] |= LEFT;
    }

    vector<edge> run() {
        vector<int> d(n, -1e9), q(n);
        int qs = 0, qe = 0;
        for (int i=0; i<n; i++) {
            if ((tip[i] & LEFT) && !(tip[i] & BOUND)) {
                d[i] = 0;
                q[qe++] = i;
                tip[i] |= QUEUED;
            }
        }

        while (qs != qe) {
            int x = q[qs++];
            if (qs == n) qs = 0;
            tip[x] ^= QUEUED;
            for (auto [y, w] : e[x]) {
                if (d[x] + w > d[y]) {
                    d[y] = d[x] + w;
                    pre[y] = x;
                    if (!(tip[y] & QUEUED)) {
                        if (tip[y] & STALE) {
                            q[qe++] = y;
                            if (qe == n) qe = 0;
                        } else {
                            qs--;
                            if (qs == -1) qs = n-1;
                            q[qs] = y;
                        }
                        tip[y] |= QUEUED | STALE;
                    }
                }
            }
        }

        int bi = -1;
        for (int i=0; i<n; i++) {
            if (!(tip[i] & LEFT) && !(tip[i] & BOUND)) {
                if (bi == -1 || d[i] > d[bi]) {
                    bi = i;
                }
            }
        }

        vector<edge> dif;
        for (int y = bi; pre[y] != -1; y = pre[y]) {
            dif.push_back({y, pre[y]}); 
        }

        return dif;
    }
};

int main() {
    ios::sync_with_stdio(!cin.tie(0));

    cin >> n >> k;
    const int N = 1 << n;
    for (int i=0; i<N; i++) cin >> a[i];
    par = string(N, 0);

    vector<edge> b;
    b.reserve(N * n / 2);
    k = min(k, N / 2);
    for (int x=0; x<N; x++) {
        if (x) par[x] = par[x - (x & -x)] ^ 1;

        if (par[x]) {
            for (int j=0; j<n; j++) {
                int y = x ^ (1 << j);
                b.push_back({x, y});
            }
        }
    }

    int chunk = min<int>(100000, b.size());
    nth_element(b.begin(), b.begin() + chunk, b.end(), cmp_weight);
    sort(b.begin(), b.begin() + chunk, cmp_weight);

    set<edge> active;

    for (int i=0; i<k; i++) {
        set<int> nodes;
        set<edge> candidates;
        for (auto [u, v] : active) {
            nodes.insert(u);
            nodes.insert(v);
        }

        auto blocked = nodes;

        vector<int> nodes_later;
        for (int x : nodes) {
            for (int i=0; i<n; i++) {
                int y = x ^ (1 << i);
                int x1 = x, y1 = y;
                if (!par[x]) {
                    swap(x1, y1);
                }
                candidates.insert({x1, y1});
                nodes_later.push_back(x1);
                nodes_later.push_back(y1);
            }
        }

        for (int x : nodes_later) nodes.insert(x);

        for (auto [x, y] : b) {
            if (!blocked.count(x) && !blocked.count(y)) {
                candidates.insert({x, y});
                nodes.insert(x);
                nodes.insert(y);
                break;
            }
        }

        // run spfa
        spfa eng(nodes.size());
        vector<int> nodes_v(begin(nodes), end(nodes));

        auto ubaci = [&](int u, int v, int d, bool rev) {
            auto uit = lower_bound(begin(nodes_v), end(nodes_v), u) - begin(nodes_v);
            auto vit = lower_bound(begin(nodes_v), end(nodes_v), v) - begin(nodes_v);
            eng.add_edge(uit, vit, d, rev);
        };

        for (auto [u, v] : active) {
            candidates.erase({u, v});
            ubaci(v, u, -a[u]-a[v], true);
        }

        for (auto [u, v] : candidates) {
            ubaci(u, v, a[u] + a[v], false);
        }

        for (int i=0; i<(int)nodes_v.size(); i++) {
            int x = nodes_v[i];
            if (par[x]) {
                eng.mark_left(i);
            }
        }

        auto dif = eng.run();
        for (auto [u, v] : dif) {
            edge e = {nodes_v[u], nodes_v[v]};
            if (!par[e.u]) swap(e.u, e.v);
            if (active.count(e)) {
                active.erase(e);
            } else {
                active.insert(e);
            }
        }
    }

    int sol = 0;
    for (auto [x, y] : active) {
        sol += a[x] + a[y];
    }

    cout << sol << "\n";
}