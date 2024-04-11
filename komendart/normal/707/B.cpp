#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 5;

int n, m, k;
tuple<int, int, int> edges[maxn];
char good[maxn];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int v, u, l;
        cin >> v >> u >> l;
        v--; u--;
        edges[i] = make_tuple(v, u, l);
    }
    for (int i = 0; i < k; i++) {
        int t; cin >> t; t--;
        good[t] = true;
    }
    int ans = 1e9 + 5;
    for (int i = 0; i < m; i++) {
        int v, u, l;
        tie(v, u, l) = edges[i];
        if (good[v] ^ good[u]) {
            ans = min(ans, l);
        }
    }
    if (ans == (int) 1e9 + 5) cout << -1 << '\n';
    else cout << ans << '\n';
}