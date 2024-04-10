#include <bits/stdc++.h>

using namespace std;

class dsu {
   public:
    vector<int> p;
    int n;

    dsu(int n) : n(n) {
        p.resize(n);
        iota(p.begin(), p.end(), 0);
    }

    inline int get(int x) { return (x == p[x] ? x : (p[x] = get(p[x]))); }

    inline bool unite(int x, int y) {
        x = get(x);
        y = get(y);
        if (x != y) {
            p[x] = y;
            return true;
        }
        return false;
    }
};

template <typename T>
class graph {
   public:
    struct edge {
        int from;
        int to;
        T cost;
    };

    vector<edge> edges;
    vector<vector<int> > g;
    int n;

    graph(int n) : n(n) { g.resize(n); }

    virtual void add(int from, int to, T cost) = 0;
};

template <typename T>
class undigraph : public graph<T> {
   public:
    using graph<T>::edges;
    using graph<T>::g;
    using graph<T>::n;

    undigraph(int n) : graph<T>(n) {}

    void add(int from, int to, T cost = 1) {
        assert(0 <= from && from < n && 0 <= to && to < n);
        g[from].push_back(edges.size());
        g[to].push_back(edges.size());
        edges.push_back({from, to, cost});
    }
};

#define real REAL

const int N = 4010;

long long total;
int n;
vector<long long> real[N], all[N];
char foo[N * N];
int a[N];

vector<int> dfs(const undigraph<int> &g, int v, int pr) {
    vector<int> here(1, v);
    for (int id : g.g[v]) {
        auto &e = g.edges[id];
        int to = e.from ^ e.to ^ v;
        if (to == pr) {
            continue;
        }
        vector<int> there = dfs(g, to, v);
        for (int i : there) {
            here.push_back(i);
        }
    }
    if (v != 0) {
        for (int i = 0; i < n; ++i) {
            a[i] = 0;
        }
        for (int i : here) {
            a[i] = 1;
        }
        long long h = 0;
        for (int k = 0; k < n; ++k) {
            h = h * 239017239 + a[k];
        }
        real[pr].push_back(h);
        real[v].push_back(total - h);
    }
    return here;
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%s", foo);
        fill(a, a + n, 0);
        int v = 0;
        for (int j = 0;; ++j) {
            if ('0' <= foo[j] && foo[j] <= '9') {
                v = v * 10 + foo[j] - '0';
            } else {
                if (foo[j] != ':') {
                    a[v - 1] = 1;
                }
                if (foo[j] == '-' || foo[j] == 0) {
                    long long h = 0;
                    for (int k = 0; k < n; ++k) {
                        h = h * 239017239 + a[k];
                        a[k] = 0;
                    }
                    all[i].push_back(h);
                }
                v = 0;
            }
            if (foo[j] == 0) {
                break;
            }
        }
    }
    total = 0;
    for (int k = 0; k < n; ++k) {
        total = total * 239017239 + 1;
    }
    vector<pair<int, int> > edges;
    for (int i = 0; i < n; ++i) {
        for (long long a : all[i]) {
            for (int j = i + 1; j < n; ++j) {
                for (long long b : all[j]) {
                    if (a + b == total) {
                        edges.emplace_back(i, j);
                    }
                }
            }
        }
    }
    int sz = edges.size();
    if (sz != n - 1) {
        puts("-1");
        return 0;
    }
    dsu d(n);
    for (auto &e : edges) {
        int x = e.first;
        int y = e.second;
        if (!d.unite(x, y)) {
            puts("-1");
            return 0;
        }
    }
    undigraph<int> g(n);
    for (auto &e : edges) {
        g.add(e.first, e.second);
    }
    dfs(g, 0, -1);
    for (int i = 0; i < n; ++i) {
        sort(all[i].begin(), all[i].end());
        sort(real[i].begin(), real[i].end());
        if (all[i].size() != real[i].size()) {
            puts("-1");
            return 0;
        }
        for (int j = 0; j < (int)all[i].size(); ++j) {
            if (all[i][j] != real[i][j]) {
                puts("-1");
                return 0;
            }
        }
    }
    printf("%d\n", n - 1);
    for (auto &e : edges) {
        printf("%d %d\n", e.first + 1, e.second + 1);
    }
    return 0;
}