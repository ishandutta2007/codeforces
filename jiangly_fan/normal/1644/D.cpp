#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int t;
    for (cin >> t; t; t -= 1) {
        int n, m, k, q;
        cin >> n >> m >> k >> q;
        vector<int> x(q), y(q);
        for (int i = 0; i < q; i += 1) cin >> x[i] >> y[i];
        set<int> sx, sy;
        LL ans = 1;
        for (int i = q - 1; i >= 0; i -= 1) {
            if ((not sx.contains(x[i]) or not sy.contains(y[i])) and sx.size() < n and sy.size() < m)
                ans = ans * k % mod;
            sx.insert(x[i]);
            sy.insert(y[i]);
        }
        cout << ans << "\n";
    }
}