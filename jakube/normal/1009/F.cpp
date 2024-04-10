#include <bits/stdc++.h>
using namespace std;

vector<int> ans;
vector<vector<int>> adj;

vector<int> dfs(int v, int p) {
    vector<int> cur;
    int& x = ans[v];
    x = 0;
    for (int u : adj[v]) {
        if (u == p) continue;
        auto child = dfs(u, v);
        if (cur.size() < child.size()) {
            swap(cur, child);
            x = ans[u];
        }
        for (int i = 0; i < (int)child.size(); i++) {
            int a = cur.size()-1-i;
            int b = child.size()-1-i;
            cur[a] += child[b];
            if (cur[a] > cur[cur.size()-1-x] || (cur[a] == cur[cur.size()-1-x] && i < x))
                x = i;
        }
    }

    if (cur.size() == 0)
        x = -1;
    
    cur.push_back(1);
    x++;
    if (cur[cur.size() - 1 - x] == 1)
        x = 0;
    return cur;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    adj.resize(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ans.resize(n);
    dfs(0, -1);

    for (auto x : ans)
        cout << x << '\n';
}