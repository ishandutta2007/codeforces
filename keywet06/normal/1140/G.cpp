#include <bits/stdc++.h>

using int64 = long long;

const int N = 3e5 + 7;
const int64 inf = (int64)(1e18) + 7;

std::vector<int> t[N];
std::vector<std::pair<int, int64> > g[2 * N];

bool die[N];
int sz[N];

void dfs(int v, int pr) {
    sz[v] = 1;
    for (int to : t[v]) {
        if (to != pr && !die[to]) dfs(to, v), sz[v] += sz[to];
    }
}

int centr(int v, int pr, int need) {
    for (int to : t[v]) {
        if (to != pr && !die[to] && sz[to] > need / 2) return centr(to, v, need);
    }
    return v;
}

const int LG = 20;

int who[2 * N][LG][2];
int64 ans[2 * N][LG][2];

void prec(int v, int lg, int type) {
    std::priority_queue<std::pair<int64, int>, std::vector<std::pair<int64, int> >,
                        std::greater<std::pair<int64, int> > >
        Que;
    Que.push({0, v});
    ans[v][lg][type] = 0;
    int root = v;
    while (!Que.empty()) {
        int v = Que.top().second;
        int64 dist = Que.top().first;
        Que.pop();
        if (dist > ans[v][lg][type]) continue;
        who[v][lg][type] = root;
        for (auto c : g[v]) {
            int to = c.first;
            if (die[to / 2]) continue;
            if (ans[to][lg][type] > ans[v][lg][type] + c.second) {
                ans[to][lg][type] = ans[v][lg][type] + c.second;
                Que.push({ans[to][lg][type], to});
            }
        }
    }
}

void build(int v, int lg) {
    dfs(v, -1);
    int x = centr(v, -1, sz[v]);
    prec(2 * x, lg, 0);
    prec(2 * x + 1, lg, 1);
    die[x] = true;
    for (int to : t[x]) {
        if (!die[to]) build(to, lg + 1);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int n;
    std::cin >> n;
    for (int i = 0; i < 2 * n; ++i) {
        for (int j = 0; j < LG; ++j) {
            for (int t = 0; t < 2; ++t) ans[i][j][t] = inf;
        }
    }
    for (int i = 0; i < n; ++i) {
        int64 x;
        std::cin >> x;
        g[2 * i].push_back({2 * i + 1, x});
        g[2 * i + 1].push_back({2 * i, x});
    }
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        std::cin >> a >> b;
        int64 w1, w2;
        std::cin >> w1 >> w2;
        --a, --b;
        t[a].push_back(b);
        t[b].push_back(a);
        g[2 * a].push_back({2 * b, w1});
        g[2 * b].push_back({2 * a, w1});
        g[2 * a + 1].push_back({2 * b + 1, w2});
        g[2 * b + 1].push_back({2 * a + 1, w2});
    }
    build(0, 0);
    int q, a, b;
    std::cin >> q;
    while (q--) {
        std::cin >> a >> b, --a, --b;
        int64 out = inf;
        for (int i = 0; i < LG; ++i) {
            for (int t = 0; t < 2; ++t) {
                if (who[a][i][t] == who[b][i][t]) out = std::min(out, ans[a][i][t] + ans[b][i][t]);
            }
        }
        std::cout << out << '\n';
    }
    return 0;
}