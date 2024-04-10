#include <bits/stdc++.h>

using namespace std;

const int N = 2000 + 10;
const int P = 998244353;

inline int sum(int a, int b) {
    int c = a + b;
    if (c >= P) c -= P;
    return c;
}

inline void add(int& a, int b) { a = sum(a, b); }
inline int mul(int a, int b) { return 1ll * a * b % P; }

int a[N], b[N];

int pp[N][N][11];
int dp[N][N][11];

void solve() {
    int n;
    cin >> n;
    int F = 0, S = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        int z = 1;
        int v = 0;
        while (x) {
            v = (v + 11 + z * (x % 10)) % 11;
            x /= 10;
            z *= -1;
        }
        if (z == 1) {
            b[S++] = v;
        } else {
            a[F++] = v;
        }
    }
    pp[0][0][0] = 1;
    for (int sum = 0; sum < F; ++sum) {
        int v = a[sum];
        for (int f = 0; f <= sum; ++f) {
            int s = sum - f;
            for (int k = 0; k < 11; ++k) {
                add(pp[f + 1][s][(k + v) % 11], mul(f + 1, pp[f][s][k]));
                add(pp[f][s + 1][(k + 11 - v) % 11], mul(s + 1, pp[f][s][k]));
            }
        }
    }

    for (int k = 0; k < 11; ++k) {
        dp[F / 2 + 1][(F + 1) / 2][k] = pp[(F + 1) / 2][F / 2][k];
    }
    for (int sum = F + 1; sum <= S + F; ++sum) {
        int v = b[sum - F - 1];
        for (int f = 1; f <= sum; ++f) {
            int s = sum - f;
            for (int k = 0; k < 11; ++k) {
                add(dp[f + 1][s][(k + v) % 11], mul(f, dp[f][s][k]));
                add(dp[f][s + 1][(k + 11 - v) % 11], mul(s, dp[f][s][k]));
            }
        }
    }
    int sum = S + F + 1;
    int ans = 0;
    for (int f = 0; f <= sum; ++f) {
        int s = sum - f;
        add(ans, dp[f][s][0]);
    }
    cout << ans << endl;
    for (int i = 0; i <= n + 1; ++i) {
        for (int j = 0; j <= n + 1; ++j) {
            for (int k = 0; k < 11; ++k) dp[i][j][k] = pp[i][j][k] = 0;
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}