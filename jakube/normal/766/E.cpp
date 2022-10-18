#include <bits/stdc++.h>
using namespace std;

vector<int> a;
vector<vector<int>> adj;
long long total_one;

pair<long long, long long> dfs(int v, int par, int bit) {
    long long all_one = 0;
    long long all_zero = 0;
    for (int next : adj[v]) {
        if (next == par) continue;
        auto p = dfs(next, v, bit);
        if (a[v] & bit) {
            total_one += p.second;
            total_one += all_one * p.first;
            total_one += all_zero * p.second;
            all_one += p.first;
            all_zero += p.second;
        } else {
            total_one += p.first;
            total_one += all_one * p.second;
            total_one += all_zero * p.first;
            all_one += p.first;
            all_zero += p.second;
        }
    }

    if (a[v] & bit) {
        total_one++;
        return {all_zero + 1, all_one};
    } else {
        return {all_one, all_zero + 1};
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    adj.resize(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    long long result = 0;
    for (int i = 0; i < 20; i++) {
        total_one = 0;
        dfs(0, -1, 1<<i);
        result += total_one * (1LL << i);
        // cout << (1 << i) << ' ' << total_one << endl;
    }
    
    cout << result << endl;
    return 0;
}