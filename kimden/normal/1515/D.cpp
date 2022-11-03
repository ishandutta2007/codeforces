#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;





int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, l, r, a;
        cin >> n >> l >> r;
        vector<int> b(n, 0), c(n, 0);
        for (int i = 0; i < l; ++i) {
            cin >> a;
            --a;
            ++b[a];
        }
        for (int i = 0; i < r; ++i) {
            cin >> a;
            --a;
            ++c[a];
        }
        int ans = 0;
        int g = 0;
        int d = 0;
        int gg = 0;
        int dd = 0;
        for (int i = 0; i < n; ++i) {
            int o = min(b[i], c[i]);
            b[i] -= o;
            c[i] -= o;
//            ans += b[i] / 2;
//            b[i] %= 2;
//            ans += c[i] / 2;
//            c[i] %= 2;
            g += b[i];
            d += c[i];
            gg += b[i] / 2;
            dd += c[i] / 2;
        }
        if (g >= d) {
            int extra_g = min(g - d, 2 * gg) / 2;
            g -= 2 * extra_g;
            ans += extra_g;
        } else {
            int extra_d = min(d - g, 2 * dd) / 2;
            d -= 2 * extra_d;
            ans += extra_d;
        }
        int u = min(g, d);
        g -= u;
        d -= u;
        ans += u;
        ans += (g + d) / 2 * 2;
        cout << ans << "\n";
    }



}