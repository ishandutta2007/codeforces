#include<bits/stdc++.h>

using namespace std;

const int mod = 998244353;

int binpow(int x, int n) {
    int res = 1;
    while (n) {
        if (n & 1) {
            res = res * 1ll * x % mod;
        }
        n >>= 1;
        x = x * 1ll * x % mod;
    }
    return res;
}

inline void add(int& x, long long y) {
    x += y % mod;
    if (x >= mod) {
        x -= mod;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, c;
    cin >> n >> c;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    int mx = 1;
    set<int> st;
    for (auto x : a) {
        st.insert(x);
        if ((int) st.size() == c) {
            st.clear();
            mx++;
        }
    }
    vector<vector<int>> dp(n + 1, vector<int> (mx));
    dp[0][0] = 1;
    vector<int> pw(n + 1, 1), inv(n + 1);
    for (int i = 1; i <= n; i++) {
        pw[i] = pw[i - 1] * 1ll * 2 % mod;
    }
    for (int i = 1; i <= n; i++) {
        inv[i] = binpow(pw[i] - 1, mod - 2);
    }
    if (c > 9) {
        vector<vector<int>> cnt(n, vector<int> (n));
        for (int i = 0; i < n; i++) {
            vector<int> gist(c);
            int s = 1, need = c;
            for (int j = i; j < n; j++) {
                if (gist[a[j]]) {
                    s = s * 1ll * inv[gist[a[j]]] % mod;
                } else {
                    need--;
                }
                gist[a[j]]++;
                s = s * 1ll * (pw[gist[a[j]]] - 1) % mod;
                if (!need) {
                    cnt[i][j] = s * 1ll * inv[gist[a[j]]] % mod;
                }
            }
        }
        vector<vector<int>> dp2(mx, vector<int> (n + 1));
        dp2[0][0] = 1;
        for (int k = 1; k < mx; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = (k - 1) * c; j < i; j++) {
                    add(dp2[k][i], dp2[k - 1][j] * 1ll * cnt[j][i - 1]);
                }
            }
        }
        for (int c = 0; c < mx; c++) {
            for (int i = 0; i <= n; i++) {
                dp[i][c] = dp2[c][i];
            }
        }
    } else {
        vector<vector<int>> tmp(mx, vector<int> (1 << c));
        auto tmp2 = tmp;
        tmp[0][0] = 1;
        for (int i = 0; i < n; i++) {
            int x = a[i];
            for (int k = 1; k < mx; k++) {
                dp[i + 1][k] = tmp[k - 1][(1 << c) - 1 - (1 << x)];
            }
            for (int k = 0; k < mx; k++) {
                for (int msk = 0; msk < (1 << c); msk++) {
                    tmp2[k][msk] = 0;
                    if (msk == 0) {
                        add(tmp2[k][msk], dp[i + 1][k] + tmp[k][msk]);
                    } else {
                        if (msk >> x & 1) {
                            add(tmp2[k][msk], 2 * 1ll * tmp[k][msk] + tmp[k][msk - (1 << x)]);
                        } else {
                            tmp2[k][msk] = tmp[k][msk];
                        }
                    }
                }
            }
            tmp = tmp2;
        }
    }
    vector<int> ans(n + 2);
    ans[0] = pw[n] - 1;
    for (int i = 1; i < mx; i++) {
        for (int j = 0; j <= n; j++) {
            ans[i] = (ans[i] + dp[j][i] * 1ll * pw[n - j]) % mod;
        }
    }
    for (int i = 0; i <= n; i++) {
        cout << (ans[i] - ans[i + 1] + mod) % mod << " ";
    }
}