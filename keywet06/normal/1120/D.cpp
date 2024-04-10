#include <bits/stdc++.h>

using int64 = long long;

const int N = 200005;

int n;
int f[N], g[N], t[N], c[N];

int64 ans = 0;

std::vector<int> vec[N];

std::set<int> s;
std::set<int>::iterator it;

void dfs(int x, int fa) {
    int siz = vec[x].size();
    if (siz == 1 && fa != 0) {
        f[x] = c[x], ans = ans + f[x], g[x] = x, t[x] = -1, s.insert(x);
        return;
    }
    bool tf = false;
    for (int u = 0; u < siz; ++u) {
        int y = vec[x][u];
        if (y == fa) continue;
        dfs(y, x);
        if (f[y] > f[x]) {
            tf = false, f[x] = f[y], g[x] = g[y];
        } else if (f[y] == f[x]) {
            tf = true;
        }
    }
    if (tf == true) g[x] = -1;
    if (f[x] > c[x]) {
        ans = ans - (f[x] - c[x]);
        int now = g[x];
        while (now != -1) s.erase(now), now = t[now];
        s.erase(g[x]), f[x] = c[x], g[x] = x, t[x] = -1, s.insert(g[x]);
    } else if (f[x] == c[x]) {
        s.insert(x), t[x] = g[x], g[x] = x;
    }
}

int main() {
    memset(f, -1, sizeof(f));
    scanf("%d", &n);
    for (int u = 1; u <= n; ++u) scanf("%d", &c[u]);
    for (int u = 1, x, y; u < n; ++u) scanf("%d%d", &x, &y), vec[x].push_back(y), vec[y].push_back(x);
    dfs(1, 0);
    printf("%lld %d\n", ans, s.size());
    for (it = s.begin(); it != s.end(); ++it) printf("%d ", (*it));
    puts("");
    return 0;
}