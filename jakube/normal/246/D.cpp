#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int idx = 0; idx < n; idx++)
        cin >> v[idx];
    
    vector<pair<int, int>> neig(m);
    for (int idx = 0; idx < m; idx++)
        cin >> neig[idx].first >> neig[idx].second;
    
    vector<vector<int>> colors(1e5+1);
    for (int i = 0; i < n; i++) {
        colors[v[i]].push_back(i);
    }

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        tie(a, b) = neig[i];
        adj[a-1].push_back(b-1);
        adj[b-1].push_back(a-1);
    }

    int ma = -1;
    int col = 0;

    for (int i = 0; i < (int)(1e5+1); i++) {
        set<int> s;
        if (colors[i].size() == 0)
            continue;
        for (int node : colors[i]) {
            for (int next : adj[node]) {
                if (v[next] != i)
                    s.insert(v[next]);
            }
        }

        if ((int)(s.size()) > ma) {
            ma = s.size();
            col = i;
        }
    }

    cout << col << endl;

    return 0;
}