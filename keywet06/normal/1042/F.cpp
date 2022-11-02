#include <bits/stdc++.h>

using namespace std;

const int N = 1000005;

int read() {
    int w = 0, f = 1;
    char c = ' ';
    while (c < '0' || c > '9') c = getchar(), f = c == '-' ? -1 : f;
    while (c >= '0' && c <= '9') w = w * 10 + c - 48, c = getchar();
    return w * f;
}

int n, k;
int siz[N], dis[N];

vector<int> e[N];

void dfs(int u, int ft) {
    if (e[u].size() == 1 && e[u][0] == ft) {
        siz[u] = 1;
        return;
    }
    vector<int> now;
    for (auto v : e[u]) {
        if (v == ft) continue;
        dfs(v, u);
        siz[u] += siz[v], now.push_back(dis[v] + 1);
    }
    sort(now.begin(), now.end());
    dis[u] = now[0];
    for (int i = 0; i < now.size() - 1; i++)
        if (now[i] + now[i + 1] <= k) siz[u]--, dis[u] = now[i + 1];
}

int main() {
    n = read(), k = read();
    int x, y, rt;
    for (int i = 1; i < n; i++) {
        x = read(), y = read();
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for (int i = 1; i <= n; i++)
        if (e[i].size() > 1) {
            rt = i;
            break;
        }
    dfs(rt, 0);
    printf("%d", siz[rt]);
    return 0;
}