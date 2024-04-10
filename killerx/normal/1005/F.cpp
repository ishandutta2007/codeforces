#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 2e5 + 5;

int n, m, K;
std::map <int, int> id[mxn];
std::vector <int> adj[mxn];
int dis[mxn];
std::vector <int> vec[mxn];
int ptr[mxn];

void bfs(int S) {
    rep(i, n) dis[i] = -1;
    dis[S] = 0;
    static std::vector <int> que;
    que.push_back(S);
    rep(i, que.size()) {
        int u = que[i];
        for (int v : adj[u]) {
            if (dis[v] == -1) {
                dis[v] = dis[u] + 1;
                que.push_back(v);
            }
        }
    }
}

int main() {
    scanf("%d %d %d", &n, &m, &K);
    rep(i, m) {
        int u, v;
        scanf("%d %d", &u, &v);
        -- u, -- v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        id[u][v] = i;
        id[v][u] = i;
    }
    bfs(0);
    int tot = 1;
    rep(i, n) if (i) {
        for (int j : adj[i]) {
            if (dis[j] + 1 == dis[i]) {
                vec[i].push_back(j);
            }
        }
        ptr[i] = 0;
        tot = std::min(1LL * K, 1LL * tot * (int) vec[i].size());
    }
    printf("%d\n", tot);
    while (tot --) {
        std::vector <int> ans(m);
        rep(i, n) if (i) ans[id[vec[i][ptr[i]]][i]] = 1;
        rep(i, m) putchar(ans[i] + '0');
        putchar('\n');
        if (tot) {
            int i = n - 1;
            while (ptr[i] == (int) vec[i].size() - 1) {
                ptr[i] = 0;
                -- i;
            }
            ++ ptr[i];
        }
    }
	return 0;
}