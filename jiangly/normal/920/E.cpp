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
    vector<int> sol;
    auto bfs = [&](int s) {
        queue<int> que;
        que.push(s);
        unused.erase(s);
        int t = 0;
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            ++t;
            auto it = unused.begin();
            while (it != unused.end()) {
                int v = *it;
                auto nxt = next(it);
                if (!e[u].count(v)) {
                    que.push(v);
                    unused.erase(it);
                }
                it = nxt;
            }
        }
        sol.push_back(t);
    };
    for (int i = 0; i < n; ++i)
        if (unused.count(i))
            bfs(i);
    sort(sol.begin(), sol.end());
    cout << sol.size() << "\n";
    for (int i = 0; i < sol.size(); ++i)
        cout << sol[i] << " \n"[i + 1 == sol.size()];
    return 0;
}