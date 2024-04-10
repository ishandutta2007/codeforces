#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<vector<int>> adj;
vector<int> state;
vector<int> order;

bool topoSort(int u) {
    if (state[u] == 2) return true;
    if (state[u] == 1) return false;
    state[u] = 1;

    for (int next : adj[u]) {
        if (!topoSort(next))
            return false;
    }

    order.push_back(u);
    state[u] = 2;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.precision(10);
    cout << fixed;

    cin >> n >> k;
    vector<int> mc(k);
    for (int i = 0; i < k; i++) {
        cin >> mc[i];
        mc[i]--;
    }
        
    adj.resize(n);
    for (int i = 0; i < n; i++) {
        int c;
        cin >> c;
        for (int j = 0; j < c; j++) {
            int p;
            cin >> p;
            adj[i].push_back(p-1);
        }
    }

    state.assign(n, 0);
    for (int m : mc) {
        if (!topoSort(m)) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << order.size() << endl;
    for (int o : order)
        cout << o+1 << " ";
    cout << endl;
}