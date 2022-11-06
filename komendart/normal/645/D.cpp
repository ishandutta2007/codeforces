#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

int n, m;
vector< pair<int, int> > edges;

vector<int> graph[maxn];
int dp[maxn];
vector<int> order;
char used[maxn];

void dfs(int v) {
    if (used[v]) return;
    used[v] = true;
    for (auto u: graph[v]) {
        dfs(u);
    }
    order.push_back(v);
}

bool f(int k) {
    for (int i = 0; i < n; i++) {
        graph[i].clear();
        dp[i] = 0;
        used[i] = false;
    }
    order.clear();

    for (int i = 0; i < k; i++) {
        graph[edges[i].first].push_back(edges[i].second);
    }

    for (int i = 0; i < n; i++) {
        dfs(i);
    }
    reverse(order.begin(), order.end());

    for (auto v: order) {
        for (auto u: graph[v]) {
            dp[u] = max(dp[u], dp[v] + 1);
        }
    }
    for (int i = 0; i < n; i++) {
        if (dp[order[i]] != i) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edges.push_back({a, b});
    }

    int left = 0, right = m + 1;
    while (right - left > 1) {
        int mid = (left + right) / 2;
        if (f(mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }

    if (right == m + 1) cout << -1 << endl;
    else cout << right << endl;
}