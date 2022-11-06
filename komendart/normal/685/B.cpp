#include <bits/stdc++.h>

using namespace std;

struct Set {
    multimap< pair<int, int>, int > a;
    set< pair<int, int> > b;

    Set() {}
};

const int maxn = 3e5 + 5;

vector<int> graph[maxn];
int answer[maxn];
int sz[maxn];

void dfs1(int v, int p=-1) {
    sz[v] = 1;
    for (auto u: graph[v]) {
        if (u != p) {
            dfs1(u, v);
            sz[v] += sz[u];
        }
    }
}

Set* dfs(int v, int p=-1) {
    Set *q = new Set();
    int m = 0;
    for (auto u: graph[v]) {
        if (u != p) {
            Set *x = dfs(u, v);
            if (x->a.size() > q->a.size()) swap(x, q);
            for (auto i: x->a) q->a.insert(i);
            for (auto i: x->b) q->b.insert(i);
            m = max(m, sz[u]);
        }
    }
    q->a.insert({{2 * sz[v], 2 * m}, v});
    q->b.insert({2 * m, v});
    while (!q->a.empty() && q->a.begin()->first.first < sz[v]) {
        auto p = q->a.begin();
        q->b.erase({p->first.second, p->second});
        q->a.erase(p);
    }
    answer[v] = q->b.begin()->second;
    return q;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, q;
    cin >> n >> q;
    for (int i = 2; i <= n; i++) {
        int p; cin >> p;
        graph[p].push_back(i);
        graph[i].push_back(p);
    }

    dfs1(1);
    dfs(1);
    for (int i = 1; i <= q; i++) {
        int v; cin >> v;
        cout << answer[v] << '\n';
    }
}