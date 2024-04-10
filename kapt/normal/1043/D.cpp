#include <bits/stdc++.h>
using namespace std;
#define int int64_t
#pragma GCC optimize("O3")

const int maxn = 2e5, maxm = 10, mod = 1e9 + 7, p = 179179;
int pref[maxm][maxn];
int arr[maxm][maxn], deg[maxn];
int m, n;
int st[maxm];
int b[maxm][maxn];

inline int hash1(int i, int s, int len) {
    int p1 = pref[i][s];
    int p2 = pref[i][s + len];
    return (p2 - p1 * deg[len]) % mod;
}

inline bool check(int len) {
    int f = true;
    if (st[0] + len > n) {
        return false;
    }
    int h = hash1(0, st[0], len);
    for (int i = 1; i < m; ++i) {
        if (st[i] + len > n || (hash1(i, st[i], len) - h) % mod != 0) {
            f = false;
            break;
        }
    }
    return f;
}

main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> arr[i][j];
            b[i][arr[i][j]] = j;
            pref[i][j + 1] = (pref[i][j] * p + arr[i][j]) % mod;
        }
    }
    deg[0] = 1;
    for (int i = 1; i < n; ++i) {
        deg[i] = (deg[i - 1] * p) % mod;
    }
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < m; ++j) {
            st[j] = b[j][i];
        }
        int l = 1, r = n + 1;
        while (r - l > 1) {
            int m = (l + r) / 2;
            if (check(m)) {
                l = m;
            } else {
                r = m;
            }
        }
        ans += l;
    }
    cout << ans;
    return 0;
}