#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cstdio>
constexpr int N = 100'000;
int n, q, dfn, top;
std::vector<int> e[N], queries[N];
int k[N], stk[N], in[N], height[N], dep[N], ans[N], f[N], parent[N];
char buf[1 << 18], *p1, *p2;
char get() {
    if (p1 == p2) {
        p1 = buf;
        p2 = buf + fread(buf, 1, sizeof(buf), stdin);
    }
    if (p1 == p2)
        return EOF;
    return *p1++;
}
int readInt() {
    int x = 0;
    char c = get();
    while (!std::isdigit(c))
        c = get();
    while (std::isdigit(c)) {
        x = 10 * x + c - '0';
        c = get();
    }
    return x;
}
void dfs1(int u) {
    stk[top++] = u;
    for (int i : queries[u]) {
        if (k[i] <= dep[u]) {
            ans[i] = stk[dep[u] - k[i]];
        } else {
            ans[i] = -1;
        }
    }
    height[u] = 1;
    for (int &v : e[u]) {
        dep[v] = dep[u] + 1;
        dfs1(v);
        height[u] = std::max(height[u], height[v] + 1);
        if (height[v] > height[e[u][0]])
            std::swap(v, e[u][0]);
    }
    --top;
}
void dfs2(int u) {
    in[u] = dfn++;
    f[in[u]] = 1;
    for (int v : e[u]) {
        dfs2(v);
        if (v != e[u][0])
            for (int i = 0; i < height[v]; ++i)
                f[in[u] + i + 1] += f[in[v] + i];
    }
    for (int i : queries[u])
        ans[i] = f[in[u] + k[i]] - 1;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    n = readInt();
    for (int i = 0; i < n; ++i) {
        parent[i] = readInt() - 1;
        if (parent[i] != -1)
            e[parent[i]].push_back(i);
    }
    q = readInt();
    for (int i = 0; i < q; ++i) {
        int u = readInt() - 1;
        k[i] = readInt();
        queries[u].push_back(i);
    }
    for (int i = 0; i < n; ++i)
        if (parent[i] == -1)
            dfs1(i);
    for (int i = 0; i < n; ++i)
        queries[i].clear();
    for (int i = 0; i < q; ++i) {
        if (ans[i] == -1) {
            ans[i] = 0;
        } else {
            queries[ans[i]].push_back(i);
        }
    }
    for (int i = 0; i < n; ++i)
        if (parent[i] == -1)
            dfs2(i);
    for (int i = 0; i < q; ++i)
        std::cout << ans[i] << " \n"[i == q - 1];
    return 0;
}