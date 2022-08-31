#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    long long total = accumulate(a.begin(), a.end(), 0LL);
    long long res = 0;
    vector<int> c(n);
    map<pair<int, int>, int> b;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int s, t, u;
        cin >> s >> t >> u;
        --s;
        --u;
        if (b.count({s, t})) {
            int x = b[{s, t}];
            b.erase({s, t});
            res -= min(c[x], a[x]);
            --c[x];
            res += min(c[x], a[x]);
        }
        if (u != -1) {
            res -= min(c[u], a[u]);
            ++c[u];
            res += min(c[u], a[u]);
            b[{s, t}] = u;
        }
        cout << total - res << "\n";
    }
    return 0;
}