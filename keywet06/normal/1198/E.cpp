#include <bits/stdc++.h>

using namespace std;

const int M = 100 + 5, inf = 1e9;

struct edge {
    int v, c, next;
} e[M * M * 2];

bool g[M][M];

int n, m, tot, cntx, cnty, S, T;
int head[M * 2], cur[M * 2], h[M * 2];
int s[M][4];

vector<int> x, y;

void insert_edge(int u, int v, int c) {
    e[tot] = {v, c, head[u]};
    head[u] = tot++;
    e[tot] = {u, 0, head[v]};
    head[v] = tot++;
}

bool bfs() {
    memset(h, -1, sizeof(h));
    queue<int> que;
    que.push(S);
    h[S] = 0;
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (int i = head[u]; i != -1; i = e[i].next) {
            int v = e[i].v;
            int c = e[i].c;
            if (c && h[v] == -1) {
                h[v] = h[u] + 1;
                if (v == T) {
                    return true;
                }
                que.push(v);
            }
        }
    }
    return false;
}

int dfs(int u, int flow) {
    if (u == T) {
        return flow;
    }
    int res = flow;
    for (int &i = cur[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        int c = e[i].c;
        if (h[v] == h[u] + 1 && c) {
            int aug = dfs(v, min(res, c));
            res -= aug;
            e[i].c -= aug;
            e[i ^ 1].c += aug;
            if (!res) {
                break;
            }
        }
    }
    return flow - res;
}

int maxflow() {
    int flow = 0;
    while (bfs()) {
        memcpy(cur, head, sizeof(head));
        flow += dfs(S, inf);
    }
    return flow;
}

int main() {
    scanf("%d%d", &n, &m);
    if (!m) {
        puts("0");
        return 0;
    }
    for (int i = 1; i <= m; ++i) {
        scanf("%d%d%d%d", &s[i][0], &s[i][2], &s[i][1], &s[i][3]);
        x.push_back(s[i][0]);
        x.push_back(++s[i][1]);
        y.push_back(s[i][2]);
        y.push_back(++s[i][3]);
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    x.resize(unique(x.begin(), x.end()) - x.begin());
    y.resize(unique(y.begin(), y.end()) - y.begin());
    for (int i = 1; i <= m; ++i) {
        for (size_t x0 = 0; x0 + 1 < x.size(); ++x0) {
            for (size_t y0 = 0; y0 + 1 < y.size(); ++y0) {
                if (x[x0] >= s[i][0] && x[x0 + 1] <= s[i][1] &&
                    y[y0] >= s[i][2] && y[y0 + 1] <= s[i][3]) {
                    g[x0 + 1][y0 + 1] = true;
                }
            }
        }
    }
    cntx = x.size() - 1;
    cnty = y.size() - 1;
    S = cntx + cnty + 1;
    T = S + 1;
    memset(head, -1, sizeof(head));
    for (int i = 1; i <= cntx; ++i) {
        insert_edge(S, i, x[i] - x[i - 1]);
    }
    for (int i = 1; i <= cnty; ++i) {
        insert_edge(cntx + i, T, y[i] - y[i - 1]);
    }
    for (int i = 1; i <= cntx; ++i) {
        for (int j = 1; j <= cnty; ++j) {
            if (g[i][j]) {
                insert_edge(i, cntx + j, inf);
            }
        }
    }
    printf("%d\n", maxflow());
    return 0;
}