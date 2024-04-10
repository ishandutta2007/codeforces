#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> l(n), r(n), a(2 * n);
    for (int i = 0; i < n; ++i) {
        cin >> l[i] >> r[i];
        --l[i];
        --r[i];
        a[l[i]] = a[r[i]] = i;
    }
    set<int> ends;
    vector<vector<int>> e(n);
    int cnt = 0;
    for (int i = 0; i < 2 * n; ++i) {
        if (i == l[a[i]]) {
            for (int j : ends) {
                if (j > r[a[i]])
                    break;
                ++cnt;
                if (cnt >= n) {
                    cout << "NO\n";
                    return 0;
                }
                e[a[i]].push_back(a[j]);
                e[a[j]].push_back(a[i]);
            }
            ends.insert(r[a[i]]);
        } else {
            ends.erase(i);
        }
    }
    vector<bool> vis(n);
    queue<int> q;
    vis[0] = true;
    q.push(0);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : e[u]) {
            if (!vis[v]) {
                vis[v] = true;
                q.push(v);
            }
        }
    }
    for (bool i : vis) {
        if (!i) {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}