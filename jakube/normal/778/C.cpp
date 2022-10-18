#include <bits/stdc++.h>
using namespace std;

struct Node {
    int size = 0;
    int depth = 0;
    int adj[26] = {0};
    bool saved = false;
    int _size = 0;
    int _adj[26] = {0};
};

vector<vector<pair<int, char>>> adj;

vector<Node> nodes;
vector<int> answer;
vector<int> changes;

void dfs(int u, int p, int depth) {
    nodes[u].depth = depth;
    nodes[u].size = 1;

    for (auto next : adj[u]) {
        if (next.first == p) continue;
        
        nodes[u].adj[next.second - 'a'] = next.first;
        dfs(next.first, u, depth + 1);
        nodes[u].size += nodes[next.first].size;
    }
}

int merge(int u, int v) {
    if (!u) return v;
    if (!v) return u;
    // if (nodes[u].size < nodes[v].size) swap(u, v);

    if (!nodes[u].saved) {
        nodes[u].saved = true;
        nodes[u]._size = nodes[u].size;
        memcpy(nodes[u]._adj, nodes[u].adj, sizeof(nodes[u].adj));
        changes.push_back(u);
    }

    for (int i = 0; i < 26; i++) {
        if (nodes[u].adj[i] || nodes[v].adj[i]) {
            if (nodes[u].adj[i]) nodes[u].size -= nodes[nodes[u].adj[i]].size;
            nodes[u].adj[i] = merge(nodes[u].adj[i], nodes[v].adj[i]);
            if (nodes[u].adj[i]) nodes[u].size += nodes[nodes[u].adj[i]].size;
        }
    }
    return u;
}

void solve(int u) {
    int merged = 0;
    for (int i = 0; i < 26; i++) {
        merged = merge(merged, nodes[u].adj[i]);
    }

    int depth = nodes[u].depth;
    answer[depth] += nodes[u].size - 1;
    if (merged)
        answer[depth] -= nodes[merged].size - 1;

    for (int x : changes) {
        nodes[x].saved = false;
        nodes[x].size = nodes[x]._size;
        memcpy(nodes[x].adj, nodes[x]._adj, sizeof(nodes[x].adj));
    }
    changes.clear();
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    adj.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    nodes.resize(n + 1);
    dfs(1, 0, 1);

    answer.assign(n + 1, 0);
    for (int i = 1; i <= n; i++)
        solve(i);

    int ma = *max_element(answer.begin(), answer.end());
    int idx = find(answer.begin(), answer.end(), ma) - answer.begin();

    cout << n - ma << endl;
    cout << idx << endl;
}