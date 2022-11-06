#include <bits/stdc++.h>

using namespace std;

#define int long long

const int maxn = 1e5 + 10;
const int inf = 1e9 + 5;

int n, m;
vector<int> graph[maxn];
int cost[maxn];
char used[maxn];

int dfs(int v) {
    if (used[v]) return inf;
    used[v] = true;
    int ans = cost[v];
    for (auto to: graph[v]) {
        ans = min(ans, dfs(to));
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> cost[i];
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        if (!used[i]) {
            ans += dfs(i);
        }
    }
    cout << ans << '\n';
    
}