#include<bits/stdc++.h>

using namespace std;

#define int long long

int n, m;
vector<vector<int>> g;
vector<int> ans;

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    g.resize(n);
    ans.resize(n, 3);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<bool> used(n, false);
    for (auto c : g[0]) {
        used[c] = true;
    }
    int k = -1;
    for (int i = 0; i < n; i++) {
        if (used[i] == false) {
            ans[i] = 1;
        }
        else {
            k = i;
        }
    }
    if (k == -1) {
        cout << -1;
        return 0;
    }
    for (auto c : g[k]) {
        used[c] = false;
    }
    for (int i = 0; i < n; i++) {
        if (used[i]) {
            ans[i] = 2;
        }
    }
    int a1 = 0, a2 = 0, a3 = 0;
    for (int i = 0; i < n; i++) {
        if (ans[i] == 1) {
            a1++;
        }
        if (ans[i] == 2) {
            a2++;
        }
        if (ans[i] == 3) {
            a3++;
        }
    }
    int res = a1 * a2 + a1 * a3 + a2 * a3;
    if (res != m || a1 == 0 || a2 == 0 || a3 == 0) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (auto c : g[i]) {
            if (ans[c] == ans[i]) {
                cout << -1;
                return 0;
            }
        }
    }
    for (auto c : ans) {
        cout << c << " ";
    }
}