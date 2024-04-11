#include <bits/stdc++.h>

using namespace std;

const int maxn = 20;
int n, k;
double p[maxn];
double dp[1 << maxn];
double ans[maxn];

void simple() {
    for (int i = 0; i < n; i++) {
        if (p[i] == 1) {
            for (int j = 0; j < n; j++) {
                if (j == i) cout << 1 << ' ';
                else cout << 0 << ' ';
            }
            exit(0);
        }
    }
    int cnt = n;
    for (int i = 0; i < n; i++) {
        if (p[i] == 0) cnt--;
    }
    if (k >= cnt) {
        for (int i = 0; i < n; i++) {
            if (p[i] == 0) cout << 0 << ' ';
            else cout << 1 << ' ';
        }
        exit(0);
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cout << fixed; cout.precision(10);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    simple();

    dp[0] = 1;
    for (int mask = 0; mask < (1 << n); mask++) {
        if (__builtin_popcount(mask) >= k) continue;
        double sum = 0;
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) sum += p[i];
        }
        for (int i = 0; i < n; i++) {
            if (!(mask & (1 << i))) {
                dp[mask | (1 << i)] += dp[mask] * (p[i] / sum);
            }
        }
    }

    for (int mask = 0; mask < (1 << n); mask++) {
        if (__builtin_popcount(mask) != k) continue;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                ans[i] += dp[mask];
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
}