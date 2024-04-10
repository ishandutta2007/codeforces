#include <bits/stdc++.h>

using int64 = long long;

const int N = 300005;

bool ghas[N];

int n;
int hv[N], ntot[N], dp[N], Pri[N];

std::vector<int> LPr[N];

bool figure(int x) {
    int np = LPr[x].size();
    int ans = 0;
    for (int i = 0; i < (1 << np); ++i) {
        int ct = 1, s = 1;
        for (int j = 0; j < np; ++j) {
            if (i & (1 << j)) ct *= LPr[x][j], s = -s;
        }
        ans += ntot[ct] * s;
    }
    return (ans != 0);
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    for (int i = 0; i < N; ++i) Pri[i] = -1;
    for (int i = 2; i < N; ++i) {
        if (Pri[i] == -1) {
            LPr[i].push_back(i);
            for (int j = 2 * i; j < N; j += i) Pri[j] = i;
        } else {
            int nv = i / Pri[i];
            for (int x : LPr[nv]) LPr[i].push_back(x);
            if (LPr[i].back() != Pri[i]) LPr[i].push_back(Pri[i]);
        }
    }
    std::cin >> n;
    for (int i = 0, x; i < n; ++i) std::cin >> x, hv[x] = 1;
    for (int i = 1; i < N; ++i) {
        ntot[i] = 0;
        for (int j = i; j < N; j += i) ntot[i] += hv[j];
    }
    for (int i = 1; i < N; ++i) ghas[i] = figure(i);
    for (int i = N - 1; i >= 1; --i) {
        dp[i] = hv[i] ? 1 : 1e9;
        for (int j = 2 * i; j < N; j += i) {
            if (ghas[j / i]) dp[i] = std::min(dp[i], 1 + dp[j]);
        }
    }
    if (dp[1] > 1e6) {
        std::cout << "-1\n";
        return 0;
    }
    std::cout << dp[1] << "\n";
    return 0;
}