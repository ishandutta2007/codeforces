#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> adj;
vector<int> d;
map<pair<int, int>, int> ma;
vector<int> out;
vector<bool> visited;


int dfs(int v, int p) {
    if (visited[v])
        return 0;
    visited[v] = 1;

    int cnt = 0;
    if (d[v] == 1) 
        cnt++;

    for (int u : adj[v]) {
        if (u != p)
            cnt += dfs(u, v);
    }

    if (cnt % 2 == 1 && p != -1)
        out.push_back(ma[make_pair(min(v,p), max(v,p))]);

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    adj.resize(n);
    d.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        ma[make_pair(min(u, v), max(u,v))] = i+1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if (all_of(d.begin(), d.end(), [](int x){ return x != 1; })) {
        cout << 0 << endl;
        return 0;
    }

    int cnt_1s = 0;
    int start = -1;
    int start_neg = -1;
    for (int i = 0; i < n; i++) {
        if (d[i] == 1) {
            cnt_1s++;
            start = i;
        } 
        if (d[i] == -1) {
            start_neg = i;
        }
    }

    if (start_neg == -1 && cnt_1s % 2 == 1) {
        cout << -1 << endl;
        return 0;
    }

    if (start_neg >= 0)
        start = start_neg;

    visited.assign(n, false);
    dfs(start, -1);

    // vector<int> out;
    // for (auto p : ma) {
    //     if (p.second >= 0)
    //         out.push_back(p.second);
    // }
    sort(out.begin(), out.end());
    cout << out.size() << endl;
    for (auto i : out)
        cout << i << " ";
    cout << endl;
}