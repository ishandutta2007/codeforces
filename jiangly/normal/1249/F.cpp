#include <bits/stdc++.h>
using namespace std;
template<typename T>
void cmax(T &a, const T &b) {
    if (b > a)
        a = b;
}
constexpr int MAX_N = 2E2;
int n, k;
int a[MAX_N];
vector<int> e[MAX_N];
int dp[MAX_N][MAX_N];
int f[MAX_N];
void dfs(int u, int p) {
    dp[u][0] = a[u];
    for (int v : e[u]) {
        if (v == p)
            continue;
        dfs(v, u);
        memset(f, 0, sizeof(f));
        for (int i = 0; i < n; ++i)
            for (int j = max(1, k + 1 - i); j < n; ++j)
                cmax(f[min(i, j)], dp[u][i] + dp[v][j - 1]);
        for (int i = 0; i < n; ++i)
            cmax(dp[u][i], dp[v][i - 1]);
        for (int i = 0; i < n; ++i)
            cmax(dp[u][i], f[i]);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 1; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(0, -1);
    cout << *max_element(dp[0], dp[0] + MAX_N) << "\n";
    return 0;
}