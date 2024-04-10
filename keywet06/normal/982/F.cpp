#include <bits/stdc++.h>

const int N = 100111, inf = 1000111222;

int n, m, cur, used[N];
std::vector<int> g[N];
std::vector<int> cycle;

void wa() {
    printf("-1\n");
    exit(0);
}

double st = clock();

bool is_tl() {
    if ((clock() - st) / CLOCKS_PER_SEC > 0.9) return true;
    return false;
}

bool dfs(int v) {
    used[v] = cur;
    for (int to : g[v]) {
        if (used[to] == cur + 1) continue;
        if (used[to] == cur || dfs(to)) {
            cycle.push_back(v);
            return true;
        }
    }
    used[v] = cur + 1;
    return false;
}

std::vector<int> perm;

bool has_cycle(int v = 0) {
    cur += 2;
    cycle.clear();
    used[v] = cur + 1;
    for (int i : perm) {
        if (used[i] < cur) {
            if (dfs(i)) {
                return true;
            }
        }
    }
    return false;
}

int cnt[N];

int main() {
    srand(time(NULL));
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) perm.push_back(i);
    std::random_shuffle(perm.begin(), perm.end());
    for (int i = 0; i < m; ++i) {
        int u, v;
        scanf("%d%d", &u, &v);
        g[u].push_back(v);
    }
    has_cycle();
    std::vector<int> p = cycle;
    std::random_shuffle(p.begin(), p.end());
    int it = 0;
    for (int v : p) {
        if (cnt[v] < it) continue;
        if (!has_cycle(v)) {
            printf("%d\n", v);
            return 0;
        }
        ++it;
        for (int v : cycle) ++cnt[v];
        if (is_tl()) wa();
    }
    wa();
    return 0;
}