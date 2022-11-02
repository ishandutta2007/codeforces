#include <bits/stdc++.h>
using namespace std;

const int MAXN = 3e5;
unordered_set<int> g[MAXN];
unordered_set<int> nst;
int arr[MAXN];

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        arr[i]--;
    }
    // cout << arr[n - 1] << endl;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        if (v != arr[n - 1]) {
            g[u].insert(v);
        } else {
            nst.insert(u);
        }
    }
    unordered_set<int> now;
    int ans = 0;
    for (int i = n - 2; i >= 0; --i) {
        if (!nst.count(arr[i])) {
            now.insert(arr[i]);
            continue;
        }
        // cout << 1 << endl;
        int cnt = 0;
        for (auto elem : g[arr[i]]) {
            if (now.count(elem)) {
                cnt++;
            }
        }

        if (cnt == now.size()) {
            ans++;
        } else {
            now.insert(arr[i]);
        }
    }
    cout << ans;
    return 0;
}