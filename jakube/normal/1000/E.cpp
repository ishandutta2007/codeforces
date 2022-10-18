#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    int idx;
    Edge(int to, int idx) : to(to), idx(idx) {}
};

int n, m;
std::vector<std::vector<Edge>> adj;

int timer;
std::vector<int> disc, low;
std::vector<bool> bridge, cut;

void dfs(int v, int p=-1) {
    disc[v] = low[v] = ++timer;
    int children = 0;
    for (Edge e : adj[v]) {
        int u = e.to;
        if (u == p)
            continue;

        if (disc[u]) {
            low[v] = std::min(low[v], disc[u]);
        } else {
            children++;
            dfs(u, v);
            low[v] = std::min(low[v], low[u]);
            if (low[u] > disc[v])
                bridge[e.idx] = true;
            if ((p != -1 && low[u] >= disc[v]) ||
                (p == -1 && children > 1))
                cut[v] = true;
        }
    }
}

void find() {
    timer = 0;
    disc.assign(n, 0);
    low.assign(n, 0);
    bridge.assign(m, false);
    cut.assign(n, false);

    for (int v = 0; v < n; v++) {
        if (!disc[v])
            dfs(v);
    }
}

stack<int> st;
vector<bool> visited;
vector<int> which;
void dfs2(int v, int p) {
    st.push(v);
    visited[v] = true;
    for (auto [u, idx] : adj[v]) {
        if (u == p || visited[u])
            continue;
        int last = st.top();
        dfs2(u, v);
        if (bridge[idx]) {
            timer++;
            while (st.top() != last) {
                which[st.top()] = timer;
                st.pop();
            }
        }
    }
}

vector<set<int>> adj2;
int longest = 0;

int dfs3(int v, int p) {
    int l1 = 0;
    int l2 = 0;
    for (int u : adj2[v]) {
        if (u == p) continue;
        int x = dfs3(u, v);
        if (x > l2)
            l2 = x;
        if (l2 > l1)
            swap(l2, l1);
    }
    longest = max(l1 + l2, longest);
    return l1 + 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    adj.resize(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
    }

    find();
    timer = 0;
    visited.assign(n, false);
    which.resize(n, 0);
    dfs2(0, -1);

    adj2.resize(timer + 1);
    for (int p = 0; p < n; p++) {
        for (auto [q, idx] : adj[p]) {
            if (which[p] != which[q]) {
                adj2[which[p]].insert(which[q]);
                adj2[which[q]].insert(which[p]);
            }
        }
    }
    dfs3(0, -1);
    cout << longest << '\n';
}