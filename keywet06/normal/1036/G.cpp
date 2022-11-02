#include <bits/stdc++.h>

const int N = 1000005;
const int B = 20;

bool found;

int n, m, b;
int in[N], dp[N];
int bits[1 << B];

std::vector<int> neigh[N], mask;

void Solve(int v) {
    if (dp[v]) return;
    for (int i = 0; i < neigh[v].size(); ++i) {
        int u = neigh[v][i];
        Solve(u), dp[v] |= dp[u];
    }
}

void Gen(int lvl, int cnt, int global) {
    if (lvl >= mask.size()) {
        if (cnt > 0 && cnt < mask.size() && bits[global] == cnt) found = true;
    } else {
        Gen(lvl + 1, cnt, global);
        Gen(lvl + 1, cnt + 1, global | mask[lvl]);
    }
}

int main() {
    for (int i = 0; i < 1 << B; ++i) bits[i] = __builtin_popcount(i);
    scanf("%d %d", &n, &m);
    for (int i = 0, a, b; i < m; ++i) {
        scanf("%d %d", &a, &b);
        neigh[a].push_back(b), ++in[b];
    }
    for (int i = 1; i <= n; ++i) {
        if (neigh[i].empty()) dp[i] = 1 << b++;
    }
    for (int i = 1; i <= n; ++i) {
        Solve(i);
        if (in[i] == 0) mask.push_back(dp[i]);
    }
    Gen(0, 0, 0);
    printf("%s\n", found ? "NO" : "YES");
    return 0;
}