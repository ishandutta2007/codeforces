#include <bits/stdc++.h>
using namespace std;
using LL = long long;
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, k;
        cin >> n >> k;
        vector<int> v(2 * n + 1);
        vector<pair<int, int>> vp;
        for (int i = 0, x, y; i < k; i += 1) {
            cin >> x >> y;
            vp.push_back({x, y});
            v[x] = v[y] = 1;
        }
        vector<int> w;
        for (int i = 1; i <= 2 * n; i += 1) if (not v[i]) w.push_back(i);
        for (int i = 0; i < n - k; i += 1) vp.push_back({w[i], w[i + n - k]});
        int ans = 0;
        for (int i = 0; i < n; i += 1) {
            if (vp[i].first > vp[i].second) swap(vp[i].first, vp[i].second);
            for (int j = i + 1; j < n; j += 1) {
                int x = vp[i].first <= vp[j].first and vp[j].first <= vp[i].second;
                int y = vp[i].first <= vp[j].second and vp[j].second <= vp[i].second;
                ans += x != y;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}