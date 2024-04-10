#include <bits/stdc++.h>
using namespace std;

vector<int> color;
vector<vector<int>> adj;
vector<array<int, 2>> previous;

bool dfs(int v) {
    if (color[v] == 1)
        return true;
    if (color[v] == 2)
        return false;
    color[v] = 1;

    for (int u : adj[v]) {
        if (dfs(u))
            return true;
    }

    color[v] = 2;
    return false;
}

void dfs2(int v, int p, int par, bool start=false) {
    if (previous[v][par] != -1)
        return;
    if (!start)
        previous[v][par] = p;

    for (int u : adj[v]) {
        dfs2(u, v, par ^ 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        for (int j = 0; j < c; j++) {
            int x;
            cin >> x;
            adj[i].push_back(x-1);
        }
    }
    int s;
    cin >> s;
    s--;

    color.assign(n, 0);
    bool draw_possible = dfs(s);

    previous.assign(n, {{-1, -1}});
    dfs2(s, s, 0, true);
    
    for (int v = 0; v < n; v++) {
        if (adj[v].empty() && previous[v][1] != -1) {
            cout << "Win" << endl;
            int par = 1;
            vector<int> path;
            do {
                path.push_back(v);
                v = previous[v][par];
                par ^= 1;
            } while (v != s || par != 0);
            path.push_back(s);
            reverse(path.begin(), path.end());
            for (auto x : path) {
                cout << x + 1 << ' ';
            }
            cout << endl;
            return 0;
        }
    }

    if (draw_possible) {
        cout << "Draw" << endl;
    } else {
        cout << "Lose" << endl;
    }
}