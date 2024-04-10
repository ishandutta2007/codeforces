#include <bits/stdc++.h>

typedef long long int64;

const int64 P = 1e9 + 7;
const int N = 1000;

int n;

int64 Br[N][N];
int64 dp[N], dp2[N], a[N];

std::vector<int> Vec;
std::map<int64, int> Map;

void Add(int64 &a, int64 b) { a += b, a %= P; }

int main() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j || j == 0) {
                Br[i][j] = 1;
            } else if (j > i) {
                Br[i][j] = 0;
            } else {
                Br[i][j] = (Br[i - 1][j] + Br[i - 1][j - 1]) % P;
            }
        }
    }
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        for (int j = 2; j * j <= a[i]; ++j) {
            while (a[i] % (j * j) == 0) a[i] /= j * j;
        }
        ++Map[a[i]];
    }
    for (auto it : Map) Vec.push_back(it.second);
    std::sort(Vec.begin(), Vec.end());
    std::reverse(Vec.begin(), Vec.end());
    int cc = Vec[0];
    dp[cc - 1] = 1;
    for (int it = 1; it < Vec.size(); ++it) {
        int c = Vec[it];
        std::fill(dp2, dp2 + cc + c, 0);
        for (int i = 0; i < cc; ++i) {
            if (dp[i] == 0) continue;
            for (int j = 1; j <= c; ++j) {
                for (int k = 0; k <= i && k <= j; ++k) {
                    if (cc + 1 - i >= j - k) {
                        Add(dp2[i - k + (c - j)], dp[i] * Br[i][k] % P * Br[cc + 1 - i][j - k] % P * Br[c - 1][j - 1]);
                    }
                }
            }
        }
        cc += c;
        for (int i = 0; i < cc; ++i) dp[i] = dp2[i];
    }
    int64 ans = dp[0];
    for (int i = 0; i < Vec.size(); ++i) {
        for (int j = 1; j <= Vec[i]; ++j) ans = (ans * j) % P;
    }
    std::cout << ans << "\n";
    return 0;
}