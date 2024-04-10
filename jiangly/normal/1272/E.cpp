#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<vector<int>> e(n);
    for (int i = 0; i < n; ++i) {
        if (i - a[i] >= 0)
            e[i - a[i]].push_back(i);
        if (i + a[i] < n)
            e[i + a[i]].push_back(i);
    }
    vector<int> ans(n);
    for (int d = 0; d < 2; ++d) {
        vector<int> dis(n, -1);
        queue<int> que;
        for (int i = 0; i < n; ++i) {
            if ((a[i] & 1) == d) {
                dis[i] = 0;
                que.push(i);
            }
        }
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            for (int v : e[u]) {
                if (dis[v] == -1) {
                    dis[v] = dis[u] + 1;
                    que.push(v);
                }
            }
        }
        for (int i = 0; i < n; ++i)
            if ((a[i] & 1) != d)
                ans[i] = dis[i];
    }
    for (int i = 0; i < n; ++i)
        cout << ans[i] << " \n"[i == n - 1];
    return 0;
}