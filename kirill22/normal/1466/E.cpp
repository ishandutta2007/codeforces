#include<bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m = 60;
        cin >> n;
        vector<long long> a(n);
        vector<int> cnt(m);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            for (int j = 0; j < m; j++) {
                if (a[i] >> j & 1) {
                    cnt[j]++;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int> l(m), r(m);
            for (int j = 0; j < m; j++) {
                if (a[i] >> j & 1) {
                    r[j] = n;
                    l[j] = cnt[j];
                } else {
                    r[j] = cnt[j];
                }
                l[j] = l[j] * 1ll * ((1ll << j) % mod) % mod;
                r[j] = r[j] * 1ll * ((1ll << j) % mod) % mod;
            }
            int L = 0, R = 0;
            for (auto x : l) {
                L = (L + x) % mod;
            }
            for (auto x : r) {
                R = (R + x) % mod;
            }
            ans = (ans + L * 1ll * R) % mod;
        }
        cout << ans << '\n';
    }
}