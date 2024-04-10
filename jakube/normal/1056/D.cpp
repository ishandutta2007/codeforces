#include <bits/stdc++.h>
using namespace std;

vector<int> leaves;

vector<vector<int>> adj;
int dfs(int v) {
    if ((int)adj[v].size() == 0) {
        leaves.push_back(1);
        return 1;
    }

    int cnt = 0;
    for (int u : adj[v]) {
        cnt += dfs(u);
    }
    leaves.push_back(cnt);
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    adj.resize(n);
    for (int i = 1; i < n; i++) {
        int p;
        cin >> p;
        p--;
        adj[p].push_back(i);
    }

    dfs(0);
    sort(leaves.begin(), leaves.end());
    for (auto x : leaves) {
        cout << x << ' ';
    }
    cout << '\n';
}