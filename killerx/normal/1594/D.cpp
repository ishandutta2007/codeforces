#include <bits/stdc++.h>

#define eprintf(args...) fprintf(stderr, args)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int fa[400005];

inline int find(int x) {
    return x == fa[x] ? x : fa[x] = find(fa[x]);
}

void merge(int x, int y) {
    fa[find(x)] = find(y);
}

void Main() {
    int n, m;
    scanf("%d %d", &n, &m);
    rep(i, n + n) fa[i] = i;
    rep(i, m) {
        int u, v;
        char s[15];
        scanf("%d %d %s", &u, &v, s);
        -- u, -- v;
        if (s[0] == 'i') merge(u, v + n), merge(u + n, v);
        else merge(u, v), merge(u + n, v + n);
    }
    rep(i, n) if (find(i) == find(i + n)) {
        puts("-1");
        return ;
    }
    static int cnt[400005][2];
    rep(i, n + n) cnt[i][0] = cnt[i][1] = 0;
    rep(i, n + n) cnt[find(i)][i < n] += 1;
    int ans = 0;
    rep(i, n + n) if (find(i) == i) ans += std::max(cnt[i][0], cnt[i][1]);
    printf("%d\n", ans >> 1);
}

int main() {
    int T; scanf("%d", &T);
    while (T --) Main();
    return 0;
}