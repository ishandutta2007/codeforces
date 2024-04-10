#include <cstdio>
#include <cstring>
#include <vector>

const int N = 300000;

int d[N], cur[N], head[N], to[N << 1], next[N << 1];
bool visited[N];
std::vector<int> ans;

void dfs(int pre, int u)
{
    visited[u] = true;
    for (int it = head[u]; ~it; it = next[it]) {
        if (!visited[to[it]]) {
            dfs(it, to[it]);
        }
    }
    if (~d[u] && ~pre && d[u] != cur[u]) {
        ans.push_back(pre);
        cur[to[pre]] ^= 1;
        cur[to[pre ^ 1]] ^= 1;
    }
}

int main()
{
#ifdef LOCAL_JUDGE
    freopen("B.in", "r", stdin);
#endif
    int n, m;
    while (scanf("%d%d", &n, &m) == 2) {
        for (int i = 0; i < n; ++ i) {
            scanf("%d", d + i);
        }
        memset(head, -1, sizeof(*head) * n);
        for (int i = 0; i < m << 1; ++ i) {
            scanf("%d", to + i);
            to[i] --;
        }
        for (int i = 0; i < m << 1; ++ i) {
            next[i] = head[to[i ^ 1]];
            head[to[i ^ 1]] = i;
        }
        memset(visited, 0, sizeof(*visited) * n);
        ans.clear();
        memset(cur, 0, sizeof(*cur) * n);
        for (int i = 0; i < n; ++ i) {
            if (!visited[i] && d[i] == -1) {
                dfs(-1, i);
            }
        }
        for (int i = 0; i < n; ++ i) {
            if (!visited[i]) {
                dfs(-1, i);
            }
        }
        bool ok = true;
        for (int i = 0; i < n; ++ i) {
            if (~d[i]) {
                ok &= d[i] == cur[i];
            }
        }
        if (ok) {
            printf("%d\n", (int)ans.size());
            for (auto&& e : ans) {
                printf("%d\n", 1 + (e >> 1));
            }
        } else {
            puts("-1");
        }
    }
}