#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int to, idx;
};

vector<vector<Edge>> adj;
vector<int> colors;
int n, r;
int M;
int cnt_bad;

void dfs(int v, int p, int c) {
    if (adj[v].size() > M) {
        if (c == 0)
            c = 1;
        // all c
        cnt_bad++;
        for (auto [u, idx] : adj[v]) {
            if (u == p)
                continue;
            colors[idx] = c;
            dfs(u, v, c);
        }
    } else {
        // different for all
        int last_c = 0;
        for (auto [u, idx] : adj[v]) {
            if (u == p)
                continue;
            last_c++;
            if (last_c == c)
                last_c++;
            colors[idx] = last_c;
            dfs(u, v, last_c);
        }
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> r;
    adj.resize(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    int L = 0; //impossible
    int R = n - 1; // possible
    colors.resize(n-1);
    while (L + 1 < R) {
        M = (L + R) / 2;
        cnt_bad = 0;
        dfs(0, -1, 0);
        if (cnt_bad <= r) {
            R = M;
        } else {
            L = M;
        }
    }
    cout << R << '\n';
    M = R;
    dfs(0, -1, 0);
    for (auto x : colors) {
        cout << x << ' ';
    }
    cout << '\n';
}