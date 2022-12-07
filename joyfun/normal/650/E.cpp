#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 500005;

int n;

struct Tree {
    vector<int> g[N];
    int fa[N];

    void build() {
        int u, v;
        for (int i = 1; i < n; i++) {
            scanf("%d%d", &u, &v);
            g[u].push_back(v);
            g[v].push_back(u);
        }
    }

    void dfs(int u, int p) {
        fa[u] = p;
        for (int i = 0; i < g[u].size(); i++) {
            int v = g[u][i];
            if (v == p) continue;
            dfs(v, u);
        }
    }
} A, B;

int rt[N];

struct Ans {
    int a, b, c, d;
    Ans() {}
    Ans(int a, int b, int c, int d) : a(a), b(b), c(c), d(d) {}
    void out() {
        printf("%d %d %d %d\n", a, b, c, d);
    }
};

vector<Ans> ans;

void dfs(int u, int p, int x) {
    if (B.fa[u] != p && B.fa[p] != u)
        x = u;
    rt[u] = x;
    for (int i = 0; i < A.g[u].size(); i++) {
        int v = A.g[u][i];
        if (v == p) continue;
        dfs(v, u, x);
    }
}

void dfs2(int u, int p) {
    if (A.fa[u] != p && A.fa[p] != u)
        ans.push_back(Ans(rt[u], A.fa[rt[u]], u, p));
    for (int i = 0; i < B.g[u].size(); i++) {
        int v = B.g[u][i];
        if (v == p) continue;
        dfs2(v, u);
    }
}

int main() {
    scanf("%d", &n);
    A.build(); A.dfs(1, 1);
    B.build(); B.dfs(1, 1);
    dfs(1, 1, 1);
    dfs2(1, 1);
    int sz = ans.size();
    printf("%d\n", sz);
    for (int i = 0; i < sz; i++)
        ans[i].out();
    return 0;
}