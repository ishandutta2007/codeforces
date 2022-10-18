#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
vector<vector<int>> adj;
long long best = std::numeric_limits<long long>::min();

long long dfs(int v, int p=-1) {
    long long cur = a[v];
    for (int u : adj[v]) {
        if (u == p)
            continue;
        cur += max(0LL, dfs(u, v));
    }
    best = max(best, cur);
    return cur;
}

int cnt = 0;
long long dfs2(int v, int p=-1) {
    long long cur = a[v];
    for (int u : adj[v]) {
        if (u == p)
            continue;
        cur += max(0LL, dfs2(u, v));
    }
    if (cur == best) {
        cnt++;
        return 0;
    }
    return cur;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    a.resize(n);
    for (auto& x : a)
        cin >> x;

    adj.resize(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0);
    dfs2(0);
    cout << best * cnt << " " << cnt << '\n';
    

}