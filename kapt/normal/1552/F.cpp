#include <bits/stdc++.h>
using namespace std;
#define int int64_t

const int MAXN = 3e5, MOD = 998244353;
int x[MAXN], y[MAXN], s[MAXN];
int go[MAXN];
int pref[MAXN];

main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i] >> s[i];
    }
    go[0] = x[0] + x[0] - y[0];
    pref[1] = go[0];
    for (int i = 1; i < n; ++i) {
        go[i] = x[i] - x[i - 1];
        int ind = lower_bound(x, x + n, y[i]) - x;
        /// cout << "ind: " << ind << endl;
        if (ind == i) {
            go[i] += x[i] - y[i];
        } else {
            if (ind == 0) {
                go[i] -= y[i];
            } else {
                go[i] -= y[i] - x[ind - 1];
            }
            go[i] += pref[i] - pref[ind];
            go[i] += x[i] - x[i - 1];
        }
        go[i] = (go[i] % MOD + MOD) % MOD;
        /// cout << go[i] << endl;
        pref[i + 1] = pref[i] + go[i];
        pref[i + 1] %= MOD;
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i]) {
            ans += go[i];
        } else {
            if (i == 0) {
                ans += x[i];
            } else {
                ans += x[i] - x[i - 1];
            }
        }
        ans %= MOD;
    }
    cout << (ans + 1) % MOD;
    return 0;
}