#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5, MAXK = 9;
vector<array<int, 2>> g[MAXN];
int in[MAXN][MAXK * MAXK];
int a[MAXK * MAXK][MAXK * MAXK];

int ans = 0;
int k;

void get(int x, vector<bool> used) {
    /**cout << x << endl;
    for (int sz = 0; sz < k; ++sz) {
        for (int j = 0; j <= sz; ++j) {
            cout << used[sz * 9 + j] << " ";
        }
        cout << endl;
    }*/
    if (x == k) {
        ans++;
        return;
    }
    for (int j = 0; j <= x; ++j) {
        int num = x * 9 + j;
        if (used[num] || a[num][num]) {
            continue;
        }
        vector<bool> p(used.size());
        for (int i = 0; i < used.size(); ++i) {
            p[i] = used[i];
        }
        for (int i = 0; i < used.size(); ++i) {
            if (a[num][i]) {
                p[i] = 1;
            }
        }
        get(x + 1, p);
    }
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m >> k;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        g[u].push_back({w, v});
    }
    for (int i = 0; i < n; ++i) {
        sort(g[i].begin(), g[i].end());
        int sz = g[i].size();
        for (int j = 0; j < sz; ++j) {
            in[g[i][j][1]][(sz - 1) * 9 + j]++;
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 9 * k; ++j) {
            if (in[i][j] == 0) {
                continue;
            }
            if (in[i][j] >= 2) {
                a[j][j] = 1;
            }
            for (int q = 0; q < j; ++q) {
                if (in[i][q] == 0) {
                    continue;
                }
                a[j][q] = 1;
                a[q][j] = 1;
            }
        }
    }
    vector<bool> used(k * 9, 0);
    get(0, used);
    cout << ans;
    return 0;
}