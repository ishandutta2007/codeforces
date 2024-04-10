#include <bits/stdc++.h>

constexpr int N = 1.5e5, M = 1 << 18;

int n, q;
int parent[N], dep[N];
char ch[N];

int down[N], h[N], deg[N];
int mx[N][26], edge[N][26], sum[N];
int e[N][2];

int bad;

void add(int u, int c, int v) {
    u = down[u];
    edge[u][c] += v;
    for (u = parent[u]; u != -1; u = parent[u]) {
        bad -= sum[u] > h[u];
        sum[u] -= mx[u][c];
        mx[u][c] = 0;
        for (int i = 0; i < deg[u]; ++i)
            mx[u][c] = std::max(mx[u][c], mx[e[u][i]][c] + edge[e[u][i]][c]);
        sum[u] += mx[u][c];
        bad += sum[u] > h[u];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::cin >> n >> q;
    parent[0] = -1;
    for (int i = 1; i < n; ++i) {
        std::cin >> parent[i] >> ch[i];
        --parent[i];
        e[parent[i]][deg[parent[i]]++] = i;
    }
    
    for (int i = n - 1; i > 0; --i)
        h[parent[i]] = h[i] + 1;
    for (int i = 1; i < n; ++i) {
        if (h[parent[i]] != h[i] + 1) {
            while (q--)
                std::cout << "Fou\n";
            return 0;
        }
        if (parent[i] != 0 && deg[parent[i]] == 1)
            parent[i] = parent[parent[i]];
    }
    for (int i = n - 1; i > 0; --i)
        down[i] = deg[i] == 1 ? down[e[i][0]] : i;
    for (int i = 0; i < n; ++i)
        deg[i] = 0;
    for (int i = 1; i < n; ++i)
        if (down[i] == i)
            e[parent[i]][deg[parent[i]]++] = i;
    
    for (int i = 1; i < n; ++i)
        if (ch[i] != '?')
            add(i, ch[i] - 'a', 1);
    
    while (q--) {
        int v;
        char c;
        std::cin >> v >> c;
        --v;
        if (ch[v] != '?')
            add(v, ch[v] - 'a', -1);
        if (c != '?')
            add(v, c - 'a', 1);
        ch[v] = c;
        if (bad == 0) {
            int ans = 0;
            for (int i = 0; i < 26; ++i)
                ans += (i + 1) * (h[0] - sum[0] + mx[0][i]);
            std::cout << "Shi " << ans << "\n";
        } else {
            std::cout << "Fou\n";
        }
    }
    
    return 0;
}