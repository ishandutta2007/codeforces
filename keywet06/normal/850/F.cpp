#include <bits/stdc++.h>

const int P = 1e9 + 7;
const int N = 1e5 + 5;

int dp[N];

int Pow(int p, int q) { return p > 1 ? q - 1LL * Pow(q % p, p) * q / p : 1; }

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    int m = 0;
    for (int& x : a) std::cin >> x, m += x;
    dp[1] = (m - 2 + Pow(m, P)) % P;
    for (int i = 2; i < N; i++) dp[i] = (2LL * dp[i - 1] - dp[i - 2] - 1LL * (m - 1) * Pow(m - i + 1, P)) % P;
    int Ans = 0;
    for (int x : a) Ans = (Ans + dp[x]) % P;
    if (Ans < 0) Ans += P;
    std::cout << Ans << '\n';
    return 0;
}