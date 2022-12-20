#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 1;

bool f[N];
vector <int> e[N];
int sz[N];
int x, y;

bool dfs(int u, int pr) {
    sz[u] = 1;
    f[u] = (u == y);
    for (int i = 0; i < e[u].size(); ++i)
    if (e[u][i] != pr) {
        if (dfs(e[u][i], u))
            f[u] = true;
        sz[u] += sz[e[u][i]];
    }
    return f[u];
}

int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    long long n, ans, a, b, i, j;
    cin >> n >> x >> y;
    for (i = 1; i < n; ++i) {
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs(x, 0);
    ans = 0;
    for (i = 1; i <= n; ++i)
    if (f[i] && i != x)
        ans = max(ans, (long long) sz[i]);
    cout << n * (n - 1) - (n - ans) * sz[y];
}