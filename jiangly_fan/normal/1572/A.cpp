#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<vector<int>> G(n + 1);
        vector<int> d(n + 1), dp(n + 1, 0);
        for (int i = 1; i <= n; i += 1) {
            int k;
            cin >> k;
            for (int j = 0, x; j < k; j += 1) {
                cin >> x;
                G[x].push_back(i);
                d[i] += 1;
            }
        }
        set<int> s;
        for (int i = 1; i <= n; i += 1) if (not d[i]) s.insert(i);
        int c = n, ans = 0;
        while (not s.empty()) {
            int x = 1;
            while (s.lower_bound(x) != s.end()) {
                int u = *s.lower_bound(x);
                for (int v : G[u]) if (not (d[v] -= 1)) s.insert(v);
                s.erase(u);
                c -= 1;
                x = u;
            }
            ans += 1;
        }
        if (c) cout << "-1\n";
        else cout << ans << "\n";
    }
    return 0;
}