#include<bits/stdc++.h>

using namespace std;

// fuck life

const int mod = 998244353, N = 13;
int dp[N][N][N], dp2[N][23][N][N], used[N], mx;
vector<int> tmp;

bool check() {
    if ((int) tmp.size() == 0) {
        return true;
    }
    for (auto x : tmp) {
        if (x >= (int) tmp.size()) {
            return true;
        }
    }
    return false;
}

void dfs(int n, int inv, int pos) {
    if (inv > 11 || pos > 11) {
        return;
    }
    if (n == mx) {
        dp[n][inv][pos]++;
        return;
    }
    if (!check()) {
        return;
    }
    for (int x = 0; x < mx; x++) {
        if (!used[x]) {
            used[x] = 1;
            int inv2 = inv, pos2 = pos;
            if ((int) tmp.size() && tmp.back() > x) {
                pos2++;
            }
            for (auto y : tmp) {
                inv2 += (y > x);
            }
            tmp.push_back(x);
            dfs(n + 1, inv2, pos2);
            tmp.pop_back();
            used[x] = 0;
        }
    }
}

int binpow(int a, int n) {
    int res = 1;
    while (n) {
        if (n % 2 == 1) {
            res = res * 1ll * a % mod;
        }
        n >>= 1;
        a = a * 1ll * a % mod;
    }
    return res;
}

int inv(int x) {
    return binpow(x, mod - 2);
}

int C(int n, int x) {
    int res = 1;
    for (int i = 1; i <= x; i++) {
        res = res * 1ll * inv(i) % mod;
    }
    for (int i = n - x + 1; i <= n; i++) {
        res = res * 1ll * i % mod;
    }
    return res;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for (mx = 2; mx <= 12; mx++) {
        dfs(0, 0, 0);
    }
    dp2[0][0][0][0] = 1;
    for (int c = 0; c + 1 < N; c++) {
        for (int n = 0; n < 23; n++) {
            for (int inv = 0; inv < N; inv++) {
                for (int pos = 0; pos < N; pos++) {
                    if (dp2[c][n][inv][pos] == 0) {
                        continue;
                    }
                    int x = dp2[c][n][inv][pos];
                    for (int n1 = 0; n + n1 < 23 && n1 <= 12; n1++) {
                        for (int inv1 = 1; inv + inv1 < N; inv1++) {
                            for (int pos1 = 0; pos + pos1 < N; pos1++) {
                                int y = x * 1ll * dp[n1][inv1][pos1] % mod;
                                dp2[c + 1][n + n1][inv + inv1][pos + pos1] = (dp2[c + 1][n + n1][inv + inv1][pos + pos1] + y) % mod;
                            }
                        }
                    }
                }
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int m, k, x;
        cin >> m >> k >> x;
        int ans = 0;
        for (int c = 0; c < N; c++) {
            for (int n = 0; n < 23; n++) {
                if (dp2[c][n][k][x] == 0) {
                    continue;
                }
                if (n > m) {
                    continue;
                }
                //cout << c << " " << n << " " << k << " " << x << endl;
                ans = (ans + dp2[c][n][k][x] * 1ll * C(m - n + c, c) % mod) % mod;
            }
        }
        cout << ans << '\n';
    }
}