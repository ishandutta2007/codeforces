#include <iostream>
#include <algorithm>
#include <string>
#include <utility>
#include <tuple>
#include <vector>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <queue>
using namespace std;
typedef long long ll;
vector<vector<int>> graph;
vector<vector<int>> children;
vector<int> p;
vector<tuple<int, int>> results;


void fillRes(int v, int t, int delta) {
    results.push_back(make_tuple(v, t));
    int prevT = t;
    for (int i = 0; i < children[v].size(); i++) {
        int u = children[v][i];
        if (t == delta) {
            t = prevT - 1 - (children[v].size() - i);
            results.push_back(make_tuple(v, t));
        }
        fillRes(u, t + 1, delta);
        t++;
        results.push_back(make_tuple(v, t));
    }

    if (t >= prevT && prevT != 0) {
        results.push_back(make_tuple(v, prevT - 1));
    }
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    graph = vector<vector<int>>(n, vector<int>());
    children = vector<vector<int>>(n, vector<int>());
    p = vector<int>(n, 0);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> vis(n, false);
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (!vis[v]) {
            vis[v] = true;
            for (auto u : graph[v]) {
                if (u != p[v]) {
                    p[u] = v;
                    q.push(u);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (auto u : graph[i]) {
            if (u != p[i]) children[i].push_back(u);
        }
    }

    int delta = 0;
    for (int i = 0; i < n; i++) {
        delta = max(delta, (int) graph[i].size());
    }

    fillRes(0, 0, delta);
    cout << results.size() << "\n";
    for (auto tup : results) {
        cout << get<0>(tup) + 1 << " " << get<1>(tup) << "\n";
    }
}