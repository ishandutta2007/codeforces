#include <bits/stdc++.h>

using namespace std;

using int64 = long long;

class Solver {
   private:
    static constexpr int N = 100 + 5;
    static constexpr int P = 998244353;
    int m;
    char n[N];
    int ans = 0;
    int posa[10], posb[10];
    int dp[2][17][17][17][2][2];
    void Add(int &a, int b) { a += b, a >= P ? a -= P : 0; }

   public:
    void solve() {
        cin >> n + 1;
        m = strlen(n + 1);
        for (int i = 1; i <= m; ++i) {
            n[i] -= '0';
            ans = (ans * 10ll + n[i]) % P;
        }
        for (int x = 1; x <= 9; ++x) {
            for (int y = 1; y < x; ++y) {
                if (__gcd(x, y) != 1) {
                    continue;
                }
                memset(posa, 0, sizeof(posa));
                memset(posb, 0, sizeof(posb));
                int cnt = 9 / x;
                for (int i = 1; i * x <= 9; ++i) {
                    posa[i * x] = 1 << (i - 1);
                    posb[i * y] = 1 << (i - 1);
                }
                int delta = x - 1;
                int lim = x + y - 2;
                memset(dp, 0, sizeof(dp));
                int cur = 0;
                dp[cur][0][0][delta][1][1] = 1;
                for (int i = m; i >= 1; --i) {
                    cur ^= 1;
                    for (int j = 0; j < (1 << cnt); ++j) {
                        for (int k = 0; k < (1 << cnt); ++k) {
                            for (int l = 0; l <= lim; ++l) {
                                dp[cur][j][k][l][0][0] = 0;
                                dp[cur][j][k][l][0][1] = 0;
                                dp[cur][j][k][l][1][0] = 0;
                                dp[cur][j][k][l][1][1] = 0;
                            }
                        }
                    }
                    for (int j = 0; j < (1 << cnt); ++j) {
                        for (int k = 0; k < (1 << cnt); ++k) {
                            for (int l = 0; l <= lim; ++l) {
                                for (int la = 0; la <= 1; ++la) {
                                    for (int lb = 0; lb <= 1; ++lb) {
                                        int val = dp[cur ^ 1][j][k][l][la][lb];
                                        if (val == 0) {
                                            continue;
                                        }
                                        for (int a = 0; a <= 9; ++a) {
                                            for (int b = 0; b <= 9; ++b) {
                                                int p =
                                                    l - delta + y * a - x * b;
                                                if (p % 10 != 0) {
                                                    continue;
                                                }
                                                Add(dp[cur][j | posa[a]]
                                                      [k | posb[b]]
                                                      [p / 10 + delta]
                                                      [a < n[i] ||
                                                       a == n[i] && la]
                                                      [b < n[i] ||
                                                       b == n[i] && lb],
                                                    val);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                int res = 0;
                for (int j = 0; j < (1 << cnt); ++j) {
                    for (int k = 0; k < (1 << cnt); ++k) {
                        if (j & k) {
                            res = (res + dp[cur][j][k][delta][1][1]) % P;
                        }
                    }
                }
                ans = (ans + res * 2ll) % P;
            }
        }
        cout << ans << endl;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    Solver().solve();
    return 0;
}