#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;

char good[maxn];
int size[maxn];
vector<int> graph[maxn];

void dfs(int v, int p) {
    if (good[v]) size[v] = 1;
    for (auto u: graph[v]) {
        if (u != p) {
            dfs(u, v);
            size[v] += size[u];
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int n, k;
    cin >> n >> k;
    k *= 2;
    for (int i = 0; i < k; i++) {
        int t; cin >> t; t--;
        good[t] = true;
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(0, -1);
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        ans += min(size[i], k - size[i]);
    }

    cout << ans << endl;
}