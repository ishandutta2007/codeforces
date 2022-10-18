#include "bits/stdc++.h"
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj_inc(n), adj_out(n), adj_undirected(n);
    vector<int> incoming(n, 0), outgoing(n, 0);
    for (int i = 0; i < m; i++) {
        int t, u, v;
        cin >> t >> u >> v;
        u--, v--;
        if (t == 1) {
            adj_out[u].push_back(v);
            adj_inc[v].push_back(u);
            outgoing[u]++;
            incoming[v]++;
        } else {
            adj_undirected[u].push_back(v);
            adj_undirected[v].push_back(u);
        }
    }

    vector<int> state(n, 0);
    stack<int> st;
    for (int v = 0; v < n; v++) {
        if (incoming[v] == 0 || outgoing[v] == 0) {
            st.push(v);
            state[v] = 1;
        }
    }

    while (!st.empty()) {
        int v = st.top();
        st.pop();

        if (incoming[v] == 0) {
            for (auto u : adj_out[v]) {
                incoming[u]--;
                if (state[u] == 0 && incoming[u] == 0) {
                    st.push(u);
                    state[u] = 1;
                }
            }
            for (auto u : adj_undirected[v]) {
                if (state[u] > 1)
                    continue;
                adj_out[v].push_back(u);
            }
        } else {
            for (auto u : adj_inc[v]) {
                outgoing[u]--;
                if (state[u] == 0 && outgoing[u] == 0) {
                    st.push(u);
                    state[u] = 1;
                }
            }
            for (auto u : adj_undirected[v]) {
                if (state[u] > 1)
                    continue;
                adj_out[u].push_back(v);
            }
        }
        state[v] = 2;
    }

    if (*min_element(state.begin(), state.end()) < 2) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
        for (int v = 0; v < n; v++) {
            for (int u : adj_out[v]) {
                cout << v+1 << " " << u+1 << "\n";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        solve();
    }
}