#include <bits/stdc++.h>

using namespace std;

typedef long double float96;

const int N = 55;
const int S = 5500;

int n, r;
int f[N], s[N];

float96 p[N];
float96 dp[N][S];

float96 csolve(float96 x) {
    for (int i = 0; i < S; ++i) dp[n][i] = i <= r ? 0 : x;
    for (int i = n - 1; i >= 0; --i) {
        for (int j = 0; j < S - 200; ++j) {
            float96 d1 = x;
            float96 d2 = p[i] * (f[i] + dp[i + 1][j + f[i]]) +
                         (1. - p[i]) * (s[i] + dp[i + 1][j + s[i]]);
            dp[i][j] = d2;
            if (i) dp[i][j] = std::min(dp[i][j], d1);
        }
    }
    return dp[0][0];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> r;
    for (int i = 0; i < n; ++i) {
        cin >> f[i] >> s[i] >> p[i];
        p[i] /= 100.;
    }
    float96 lo = 0.0, hi = 1e16;
    while (hi - lo > 1e-11) {
        float96 mid = (hi + lo) / 2.;
        float96 sscore = csolve(mid);
        (sscore > mid ? lo : hi) = mid;
    }
    std::cout << std::fixed << std::setprecision(11);
    std::cout << lo << "\n";
    return 0;
}