#include <bits/stdc++.h>
using namespace std;
using LL = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for (cin >> t; t; t -= 1) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i += 1) cin >> a[i];
        vector<int> b(n + 1), v(n + 1), c(n + 1);
        for (int i = 1; i <= n; i += 1) c[a[i]] += 1;
        vector<pair<int, int>> vp;
        for (int i = 1; i <= n; i += 1) if(c[i] == 0) {
            vp.push_back({i, 0});
            for (int j = i; ; j = a[j]) {
                v[j] = 1;
                if (v[a[j]]) {
                    vp.back().second = j;
                    break;
                }
                b[j] = a[j];
            }
        }
        for (int i = 0; i < vp.size(); i += 1)
            b[vp[i].second] = vp[(i + 1) % vp.size()].first;
        for (int i = 1; i <= n; i += 1) if (not b[i]) b[i] = a[i];
        int ans = 0;
        for (int i = 1; i <= n; i += 1) {
            ans += a[i] == b[i];
            assert(i != b[i]);
        }
        cout << ans << "\n";
        for (int i = 1; i <= n; i += 1) cout << b[i] << " ";
        cout << "\n";
    }
    return 0;
}