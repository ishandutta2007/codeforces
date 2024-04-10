#include <bits/stdc++.h>

using int64 = long long;

const int P = 998244353;
const int N = 505;
const int M = N << 2;

struct edge {
    int to, next;
};

int head[N], tot;
int dis[N][N];
int n, m;
int as[N][N];

edge e[M];

std::queue<int> q;

inline void addedge(int from, int to) {
    e[++tot] = (edge){to, head[from]};
    head[from] = tot;
    e[++tot] = (edge){from, head[to]};
    head[to] = tot;
}

void Getdis(int S, int *dis) {
    for (int i = 1; i <= n; ++i) dis[i] = 0;
    q.push(S);
    dis[S] = 1;
    while (!q.empty()) {
        int t = q.front();
        q.pop();
        for (int i = head[t]; i; i = e[i].next) {
            if (!dis[e[i].to]) dis[e[i].to] = dis[t] + 1, q.push(e[i].to);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m;
    for (int i = 1, x, y; i <= m; ++i) std::cin >> x >> y, addedge(x, y);
    for (int i = 1; i <= n; ++i) Getdis(i, dis[i]);
    for (int x = 1; x <= n; ++x) {
        for (int y = x; y <= n; ++y) {
            int cnt = 0;
            for (int i = 1; i <= n; ++i) {
                cnt += dis[x][i] + dis[y][i] - 1 == dis[x][y];
            }
            int64 ans = 1;
            if (cnt > dis[x][y]) ans = 0;
            for (int i = 1; i <= n; ++i)
                if (dis[x][i] + dis[y][i] - 1 != dis[x][y]) {
                    int flag = 0;
                    for (int j = head[i]; j; j = e[j].next) {
                        flag += dis[x][e[j].to] == dis[x][i] - 1 &&
                                dis[y][e[j].to] == dis[y][i] - 1;
                    }
                    ans = ans * flag % P;
                    if (!ans) break;
                }
            as[x][y] = as[y][x] = ans;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) std::cout << as[i][j] << " \n"[j == n];
    }
    return 0;
}