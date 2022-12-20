#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 1;

int sz[N], ans = 0;
vector <int> e[N];

void dfs(int u, int pr) {
    sz[u] = 1;
    for (int i = 0; i < e[u].size(); ++i)
    if (e[u][i] != pr) {
        dfs(e[u][i], u);
        if (sz[e[u][i]] % 2 == 0)
            ++ans;
        sz[u] += sz[e[u][i]];
    }
}

int main() {
    int i, j, k, n, a, b;
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    cin >> n;
    if (n % 2 == 1) {
        cout << -1;
        return 0;
    }
    for (i = 1; i < n; ++i) {
        cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs(1, 0);
    cout << ans;
}