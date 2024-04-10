#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <algorithm>
#include <utility>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <stack>
using namespace std;
typedef long long ll;

vector<vector<tuple<int, ll>>> graph;
vector<vector<tuple<int, ll>>> graph_inv;
stack<int> order;
vector<bool> vis_first;
vector<bool> vis_second;
vector<int> component;
vector<ll> w_b;

void dfs_first(int u) {
    for (auto [v, l] : graph[u]) {
        if (!vis_first[v]) {
            vis_first[v] = true;
            dfs_first(v);
        }
    }

    order.push(u);
}

void dfs_second(int u) {
    component.push_back(u);
    for (auto [v, l] : graph_inv[u]) {
        if (!vis_second[v]) {
            w_b[v] = w_b[u] + l;
            vis_second[v] = true;
            dfs_second(v);
        }
    }
}

ll gcd(ll a, ll b) {
    if (a < b) {
        swap(a, b);
    }

    while (b != 0) {
        ll tmp = b;
        b = a % b;
        a = tmp;
    }

    return a;
}

ll gcd_slow(ll a, ll b) {
    if (a < b) return gcd_slow(b, a);
    if (b == 0) return a;
    return gcd_slow(b, a % b);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(14);
    int n, m;
    cin >> n >> m;

    graph = vector<vector<tuple<int, ll>>>(n, vector<tuple<int, ll>>());
    graph_inv = vector<vector<tuple<int, ll>>>(n, vector<tuple<int, ll>>());

    for (int i = 0; i < m; i++) {
        int a, b;
        ll l;
        cin >> a >> b >> l;
        a--, b--;
        graph[a].emplace_back(b, l);
        graph_inv[b].emplace_back(a, l);
    }

    vis_first = vector<bool>(n, false);

    for (int u = 0; u < n; u++) {
        if (vis_first[u]) {
            continue;
        }

        vis_first[u] = true;
        dfs_first(u);
    }

    w_b = vector<ll>(n, 0);
    vis_second = vector<bool>(n, false);
    vector<vector<int>> components;
    while (!order.empty()) {
        int u = order.top();
        order.pop();
        if (vis_second[u]) {
            continue;
        }

        vis_second[u] = true;
        component.clear();
        dfs_second(u);
        components.push_back(component);
    }

    vector<int> v_comp(n, -1);
    for (int i = 0; i < components.size(); i++) {
        for (int j = 0; j < components[i].size(); j++) {
            int v = components[i][j];
            v_comp[v] = i;
        }
    }

    vector<vector<tuple<int, ll>>> bi_graph(n, vector<tuple<int, ll>>());

    for (int u = 0; u < n; u++) {
        for (auto [v, l] : graph[u]) {
            if (v_comp[u] == v_comp[v]) {
                bi_graph[u].emplace_back(v, l);
            }
        }
    }

    int num_comp = components.size();
    vector<ll> v_d(n, 0);
    vector<bool> vis_1(n, false);
    vector<ll> w_f(n, 0);
    for (int comp_i = 0; comp_i < num_comp; comp_i++) {
        int v = components[comp_i][0];
        int s = components[comp_i].size();
        
        queue<int> bfs;
        bfs.push(v);
        vis_1[v] = true;
        while (!bfs.empty()) {
            auto u = bfs.front();
            bfs.pop();
            
            for (auto [w, l] : bi_graph[u]) {
                if (!vis_1[w]) {
                    vis_1[w] = true;
                    w_f[w] = w_f[u] + l;
                    bfs.push(w);
                }
            }
        }

        ll total_gcd = 0;
        for (auto v : components[comp_i]) {
            for (auto [u, l] : bi_graph[v]) {
                total_gcd = gcd_slow(total_gcd, w_f[v] + l + w_b[u]);
            }
        }

        for (auto v : components[comp_i]) {
            v_d[v] = total_gcd;
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int v;
        ll s, t;
        cin >> v >> s >> t;
        v--;
        if (s % gcd_slow(t, v_d[v]) == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}