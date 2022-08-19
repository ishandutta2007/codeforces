#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> nxt(n);
    set<int> unused;
    for (int i = 0; i < n; ++i)
        unused.insert(i);
    vector<set<int>> e(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u;
        --v;
        e[u].insert(v);
        e[v].insert(u);
    }
    int ans = n - 1;
    auto bfs = [&](int s) {
        queue<int> que;
        que.push(s);
        unused.erase(s);
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            auto it = unused.begin();
            while (it != unused.end()) {
                int v = *it;
                auto nxt = next(it);
                if (!e[u].count(v)) {
                    --ans;
                    que.push(v);
                    unused.erase(it);
                }
                it = nxt;
            }
        }
    };
    for (int i = 0; i < n; ++i)
        if (unused.count(i))
            bfs(i);
    cout << ans << endl;
    return 0;
}