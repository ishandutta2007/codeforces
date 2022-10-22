#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

const int mxn = 1e6 + 5;

int n, d;
int a[mxn];

void Main() {
    scanf("%d %d", &n, &d);
    rep(i, n) scanf("%d", &a[i]);
    static int dist[mxn];
    rep(i, n) dist[i] = -1;
    std::vector <int> que;
    rep(i, n) if (a[i] == 0) {
        dist[i] = 0;
        que.push_back(i);
    }
    rep(i, que.size()) {
        int u = que[i];
        int v = (u + d) % n;
        if (dist[v] == -1) {
            dist[v] = dist[u] + 1;
            que.push_back(v);
        }
    }
    int ans = 0;
    rep(i, n) {
        if (dist[i] == -1) {
            puts("-1");
            return ;
        }
        ans = std::max(ans, dist[i]);
    }
    printf("%d\n", ans);
}

int main() {
    int T; scanf("%d", &T);
    while (T --) Main();
    return 0;
}