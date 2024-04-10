#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;

vector<int> result;
vector<int> first;

int dfs(int v, int p=-1) {
    int cnt = 0;
    for (int u : adj[v]) {
        if (u == p) continue;
        cnt += dfs(u, v);
    }
    if (cnt % 2 == 0) {
        result.push_back(v);
        return 1;
    } else {
        first.push_back(v);
        return 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    adj.resize(n);
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        if (p) {
            adj[p-1].push_back(i);
            adj[i].push_back(p-1);
        }
    }
    
    if (!dfs(0)) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
        for (auto x : first) {
            cout << x + 1 << '\n';
        }
        reverse(result.begin(), result.end());
        for (auto x : result) {
            cout << x + 1 << '\n';
        }
    }
}