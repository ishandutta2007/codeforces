#include "bits/stdc++.h"
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> w(n);
    for (auto& x : w)
        cin >> x;
    
    vector<pair<int, int>> v(m);
    for (auto& p : v) {
        cin >> p.first >> p.second;
        p.first--;
        p.second--;
    }

    vector<int> W = w;
    vector<bool> seen(m, false);
    vector<vector<int>> who(n);
    for (int i = 0; i < m; i++) {
        auto [x, y] = v[i];
        W[x]--;
        W[y]--;
        who[x].push_back(i);
        who[y].push_back(i);
    }

    vector<bool> in_queue(n, false);
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (W[i] >= 0) {
            q.push(i);
            in_queue[i] = true;
        }
    }

    vector<int> order;
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (int fr : who[cur]) {
            if (seen[fr])
                continue;
            order.push_back(fr);
            seen[fr] = true;
            auto [x, y] = v[fr];
            W[x]++;
            W[y]++;
            if (W[x] == 0) {
                in_queue[x] = true;
                q.push(x);
            }
            if (W[y] == 0) {
                in_queue[y] = true;
                q.push(y);
            }
        }
    }
    if (order.size() == m) {
        cout << "ALIVE" << '\n';
        reverse(order.begin(), order.end());
        for (int x : order)
            cout << x + 1 << ' ';
        cout << "\n";
    } else {
        cout << "DEAD" << '\n';
    }
}