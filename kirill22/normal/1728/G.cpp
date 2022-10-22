#include<bits/stdc++.h>

using namespace std;

//#define int long long

const int mod = 998244353;

inline int mul(int x, int y) {
    return 1ll * x * y % mod;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int d, n, m;
    cin >> d >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<int> b(m);
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    b.push_back((int) -1e7);
    b.push_back((int) 1e7);
    sort(b.begin(), b.end());
    m += 2;
    vector<vector<int>> dp1(m, vector<int> (m));
    for (int l = 0; l < m; l++) {
        for (int r = l; r < m; r++) {
            dp1[l][r] = 1;
            for (auto x : a) {
                if (b[l] < x && x < b[r]) {
                    int mx = min(d, min(x - b[l] - 1, b[r] - x - 1));
                    dp1[l][r] = mul(dp1[l][r], mx + 1);
                }
            }
        }
    }
    vector<vector<int>> dp2(m, vector<int> (m));
    for (int l = 0; l < m; l++) {
        for (int r = l; r < m; r++) {
            dp2[l][r] = dp1[l][r];
            for (int i = l + 1; i < r; i++) {
                dp2[l][r] = (dp2[l][r] - mul(dp2[l][i], dp1[i][r]) + mod) % mod;
            }
        }
    }
    int all = dp2[0][m - 1];
    vector<vector<int>> dp(m, vector<int> (m));
    for (int L = 0; L + 1 < m; L++) {
        dp[L][L + 1] = all;
    }
    for (int L = m - 1; L >= 0; L--) {
        for (int R = L + 2; R < m; R++) {
            if (R - L == 2) {
                dp[L][R] = (all + dp2[0][L + 1] * 1ll * dp2[R - 1][m - 1]) % mod;
            } else {
                dp[L][R] = ((dp[L + 1][R] + dp[L][R - 1]) % mod - dp[L + 1][R - 1] + mod) % mod;
                dp[L][R] = (dp[L][R] + mul(dp2[0][L + 1], mul(dp2[R - 1][m - 1], dp1[L + 1][R - 1]))) % mod;
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;
        vector<int> D = {0, d + 1};
        for (auto y : b) {
            D.push_back(abs(x - y));
        }
        sort(D.begin(), D.end());
        int ans = 0;
        for (int i = 0; i < (int) D.size() && D[i] <= d; i++) {
            int l = x - D[i], r = x + D[i];
            int res = D[i + 1] - D[i];
            int L = -1;
            while (L + 1 < m && !(l <= b[L + 1] && b[L + 1] <= r)) {
                L++;
            }
            int R = m;
            while (R > 0 && !(l <= b[R - 1] && b[R - 1] <= r)) {
                R--;
            }
            if (L == 0 && R == m - 1) {
                res = mul(res, dp1[0][m - 1]);
            } else if (L == m - 1) {
                res = mul(res, dp2[0][m - 1]);
            }  else {
                res = mul(res, dp[L][R]);
            }
            ans = (ans + res) % mod;
        }
        cout << ans << '\n';
    }
}