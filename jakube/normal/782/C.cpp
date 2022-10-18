#include <bits/stdc++.h>
using namespace std;

vector<int> coloring;
vector<vector<int>> adj;

void dfs(int u, int p, int last_color1, int last_color2) {
    coloring[u] = last_color1;

    int color = 0;
    for (auto next : adj[u]) {
        if (next == p) continue;
        color++;
        while (color == last_color1 || color == last_color2)
            color++;

        dfs(next, u, color, last_color1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n;
    cin >> n;
    adj.resize(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    coloring.resize(n);

    dfs(0, -1, 1, 0);
    cout << *max_element(coloring.begin(), coloring.end()) << endl;
    for (int c : coloring)
        cout << c << ' ';
    cout << endl;
}