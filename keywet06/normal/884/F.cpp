#include <bits/stdc++.h>

const int N = 100;
const int M = 2800;
const int INF = 1e9;

bool used[N];

int n, S, T, ans;
int dis[N], path[N];

int cnt = 1;
int head[N], to[M], nxt[M], v[M], w[M];

void Add(int x, int y, int z, int f) {
    ++cnt;
    to[cnt] = y;
    nxt[cnt] = head[x];
    head[x] = cnt;
    v[cnt] = f;
    w[cnt] = z;
}

void Ins(int x, int y, int z, int f) {
    Add(x, y, z, f);
    Add(y, x, -z, 0);
}

bool SPFA() {
    memset(used, false, sizeof(used));
    for (int i = S; i <= T; ++i) dis[i] = INF;
    std::queue<int> q;
    while (!q.empty()) q.pop();
    dis[S] = 0;
    used[S] = true;
    q.push(S);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = head[x]; i; i = nxt[i]) {
            int y = to[i];
            if (v[i] && dis[y] > dis[x] + w[i]) {
                path[y] = i;
                dis[y] = dis[x] + w[i];
                if (!used[y]) q.push(y), used[y] = true;
            }
        }
        used[x] = false;
    }
    return dis[T] < INF;
}

void Flow() {
    while (SPFA()) {
        int x = T, f = INF;
        while (x != S) {
            f = std::min(f, v[path[x]]);
            x = to[path[x] ^ 1];
        }
        ans += f * dis[T];
        x = T;
        while (x != S) {
            v[path[x] ^ 1] += f;
            v[path[x]] -= f;
            x = to[path[x] ^ 1];
        }
    }
}

char s[110];
int b[110], sum[110];

int main() {
    scanf("%d", &n);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; ++i) ++sum[s[i] - 'a' + 1];
    for (int i = 1; i <= n; ++i) scanf("%d", &b[i]);
    S = 0;
    T = 26 + n / 2 + 1;
    for (int i = 1; i <= 26; ++i) Ins(S, i, 0, sum[i]);
    for (int i = 1; i <= n / 2; ++i) Ins(26 + i, T, 0, 2);
    for (int i = 1; i <= 26; ++i) {
        for (int j = 1; j <= n / 2; ++j) {
            int now = 0;
            if (s[j] == 'a' + i - 1) now = std::max(now, b[j]);
            if (s[n + 1 - j] == 'a' + i - 1) now = std::max(now, b[n + 1 - j]);
            Ins(i, 26 + j, -now, 1);
        }
    }
    Flow();
    std::cout << -ans << std::endl;
    return 0;
}