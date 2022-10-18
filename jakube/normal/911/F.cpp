#include <bits/stdc++.h>
using namespace std;


std::vector<std::vector<int>> adj;
vector<int> pre;

std::pair<int, std::vector<int>> bfs(int start) {
    int n = adj.size();
    std::vector<bool> found(n, false);
    std::queue<std::pair<int, int>> q;
    std::vector<int> dist_to_start(n);
    pre.resize(n);

    q.push({start, 0});
    found[start] = true;
    pre[start] = -1;

    int cur;
    while (!q.empty()) {
        auto p = q.front();
        cur = p.first;
        int dist = p.second;
        q.pop();

        dist_to_start[cur] = dist;

        for (auto next : adj[cur]) {
            if (!found[next]) {
                q.push({next, dist + 1});
                pre[next] = cur;
                found[next] = true;
            }
        }
    }

    return {cur, dist_to_start};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    adj.resize(n);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    auto x = bfs(0);
    auto end1 = x.first;
    auto y = bfs(end1);
    auto end2 = y.first;
    auto& dist_from_end1 = y.second;
    // get nodes of diameter
    vector<bool> on_diameter(n, false);
    int cur = end2;
    vector<int> dia;
    while (cur >= 0) {
        on_diameter[cur] = true;
        dia.push_back(cur);
        cur = pre[cur];
    }

    auto z = bfs(end2);
    auto& dist_from_end2 = z.second;

    long long sum = 0;
    for (int i = 0; i < n; i++) {
        if (!on_diameter[i]) {
            sum += max(dist_from_end1[i], dist_from_end2[i]);
        }
    }

    long long diameter = dist_from_end1[end2];
    sum += diameter * (diameter + 1) / 2;
    cout << sum << '\n';

    queue<int> leaves;
    vector<int> adjc(n, 0);
    for (int i = 0; i < n; i++) {
        adjc[i] = adj[i].size();
        if (adjc[i] == 1 && !on_diameter[i])
            leaves.push(i);
    }

    while (!leaves.empty()) {
        int a = leaves.front();
        leaves.pop();
        int to1 = dist_from_end1[a];
        int to2 = dist_from_end2[a];
        if (to1 > to2)
            cout << a + 1 << " " << end1 + 1 << " " << a + 1 << '\n';
        else
            cout << a + 1 << " " << end2 + 1 << " " << a + 1 << '\n';
        for (int next : adj[a]) {
            adjc[next]--;
            if (adjc[next] == 1 && !on_diameter[next])
                leaves.push(next);
        }
    }

    for (int i = 0; i < (int)dia.size() - 1; i++) {
        cout << dia[i] + 1 << " " << dia.back() + 1 << " " << dia[i] + 1 << '\n';
    }
}