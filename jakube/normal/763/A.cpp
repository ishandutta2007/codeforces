#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> color;

bool same_color(int v, int parent) {
    bool b = false;

    for (int next : adj[v]) {
        if (next != parent) {
            if (!same_color(next, v))
                return false;
            b |= color[next] != color[v];
        }
    }

    return !b;
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

    color.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> color[i];
    }

    if (all_of(color.begin(), color.end(), [](int c){ return c == color.front(); })) {
        cout << "YES" << endl;
        cout << 1 << endl;
        return 0;
    }

    vector<pair<int, int>> vec(n);
    for (int v = 0; v < n; v++) {
        int cnt = 0;
        for (int next : adj[v]) {
            cnt += color[v] != color[next];
        }
        vec[v] = { cnt, v };
    }

    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());

    int v = vec.front().second;
    if (all_of(adj[v].begin(), adj[v].end(), [v](int next){ return same_color(next, v); })) {
        cout << "YES" << endl;
        cout << v + 1 << endl;
        return 0;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}