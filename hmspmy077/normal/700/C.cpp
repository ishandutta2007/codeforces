#include <algorithm>
#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
#include <utility>

const int N = 1000;
const int M = 30000;

int n, m, s, t, x[M], y[M], w[M], head[N], edge_count, to[M + M], next[M + M], weight[M + M];
int delta[N];
bool visited[N], used[M];
std::vector<int> candidates;

void add_edge(int u, int v, int w)
{
    to[edge_count] = v;
    next[edge_count] = head[u];
    weight[edge_count] = w;
    head[u] = edge_count ++;
}

bool dfs1(int u)
{
    visited[u] = true;
    bool has = u == t;
    for (int it = head[u]; ~it; it = next[it]) {
        int v = to[it];
        if (used[it >> 1]) {
            continue;
        }
        used[it >> 1] = true;
        if (!visited[v]) {
            if (dfs1(v)) {
                has = true;
                candidates.push_back(it >> 1);
            }
        }
    }
    return has;
}

bool reach;
std::pair<int, int> minimum;

std::pair<int, bool> dfs2(int u)
{
    visited[u] = true;
    bool has = u == t;
    if (has) {
        reach = true;
    }
    int sum = 0;
    for (int it = head[u]; ~it; it = next[it]) {
        int v = to[it];
        if (used[it >> 1]) {
            continue;
        }
        used[it >> 1] = true;
        if (!visited[v]) {
            auto ref = dfs2(v);
            if (ref.first == 0 && ref.second) {
                minimum = std::min(minimum, {weight[it], it >> 1});
            }
            sum += ref.first;
            if (ref.second) {
                has = true;
            }
        } else {
            sum ++;
            delta[v] --;
        }
    }
    sum += delta[u];
    return {sum, has};
}

int main()
{
    scanf("%d%d%d%d", &n, &m, &s, &t);
    s --;
    t --;
    edge_count = 0;
    memset(head, -1, sizeof(head));
    for (int i = 0; i < m; ++ i) {
        scanf("%d%d%d", x + i, y + i, w + i);
        x[i] --;
        y[i] --;
        add_edge(x[i], y[i], w[i]);
        add_edge(y[i], x[i], w[i]);
    }
    memset(visited, 0, sizeof(visited));
    memset(used, 0, sizeof(used));
    dfs1(s);
    if (candidates.empty()) {
        printf("0\n0\n\n");
        return 0;
    }
    std::pair<int, std::vector<int>> best(INT_MAX, {});
    for (auto&& c : candidates) {
        edge_count = 0;
        memset(head, -1, sizeof(head));
        for (int i = 0; i < m; ++ i) {
            if (i != c) {
                add_edge(x[i], y[i], w[i]);
                add_edge(y[i], x[i], w[i]);
            } else {
                edge_count += 2;
            }
        }
        memset(visited, 0, sizeof(visited));
        memset(used, 0, sizeof(used));
        memset(delta, 0, sizeof(delta));
        reach = false;
        minimum = std::make_pair(INT_MAX, -1);
        dfs2(s);
        if (!reach) {
            best = std::min(best, {w[c], {c}});
        } else if (minimum.first < INT_MAX) {
            best = std::min(best, {w[c] + minimum.first, {c, minimum.second}});
        }
    }
    if (best.first < INT_MAX) {
        printf("%d\n%d\n", best.first, (int)best.second.size());
        for (auto&& x : best.second) {
            printf("%d ", x + 1);
        }
        puts("");
    } else {
        puts("-1");
    }
}