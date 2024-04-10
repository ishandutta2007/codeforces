#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, m;
        cin >> n >> m;
        vector<LL> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; i += 1) {
            cin >> a[i];
            a[i] += a[i - 1];
        }
        for (int i = 1; i <= n; i += 1) {
            cin >> b[i];
            b[i] += b[i - 1];
        }
        vector<pair<int, int>> q(m);
        vector<vector<int>> G(n + 1);
        for (int i = 0; i < m; i += 1) {
            auto& [x, y] = q[i];
            cin >> x >> y;
            x -= 1;
            G[x].push_back(i);
            G[y].push_back(i);
        }
        set<int> s;
        queue<int> qq;
        for (int i = 0; i <= n; i += 1)
            if (a[i] == b[i])
                qq.push(i);
            else s.insert(i);
        while (not qq.empty()) {
            int u = qq.front();
            qq.pop();
            for (int i : G[u]) {
                auto [x, y] = q[i];
                if (a[x] == b[x] and a[y] == b[y])
                    for (auto it = s.lower_bound(x); it != s.end() and *it <= y; it = s.erase(it)) {
                        a[*it] = b[*it];
                        qq.push(*it);
                    }
            }
        }
        cout << (a == b ? "YES\n" : "NO\n");
    }
    return 0;
}