#include <bits/stdc++.h>

using namespace std;

int n;
int V[1000005];
vector<int> G[1 << 20];
vector<int> ans, cyc;
bool used[500005];

void dfs(int x) {
    while (!G[x].empty()) {
        int i = G[x].back();
        G[x].pop_back();
        if (used[i + 1 >> 1]) continue;
        used[i + 1 >> 1] = 1;
        cyc.push_back((i - 1 ^ 1) + 1);
        cyc.push_back(i);
        dfs(V[i]);
        return;
    }
}

void find_path(int x) {
    cyc.clear();
    dfs(x);
    vector<int> c = cyc;
    for (int i = 0; i < c.size(); i += 2) {
        find_path(V[c[i]]);
        ans.push_back(c[i]);
        ans.push_back(c[i + 1]);
    }
}

bool check(int b) {
    for (int i = 1; i <= 2 * n; i++) V[i] &= (1 << b) - 1;
    for (int i = 0; i < (1 << b); i++) G[i].clear();
    for (int i = 1; i <= n; i++) {
        int a = 2 * i - 1, b = 2 * i;
        used[i] = 0;
        G[V[a]].push_back(b);
        G[V[b]].push_back(a);
    }
    for (int i = 0; i < (1 << b); i++) if (G[i].size() & 1) return 0;
    ans.clear();
    for (int i = 0; ; i++) {
        if (G[i].empty()) continue;
        find_path(i);
        break;
    }
    if (ans.size() < 2 * n) return 0;
    printf("%d\n", b);
    for (int i : ans) printf("%d ", i);
    return 1;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= 2 * n; i++) {
        scanf("%d", V + i);
    }
    for (int i = 20; i >= 0; i--) if (check(i)) return 0;
    return 1;
}