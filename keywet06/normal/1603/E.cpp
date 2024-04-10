#include <bits/stdc++.h>

using int64 = long long;

const int N = 210;

int64 P;

int n;

int64 Pow(int64 a, int64 b) {
    if (!b) return 1ll;
    return b % 2 ? Pow(a, b - 1) * a % P : Pow(a * a % P, b / 2ll);
}

int dp[N][N][N];
int64 f[N], rf[N];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    std::cin >> n >> P;
    f[0] = rf[0] = 1;
    for (int64 i = 1; i <= n; ++i) f[i] = (f[i - 1] * i) % P, rf[i] = Pow(f[i], P - 2);
    int64 res = 0ll;
    int VVV = n + 1, cnt = 0;
    for (int mn = n; mn >= 1; --mn) {
        memset(dp, 0, sizeof(dp));
        for (int cn = 1; cn <= mn; ++cn) dp[mn][0][cn] = rf[cn];
        for (int el = mn; el <= n; ++el) {
            for (int sum = 0; sum <= mn; ++sum) {
                for (int cn = 1; cn <= n; ++cn) {
                    int L = (el == n);
                    int R = std::min({n, ((el + 1 - cn) * mn - sum) / (el + 1), (mn - sum) / (el + 1 - mn)});
                    for (int nw = L; nw <= R; ++nw) {
                        if (sum + nw * (el + 1 - mn) > mn) exit(1);
                        dp[el + 1][sum + nw * (el + 1 - mn)][cn + nw] =
                            (dp[el + 1][sum + nw * (el + 1 - mn)][cn + nw] + dp[el][sum][cn] * rf[nw]) % P;
                    }
                }
            }
        }
        int64 last = res;
        for (int sum = 0; sum <= mn; ++sum) res = (res + dp[n + 1][sum][n] * f[n]) % P;
        cnt = last == res ? cnt + 1 : 0;
        if (cnt == 3) break;
    }
    res += 2, res %= P;
    std::cout << res << '\n';
    return 0;
}