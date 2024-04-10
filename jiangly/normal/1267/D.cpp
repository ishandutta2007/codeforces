#include <bits/stdc++.h>
using namespace std;
constexpr int cnt[] = {0, 1, 1, 2, 1, 2, 2, 3};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> in(n), out(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            int x;
            cin >> x;
            in[i] = 2 * in[i] + x;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            int x;
            cin >> x;
            out[i] = 2 * out[i] + x;
        }
        out[i] &= in[i];
    }
    vector<bool> on(n), ok(n);
    vector<pair<int, int>> edges;
    ok[0] = true;
    queue<int> que;
    que.push(0);
    int x[8];
    fill(x, x + 8, -1);
    while (true) {
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            x[on[u] ? out[u] : in[u]] = u;
            for (int i = 0; i < n; ++i) {
                if (!ok[i] && in[i] == (on[u] ? out[u] : in[u])) {
                    ok[i] = true;
                    edges.emplace_back(u, i);
                    que.push(i);
                    on[i] = true;
                }
            }
        }
        bool found = false;
        for (int i = 0; i < n; ++i) {
            if (!ok[i] && cnt[in[i]] == 2) {
                int a = in[i] & -in[i];
                int b = in[i] - a;
                if (x[a] != -1 && x[b] != -1) {
                    edges.emplace_back(x[a], i);
                    edges.emplace_back(x[b], i);
                    ok[i] = true;
                    que.push(i);
                    found = true;
                    break;
                }
            }
        }
        if (!found)
            break;
    }
    for (int i = 0; i < n; ++i) {
        if (!ok[i]) {
            cout << "Impossible\n";
            return 0;
        }
    }
    cout << "Possible\n";
    for (int i = 0; i < n; ++i)
        cout << on[i] << " \n"[i == n - 1];
    cout << edges.size() << "\n";
    for (auto e : edges)
        cout << e.first + 1 << " " << e.second + 1 << "\n";
    return 0;
}