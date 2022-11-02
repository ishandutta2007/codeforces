#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;
vector<int> g[MAXN];
array<int, 2> arr[MAXN];
int col[MAXN];
int used[MAXN];

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (int i = 0; i < n; ++i) {
        cin >> arr[i][0];
        col[i] = arr[i][0];
        arr[i][1] = i;
    }
    sort(arr, arr + n);
    for (int i = 0; i < n; ++i) {
        int v = arr[i][1];
        int c = arr[i][0];
        for (auto u : g[v]) {
            used[col[u]] = i + 1;
        }
        int k = -1;
        for (int j = 1;; ++j) {
            if (used[j] != i + 1) {
                k = j;
                break;
            }
        }

        if (k != c) {
            cout << -1;
            return 0;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << arr[i][1] + 1 << " ";
    }
    return 0;
}