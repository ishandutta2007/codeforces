#include <bits/stdc++.h>

const int N = 1050005;

int n, K;
int par[N][20], Dep[N], P[N], D[N], C[N];

std::vector<int> E[N];

void Dfs(int a) {
    for (int i = 0; i < 19; ++i) par[a][i + 1] = par[par[a][i]][i];
    for (auto &x : E[a]) par[x][0] = a, Dep[x] = Dep[a] + 1, Dfs(x);
}

int Up(int a, int d) {
    int i = 0;
    while (d) {
        if (d & 1) a = par[a][i];
        d >>= 1, ++i;
    }
    return a;
}

void Calc(int a) {
    if (!P[a]) P[a] = a;
    for (auto &x : E[a]) {
        Calc(x);
        if (Dep[P[a]] > Dep[P[x]]) P[a] = P[x];
    }
}

void Went(int a) {
    P[a] = P[P[a]];
    for (auto &x : E[a]) Went(x);
}

int res;

void Do(int a, int s) {
    s += C[a], res = std::max(res, s);
    for (auto &x : E[a]) Do(x, s);
}

int main() {
    int i, a;
    scanf("%d%d", &n, &K);
    for (i = 2; i <= n; ++i) {
        scanf("%d", &a), E[a].push_back(i);
    }
    Dfs(1);
    for (i = 1; i <= n; ++i) {
        if (E[i].empty()) {
            if (Dep[i] <= K) {
                D[i] = P[i] = 1;
            } else {
                D[i] = P[i] = Up(i, K);
            }
        }
    }
    Calc(1);
    Went(1);
    for (i = 1; i <= n; ++i) {
        if (E[i].empty()) ++C[P[i]];
    }
    Do(1, 0);
    printf("%d\n", res);
    return 0;
}