#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 100000;

int phi[N + 1];
i64 sphi[N + 1];
bool isprime[N + 1];

std::vector<int> primes;

i64 dp[19][N + 1];

std::vector<int> dvd[N + 1];
std::vector<i64> pre[N + 1];

i64 c(int l, int r) {
    i64 res = 1LL * r * (r + 1) / 2;
    if (l > 1) {
        int k = std::upper_bound(dvd[r].begin(), dvd[r].end(), l) - dvd[r].begin() - 1;
        res -= pre[r][k] + (l - dvd[r][k]) * sphi[r / (l - 1)];
    }
    return res;
}

void solve() {
    int n, k;
    std::cin >> n >> k;
    
    if (k > 18) {
        std::cout << n << "\n";
        return;
    }
    
    std::cout << dp[k][n] << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::fill(isprime + 2, isprime + N + 1, true);
    phi[1] = 1;
    for (int i = 2; i <= N; i++) {
        if (isprime[i]) {
            phi[i] = i - 1;
            primes.push_back(i);
        }
        for (auto p : primes) {
            if (i * p > N) {
                break;
            }
            isprime[i * p] = false;
            if (i % p == 0) {
                phi[i * p] = phi[i] * p;
                break;
            }
            phi[i * p] = phi[i] * (p - 1);
        }
    }
    for (int i = 1; i <= N; i++) {
        sphi[i] = sphi[i - 1] + phi[i];
    }
    
    for (int i = 1; i <= N; i++) {
        i64 s = 0;
        for (int j = 1, k; j <= i; j = k + 1) {
            int v = i / j;
            k = i / v;
            dvd[i].push_back(j);
            pre[i].push_back(s);
            s += sphi[v] * (k - j + 1);
        }
    }
    
    for (int i = 1; i <= N; i++) {
        dp[1][i] = c(1, i);
    }
    for (int k = 2; k <= 18; k++) {
        std::function<void(int, int, int, int)> solve = [&](int l, int r, int L, int R) {
            if (l > r) {
                return;
            }
            int m = (l + r) / 2;
            int g = -1;
            i64 v = 1E18;
            for (int i = L; i <= std::min(m - 1, R); i++) {
                i64 res = dp[k - 1][i] + c(i + 1, m);
                if (res < v) {
                    v = res;
                    g = i;
                }
            }
            dp[k][m] = v;
            solve(l, m - 1, L, g);
            solve(m + 1, r, g, R);
        };
        solve(k, N, k - 1, N);
    }
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}