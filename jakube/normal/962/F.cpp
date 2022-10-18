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

std::vector<std::vector<std::pair<int, int>>> bc_components;
std::stack<std::pair<int, int>> st;

void dfs(int v, int p=-1) {
    disc[v] = low[v] = ++timer;
    int children = 0;
    for (Edge e : adj[v]) {
        int u = e.to;
        if (u == p)
            continue;

        if (!disc[u]) {
            children++;
            st.push({v, u});
            dfs(u, v);
            low[v] = std::min(low[v], low[u]);
            if ((p != -1 && low[u] >= disc[v]) ||
                (p == -1 && children > 1))
            {
                std::vector<std::pair<int, int>> component;
                do {
                    component.push_back(st.top());
                    st.pop();
                } while (component.back() != std::make_pair(v, u));
                bc_components.push_back(std::move(component));
            }
        } else if (disc[u] < disc[v]) {
            st.push({v, u});
            low[v] = std::min(low[v], disc[u]);
        }
    }
}

void construct() {
    timer = 0;
    disc.assign(n, 0);
    low.assign(n, 0);

    for (int v = 0; v < n; v++) {
        if (!disc[v]) {
            dfs(v);
            if (!st.empty()) {
                std::vector<std::pair<int, int>> component;
                while (!st.empty()) {
                    component.push_back(st.top());
                    st.pop();
                }
                bc_components.push_back(std::move(component));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    adj.resize(n);
    map<pair<int, int>, int> ma;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].emplace_back(v, i);
        adj[v].emplace_back(u, i);
        ma[make_pair(min(u, v), max(u, v))] = i + 1;
    }
    construct();

    vector<int> result;
    for (auto& block : bc_components) {
        set<int> s;
        for (auto [v, u] : block) {
            s.insert(v);
            s.insert(u);
        }
        if (s.size() == block.size()) {
            for (auto [v, u] : block)
                result.push_back(ma[make_pair(min(u, v), max(u, v))]);
        }
    }

    sort(result.begin(), result.end());
    cout << result.size() << endl;
    for (auto x : result) {
        cout << x << ' ';
    }
    cout << endl;
}