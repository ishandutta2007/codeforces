#include <bits/stdc++.h>

using namespace std;

const int maxn = 205;
const int INF = 1e8;

struct Edge {
    int to, flow, cap;
};

int N, st, fin;
vector<Edge> edges;
vector<int> graph[maxn];
char used[maxn];

void add_edge(int a, int b, int c) {
    int ind = edges.size();
    graph[a].push_back(ind);
    graph[b].push_back(ind ^ 1);
    edges.push_back({b, 0, c});
    edges.push_back({a, 0, 0});
}

int dfs(int v, int mincap) {
    if (v == fin || mincap == 0) {
        return mincap;
    }
    used[v] = true;
    for (auto ind: graph[v]) {
        if (used[edges[ind].to] || edges[ind].cap == edges[ind].flow) continue;
        int delta = dfs(edges[ind].to, min(mincap, edges[ind].cap - edges[ind].flow));
        if (delta) {
            edges[ind].flow += delta;
            edges[ind ^ 1].flow -= delta;
            return delta;
        }
    }
    return 0;
}

int maxFlow() {
    int ans = 0;
    while (int delta=dfs(st, INF)) {
        ans += delta;
        memset(used, 0, N);
    }
    return ans;
}

bool is_prime(int n) {
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return n != 1;
}

void dfs2(int v, vector<int> &ans) {
    used[v] = true;
    ans.push_back(v);
    for (auto ind: graph[v]) {
        int to = edges[ind].to;
        if (to == st || to == fin || used[to]) continue;
        if (edges[ind].flow != 0) {
            dfs2(to, ans);
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    N = n + 2;
    st = 0, fin = N - 1;
    for (int i = 1; i <= n; ++i) {
        if (a[i] % 2 == 0) {
            add_edge(st, i, 2);
        } else {
            add_edge(i, fin, 2);
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (a[i] % 2 == 1) continue;
        for (int j = 1; j <= n; ++j) {
            if (is_prime(a[i] + a[j])) {
                add_edge(i, j, 1);
            }
        }
    }
    if (maxFlow() != n) {
        cout << "Impossible\n";
        return 0;
    }

    memset(used, 0, n + 1);
    vector< vector<int> > ans;
    for (int i = 1; i <= n; ++i) {
        if (used[i]) continue;
        vector<int> tmp;
        dfs2(i, tmp);
        ans.push_back(tmp);
    }
    cout << ans.size() << '\n';
    for (auto &v: ans) {
        cout << v.size();
        for (auto i: v) {
            cout << ' ' << i;
        }
        cout << '\n';
    }
}